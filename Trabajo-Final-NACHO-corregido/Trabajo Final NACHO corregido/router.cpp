#include <iostream>
#include <fstream>
#include "Estructuras/ListaColas.cpp"
#include "Estructuras/Set.cpp"
#include "pagina.cpp"
#include "Estructuras/Cola.cpp"
#include "Estructuras/Paquete.cpp"
#ifndef ROUTER_H
#define ROUTER_H
using namespace std;
ofstream salida("resultados.dat", ios::out);
ofstream tablas("tablas.dat");

class Router{
	private:
		int direccion;
		int maquinas[256];
		int routers[256];
		Set<int>* paginasAMaquina;
		Set<int>* paginasARouters;
		int precedencias[256];
		ListaColas* colasDeRouters;
		ListaColas* PagesToMaq;   //Paginas que van a Maquinas en el router
		ListaColas* PagesToRout;  //Paginas que van a otros routers, y cuyos paquetes tienen que ser distribuidos en las colas de routers.
		
	public:
		Router(int dir);
		bool contienePC(int dir){return maquinas[dir] == 1;};
		int getDir(){return direccion;};
		void conectarPC(int maq){maquinas[maq] = 1;};
		void conectarRouter(int rout);
		int* getMaquinas(){return maquinas;};
		int* getRouters(){return routers;};
		int getPrecedencia(int destino){return precedencias[destino];};
		int* getTabla(){return precedencias;};
		ListaColas* getColasRouters(){return colasDeRouters;};
		ListaColas* getPagesToMaq(){return PagesToMaq;};
		ListaColas* getPagesToRout(){return PagesToRout;};
		int nextRouter(int dest);
		void setDir(int dir){direccion = dir;};
		int recibirPaquetes(Paquete p);
		Paquete enviarPaquetes(int destino){return colasDeRouters->desencolarDe(destino);};
		void RecibirPagina(Pagina page);
		Pagina ArmarPagina(Cola<Paquete>* paquetes);
		void repartirPaquetes();
		void entregarPaginasCompletas();
		void printTablas(){
			for(int i = 0; i <5; i++)
				tablas << "Al router " << i << "  " << precedencias[i] << endl;
		}
};

//EL CONSTRUCTOR NO INICIALIZA PORQUE NO ME COMPILABA

/*----------------------------CONSTRUCTOR---------------------------OK*/

Router::Router(int dir){
	direccion = dir;
	//maquinas = {0};
	//precedencias = {0};
	colasDeRouters = new ListaColas();
	PagesToMaq = new ListaColas();
	PagesToRout = new ListaColas();
	paginasAMaquina = new Set<int>();
	paginasARouters = new Set<int>();
}

/*---------------------------CONECTAR ROUTER------------------------OK*/

void Router::conectarRouter(int rout){
	routers[rout] = 1;
	Cola<Paquete>* c = new Cola<Paquete>();
	c->setNombreCola(rout);
	colasDeRouters->add(c);
}

/*-----------------------------NEXT ROUTER--------------------------OK*/

int Router::nextRouter(int dest){
	int next = dest;
	while(precedencias[next] != direccion)
		next = precedencias[next];
	return next;
}

/*--------------------------RECIBIR PAQUETES--------------------------*/
		
int Router::recibirPaquetes(Paquete p){
	
	if(p.getRoutDestino() == direccion){
		if(paginasAMaquina->pertenece(p.getID())) //en los paquetes que van a las maquinas, el nombre de la cola es el nombre
												 //de la pagina de la cual forman parte.
			PagesToMaq->encolarEn(p.getID(), p);
		else{
			paginasAMaquina->agregar(p.getID());
			Cola<Paquete>* c = new Cola<Paquete>();
			c->setNombreCola(p.getID());
			PagesToMaq->add(c);
			PagesToMaq->encolarEn(p.getID(), p);
		}
	}
	else if(paginasARouters->pertenece(p.getID())){ //Si la direccion de destino no es la misma del router en que esta y ya existe la cola de esta pagina.
		PagesToRout->encolarEn(p.getID(), p); //Pone el paquete en una cola con el nombre de la pagina de la que forma parte
											  //Si llegan muchos paquetes de la misma pagina, se ponen en la misma cola, para distribuirse bien.
	}
	
	else{ //Si es el primer paquete de la pagina que llega.
		paginasARouters->agregar(p.getID());
		Cola<Paquete>* c = new Cola<Paquete>();
		c->setNombreCola(p.getID());
		PagesToRout->add(c);
		PagesToRout->encolarEn(p.getID(), p);
	}
	
	return 0;
}

/*--------------------------RECIBIR PAGINA--------------------------OK*/

void Router::RecibirPagina(Pagina page){
	Cola<Paquete>* paquetes = new Cola<Paquete>();
	string palabra = page.getInformacion(); //obtengo el string de informacion de la pagina
	int cantidad = palabra.length();		//obtengo el tamaño de la pagina
	Paquete paux;
	int i;
	
	paux.setOrigen(page.getMaqOrigen(), page.getRoutOrigen()); //Estos metodos setean la informacion del paquete
	paux.setDestino(page.getMaqDestino(), page.getRoutDestino());
    paux.setID(page.getNombre());
	paux.setPageSize(page.getTamanio());
	for(i = 0; i < cantidad; i++){
		paux.setOrden(i);
		paux.setInfo(palabra.at(i));//paso informacion al paquete
		paquetes->encolar(paux);//Encola el paquete
	}
	paquetes->setNombreCola(paux.getID());
	if(paux.getRoutDestino() == direccion)
		PagesToMaq->add(paquetes);
	else
		PagesToRout->add(paquetes);
	return;
}

/*----------------------------ARMAR PAGINA--------------------------OK*/

Pagina Router::ArmarPagina(Cola<Paquete>* paquetes){
	string pagina;
	Paquete paux;
	paquetes->toPrint();
	int cantidad = paquetes->getTamanio(paquetes->getLista(), 0);
	Pagina retorno(cantidad); //Crea la pagina que va a entregar, del mismo tamanio que la de origen
	char infoDePagina[cantidad];
	for(int i = 0; i < cantidad; i++){
		paux=paquetes->desencolar();
		infoDePagina[paux.getOrden()]=paux.getInfo();
	}
	for(int i = 0; i < cantidad; i++)
		pagina = pagina + infoDePagina[i];	
	retorno.setInformacion(pagina);
	retorno.setNombre(paux.getID());
	retorno.setMaqOrigen(paux.getMaqOrigen());
	retorno.setRoutOrigen(paux.getRoutOrigen());
	retorno.setMaqDestino(paux.getMaqDestino());
	retorno.setRoutDestino(paux.getRoutDestino());
	salida << "Se entregó la página: " << retorno.getNombre()
		   << " - Orígen: " << retorno.getRoutOrigen() << '.' << retorno.getMaqOrigen()
		   << " - Destino: " << retorno.getRoutDestino() << '.' << retorno.getMaqDestino()
		   << " - Info: " << retorno.getInformacion()
		   << " - Tamaño: " << retorno.getTamanio() << endl;
	return retorno;
}

/*-------------------------REPARTIR PAQUETES------------------------OK*/

void Router::repartirPaquetes(){
	bool seEncolo;
	ListaColas* aux;
	do{
		seEncolo = false;
		aux = PagesToRout;
		while(aux->getComienzo() != NULL){ //saca un paquete de cada cola y lo pone en la cola del router correspondiente.
			if(!aux->cabecera()->esVacia()){ //si la cola no esta vacia
				Paquete paux = aux->cabecera()->desencolar();
				colasDeRouters->encolarEn(nextRouter(paux.getRoutDestino()), paux);
				seEncolo = true; //esto indica que algun paquete se encolo
			}
			aux = aux->resto();
		}
	}
	while(seEncolo);
	delete PagesToRout; //Una vez que todos los paquetes fueron repartidos, se vuelve al estado inicial esta lista de colas.
	delete paginasARouters;
	PagesToRout = new ListaColas();
	paginasARouters = new Set<int>();
}

/*--------------------ENTREGAR PAGINAS COMPLETAS--------------------OK*/

void Router::entregarPaginasCompletas(){
	ListaColas* aux;
	aux = PagesToMaq;
	while(!aux->esVacia()){
		if(aux->cabecera()->getTope().getPageSize() == aux->cabecera()->getTamanio(aux->cabecera()->getLista(), 0)){ //esta completa
			pantalla << "Se entrega la siguiente página del router " << aux->cabecera()->getTope().getRoutDestino() 
					 << " a la máquina " << aux->cabecera()->getTope().getMaqDestino() << endl;
			ArmarPagina(aux->cabecera());
			int colaAEliminar = aux->cabecera()->getNombreCola();
			aux = aux->resto();
			PagesToMaq->eliminarCola(colaAEliminar);
		}
		else
			aux = aux->resto();
	}
	//pantalla << "Termina de entregar" << endl;
}
	
#endif
