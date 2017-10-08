#include <iostream>
#include <fstream>
#include "Admin.cpp"
#include "router.cpp"
#include "Maquina.cpp"
#include "pagina.cpp"
using namespace std;

#ifndef salida
#define ofstream salida("resultados.txt", ios::out);
#endif

void leerArchivo(Router* routers[256], Maquina* maquinas[256][256], int matriz[256][256]);
Maquina* getMaquinaAlAzar(Maquina* maquinas[256][256]);
void calcularCaminosMasCortos(Router* routers[], Admin* admin);
void enviarPaginas(Maquina* maquinas[256][256], Router* routers[]);
void operarRouters(Router* routers[], int BW[256][256]);
void recalcularPesos(Router* routers[], Admin* admin);

int main()
{
	Admin* admin;
	Router* routers[256];
	Maquina* maquinas[256][256];
	int AnchosDeBanda[256][256]; //aqui estan los anchos de banda
	leerArchivo(routers, maquinas, AnchosDeBanda); //este metodo lee el archivo de entrada y crea las conexiones.
	admin = new Admin(AnchosDeBanda);
	
	cout << "Para finalizar de operar, presione Ctrl+C.\n"
		 << "Para ver la salida, abra el archivo pantalla.dat y resultados.dat" << endl;
	
	calcularCaminosMasCortos(routers, admin); 
	for(int i = 0; i < 5; i++){
		tablas << "Tabla del Router " << routers[i]->getDir() << endl;
		routers[i]->printTablas();
	}
	int j = 1;
	while(true){
		enviarPaginas(maquinas, routers);
		pantalla << "Ciclo " << j << endl;
		for(int i = 0; i < 3; i++){
			pantalla << "Operación de routers e impresión de colas" << endl;
			operarRouters(routers, AnchosDeBanda);
		}
		recalcularPesos(routers, admin);
		calcularCaminosMasCortos(routers, admin);
		tablas << "Recalculado" << endl;
		for(int i = 0; i < 5; i++){
			tablas << "Tabla del Router " << routers[i]->getDir() << endl;
			routers[i]->printTablas();
		}
		j++;
	}
	
	return 0;
};

/*--------------------------LEER ARCHIVO----------------------------OK*/

void leerArchivo(Router* routers[256], Maquina* maquinas[256][256], int AnchoDeBanda[256][256]){
	ifstream entrada("inputs.dat", ios::in);
	for(int i = 0; i < 256; i++){ //apunta los punteros a NULL e inicializa la matriz de pesos en 0
		routers[i] = NULL;
		for(int j = 0; j < 256; j++){
			maquinas[i][j] = NULL;
			AnchoDeBanda[i][j] = 0;
		}
	}
	int tipoDeConexion; //si es 1, es una conexion router a router
						//si es 2, es una conexion router a maquina
	int vertice1, vertice2;
	double anchoDeBanda;
	while(entrada >> tipoDeConexion){
		if(tipoDeConexion == 1){ //conexion router a router
			entrada >> vertice1 >> vertice2 >> anchoDeBanda;
			if(AnchoDeBanda[vertice1][vertice2] != 0){
				cout << "La conexion de los routers " << vertice1 << " y " << vertice2 << " ya fue asignada" << endl;
				exit(1);
			}
			if(routers[vertice1] == NULL)
				routers[vertice1]= new Router(vertice1);
			if(routers[vertice2] == NULL)
				routers[vertice2]= new Router(vertice2);
			routers[vertice1]->conectarRouter(vertice2);
			routers[vertice2]->conectarRouter(vertice1);
			AnchoDeBanda[vertice1][vertice2] = (int)anchoDeBanda;
			AnchoDeBanda[vertice2][vertice1] = (int)anchoDeBanda;
		}
		else if(tipoDeConexion == 2){ //conexion router a maquina
			entrada >> vertice1 >> vertice2;
			if(maquinas[vertice1][vertice2] == NULL)
				maquinas[vertice1][vertice2] = new Maquina(vertice1, vertice2);
			else{
				cout << "La misma ip ya esta asignada" << endl;
				exit(1);
			}
			if(routers[vertice1] == NULL)
				routers[vertice1] = new Router(vertice1);
			routers[vertice1]->conectarPC(vertice2);
		}
		else{
			cout << "La entrada es incorrecta" << endl;
			exit(1);
		}
	}
}

/*----------------------GET MAQUINA AL AZAR-------------------------OK*/

Maquina* getMaquinaAlAzar(Maquina* maquinas[256][256]){
	int i,j;
	bool flag=true;
	while(flag){
		i=(rand() % (256));
		j=(rand() % (256));
			if(maquinas[i][j]!= NULL){
				flag=false;
			}
	}
	return maquinas[i][j];
}

/*--------------------CALCULAR CAMINOS MAS CORTOS-------------------OK*/

void calcularCaminosMasCortos(Router* routers[256], Admin* admin){
	
	for(int i = 0; i < 256; i++)
		if(routers[i] != NULL)
			admin->encontrarCMC(routers[i]->getDir(), routers[i]->getTabla());
	cout << endl;
}

/*-------------------------ENVIAR PAGINAS---------------------------OK*/

void enviarPaginas(Maquina* maquinas[256][256], Router* routers[]){
	//Cada 30 ciclos envia aleatoriamente 50 paginas de cualquier origen a cualquier destino. Esto hay que modificarlo por 50 paginas al azar
	for(int i = 0; i < 5; i++){
		Maquina* maq = getMaquinaAlAzar(maquinas); //se toma una maquina al azar
		Pagina pageToSend = maq->mandarPagina();   //la misma genera una pagina al azar
		while(maquinas[pageToSend.getRoutDestino()][pageToSend.getMaqDestino()] == NULL || 
			 (pageToSend.getRoutDestino() == pageToSend.getRoutOrigen() &&
			 pageToSend.getMaqDestino() == pageToSend.getMaqOrigen())){
			 pageToSend = maq->mandarPagina();
		} //se verifica que el destino de la pagina exista y que no sea el mismo que el origen,
		  //sino, se crea otra pagina al azar hasta que exista
		  //Se imprime en archivo los datos de la pagina a mandar, y se la envia al router correspondiente.
		  
		salida << "Se envió la página: " << pageToSend.getNombre()
			   << " - Orígen: " << pageToSend.getRoutOrigen() << '.' << pageToSend.getMaqOrigen()
			   << " - Destino: " << pageToSend.getRoutDestino() << '.' << pageToSend.getMaqDestino()
			   << " - Info: " << pageToSend.getInformacion()
			   << " - Tamaño: " << pageToSend.getTamanio() << endl;
		routers[maq->getIP().router]->RecibirPagina(pageToSend);
	}
	for(int i = 0; i < 256; i++)
		if(routers[i] != NULL)
			routers[i]->repartirPaquetes();
}

/*--------------------------OPERAR ROUTERS--------------------------OK*/

void operarRouters(Router* routers[], int BW[256][256]){
	Cola<Paquete>* colaAEnviar;
	ListaColas* listaRestante;
	//Envio de los paquetes a los siguientes routers.
	for(int i = 0; i < 256; i++){
		colaAEnviar = NULL;
		if(routers[i] != NULL){
			pantalla << "Router " << i << endl;
			routers[i]->getColasRouters()->toPrint();
			listaRestante = routers[i]->getColasRouters();
			if(listaRestante->getComienzo() != NULL)
				colaAEnviar = listaRestante->cabecera();
			while(colaAEnviar != NULL){
				for(int j = 0; j < BW[i][colaAEnviar->getNombreCola()]; j++){
					if(!colaAEnviar->esVacia()){
						routers[colaAEnviar->getNombreCola()]->recibirPaquetes(colaAEnviar->desencolar());
					}
				}
				listaRestante = listaRestante->resto();
				if(listaRestante->getComienzo() != NULL)
					colaAEnviar = listaRestante->cabecera();
				else
					colaAEnviar = NULL;
			}
		}
	} //hasta aca se mandan todos los paquetes que corresponden a los routers siguientes.
	
	//Reparto de los paquetes que llegaron a un router.
	for(int i = 0; i < 256; i++)
		if(routers[i] != NULL){
			routers[i]->repartirPaquetes();
		}
				
	//Entrega de las paginas completas a las maquinas.
	for(int i = 0; i <256; i++)
		if(routers[i] != NULL)
			routers[i]->entregarPaginasCompletas();
}

/*-------------------------RECALCULAR PESOS---------------------------*/

void recalcularPesos(Router* routers[256], Admin* admin){
	ListaColas* colasRestantes;
	for(int i = 0; i < 256; i++){ //para cada router
		if(routers[i] != NULL){
			colasRestantes = routers[i]->getColasRouters();
			while(colasRestantes != NULL){ //mientras la lista de colas sea distinta de null
				admin->setPeso(i, colasRestantes->cabecera()->getNombreCola(), (1 + colasRestantes->cabecera()->getTamanio(colasRestantes->cabecera()->getLista(), 0)));
				if(!colasRestantes->resto()->esVacia())
					colasRestantes = colasRestantes->resto();
				else
					colasRestantes = NULL;
			}
		}
	} //Luego de esto el server deberia conocer el estado de cada router y ya puede calcular los caminos mas cortos.
}
