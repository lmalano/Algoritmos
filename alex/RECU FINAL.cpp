#include <iostream>
#define v 25
#define h 80
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;

struct par{
public:
	par() {};	
	int coordX;
	int coordY;	
	void es(int x, int y){
	coordX=x;
	coordY=y;		
	};
};

class conjunto{
public:
	conjunto();
    ~conjunto(){};
    void limites(par, par);
	void crearmatriz(int);
    bool vacio(par);
    void add (char);
	bool esta(par);
	void interseccion(conjunto, conjunto);
	void imprimir ();
	void mover(char);

	
	int desdeX, hastaX, desdeY, hastaY, k;
	int elem[v][h];
	int neX, neY;	

};

conjunto::conjunto(){ neX=neY=k=0;
 	 for(int i=0;i<v;i++){
     	for(int j=0;j<h-1;j++){		 
         elem[i][j] = 0;
		 }
	}

};

void conjunto::limites(par p1, par p2){
	
	desdeX=p1.coordX;
	hastaX=p2.coordX;
	desdeY=p1.coordY;
	hastaY=p2.coordY;
	
};

void conjunto::crearmatriz(int n){
	
	int i, j, t, s;
	t=0;
	s=0;
	k=n;

	neX=(hastaX-desdeX);
	neY=(hastaY-desdeY);
		
    for(i=desdeX;i<hastaX;i++){
     	for(j=desdeY;j<hastaY;j++){		 
         elem[i][j] = k;
		 }	 
	 }	
};


bool conjunto::vacio(par p1){
	bool b=false;
	
	if(elem[p1.coordX][p1.coordY]==0) b=true;
	
	return b;
}

void conjunto::imprimir()
{
	par p1;
	
	for(int i=0;i<v;i++){
		p1.coordX=i;
     	for(int j=0;j<h-1;j++){
		 p1.coordY=j;
		 if(vacio(p1)) 	cout<<" ";	 
		 	 
         else cout<<elem[i][j];
     
		 }
		 cout<<endl;
	}
	cout<<endl;
};

bool conjunto::esta(par a)
{
    bool e;
	e=false;
	
	if (elem[a.coordX][a.coordY]!=0) e=true;
	
	return e;
};

void conjunto::add(char x )
{
	if(x == '+'){
		neX++;
		neY++;
		hastaX++;
		hastaY++;
		
		for(int i=desdeX;i<hastaX;i++){
     	for(int j=desdeY;j<hastaY;j++){		 
         elem[i][j] = k;
		 }	 
	  }		
	}
	
	else if(x == '-'){
		neX--;
		neY--;
		hastaX--;
		hastaY--;
		
		for(int i=desdeX;i<hastaX+1;i++){
     	for(int j=desdeY;j<hastaY+1;j++){
			if (i==(hastaX)||j==(hastaY))	elem[i][j]=0; 
            else elem[i][j] = k;
		 }	 
}			
	}
};

void conjunto::mover(char x){
	
	if (x=='w'){
		desdeX--;
		hastaX--;
		for(int i=desdeX;i<(hastaX)+1;i++){
     	for(int j=desdeY;j<hastaY;j++){	
		 if (i==(hastaX))	elem[i][j]=0; 
         else elem[i][j] = k;
		 }	 		
	}
}
	
	if(x=='s'){
		desdeX++;
		hastaX++;
		for(int i=(desdeX)-1;i<hastaX;i++){
     	for(int j=desdeY;j<hastaY;j++){
		 if(i==(desdeX)-1) elem[i][j]=0;
		 else elem[i][j] = k;
		 }	 	
	}}
	
	if(x=='d'){
		desdeY++;
		hastaY++;
		for(int i=desdeX;i<hastaX;i++){
     	for(int j=((desdeY)-1);j<hastaY;j++){
		 if (j==(desdeY)-1) elem[i][j]=0;		 
         else elem[i][j] = k;
		 }	 	
	}
}	
	if(x=='a'){
		desdeY--;
		hastaY--;
		for(int i=desdeX;i<hastaX;i++){
     	for(int j=desdeY;j<(hastaY)+1;j++){	
		 if(j==(hastaY)) elem[i][j]=0;	 
         else elem[i][j] = k;
		 }	 	
	}
}	
};

void conjunto::interseccion(conjunto c1, conjunto c2)
{
   par comp;
     for(int i=0;i<v;i++)
     {   comp.coordX=i;
     	 for (int j=0;j<h;j++){
     	 comp.coordY=j;
         if (c2.esta(comp))
         {   elem[i][j]=c2.k;
           
         }
         else elem[i][j]=c1.elem[i][j];
     }
     }  
}

conjunto super(conjunto inter, conjunto arreglo[], int n ){
	int pos;
	
	cout<<"Ingrese el numero de la matriz que quiere ver adelante. "<<endl;
	cin>>pos;	

	for (int i=1; i<n+1 ;i++){
		
		if (i!=pos){
			inter.interseccion(inter,arreglo[i]);
		}
	}
		
	inter.interseccion(inter,arreglo[pos]);
	inter.imprimir();
	return inter;
}
	
conjunto crearconjunto(int n, int w, int &entrada, int corde[]){
	
   conjunto aux;
   int a, b;
   
   par p1, p2;

   bool flag=false;

   for (int i=entrada ;i<=(4*n)+1;i++){
	if((i+1)%2!=0){
	a=corde[i];
	}
		
	if((i+1)%2==0){
		b=corde[i];
	
		if(!flag){
		p1.es(a,b);}
		
		if (flag){
		p2.es(a,b);
		cout<<endl;
		aux.limites(p1,p2);
		aux.crearmatriz(w);
		return aux;
		flag=false;		
		}
	flag=true;
	entrada=entrada+4;
	}
	}						
}
	
void instrucciones (){
		cout<<"--------------------------------------------------------------------------------";
		cout<<"| Para agrandar la matriz, presione +. "<<endl;
		cout<<"| Para achicar la matriz, presione -. "<<endl;
		cout<<"| Para desplazar en cualquiera de las cuatro posiciones, presione: "<<endl;
		cout<<"      w si desea mover hacia arriba."<<endl;
		cout<<"      s si desea mover hacia abajo."<<endl;
		cout<<"      d si desea mover hacia la derecha."<<endl;
		cout<<"      a si desea mover hacia la izquierda."<<endl;
		cout<<"| Para traer hacia adelante alguna matriz, presione t. "<<endl;
		cout<<"| Para salir presione e"<<endl;
		cout<<"--------------------------------------------------------------------------------";				
		cout<<"Presione la opcion que desea ejecutar."<<endl;
}	

int main(){
	
	int pos=0;
	int n;
	cout<<"ingrese cuantas ventanas desea crear (hasta 9):"<<endl;
    cin>>n;
    cout<<endl;
	
	conjunto ar[n+1];
	
	conjunto c0;
    par p3;
	p3.es(0,0);
	par p4;
	p4.es(25,79);
	c0.limites(p3,p4);
	c0.crearmatriz(0);
	c0.imprimir();
	ar[0]=c0;
	
	string nombre_archivo="textoparcial.txt";
    int cord,a, b;
    ifstream archivo_entr;
    int j=0;
    
    int entrada=0;
    
    archivo_entr.open(nombre_archivo.c_str());
     
    int corde[n*4];
    
    for (j;j<n*4;j++)
    if(archivo_entr.good()){
 
   		archivo_entr>>cord;
		corde[j]=cord;
		}  	
	j=1;	
	while (j<n+1){
		ar[j]=crearconjunto(n,j,entrada, corde);
		j++;
	}
        
    conjunto inter;
	inter=super(inter, ar, n+1);
	instrucciones();

	
	char i;
    cin>>i;
    conjunto aux;
		
	while(i != 'e'){
		
		switch (i){ 
			case '+': cout<<"suma"<<endl;
			cout<<"seleccione la ventana que desea agrandar:"<<endl;
			cin>>pos;	
			ar[pos].add(i);
			inter=super(aux,ar,n);
			system ("pause");
			instrucciones();
			cin>>i; 
			break;
			case '-': cout<<"resta"<<endl;
			cout<<"seleccione la ventana que desea achicar:"<<endl;
			cin>>pos;	
			ar[pos].add(i);
			inter=super(aux,ar,n);
			system ("pause");
			instrucciones();
			cin>>i; 
			break;
			case 'w':cout<<"sube"<<endl;
			cout<<"seleccione la ventana que desea subir:"<<endl;
			cin>>pos;	
			ar[pos].mover(i);
			inter=super(aux,ar,n);
			system ("pause");
			instrucciones();
			cin>>i;
			break;
			case 'a':cout<<"izquierda"<<endl;
			cout<<"seleccione la ventana que desea mover:"<<endl;
			cin>>pos;	
			ar[pos].mover(i);
			inter=super(aux,ar,n);
			system ("pause");
			instrucciones();
			cin>>i;
			break;
			case 's':cout<<"baja"<<endl;			
			cout<<"seleccione la ventana que desea mover:"<<endl;
			cin>>pos;	
			ar[pos].mover(i);
			inter=super(aux,ar,n);
			system ("pause");
			instrucciones();
			cin>>i; 
			break;
			case 'd':cout<<"derecha"<<endl;
			cout<<"seleccione la ventana que desea mover:"<<endl;
			cin>>pos;	
			ar[pos].mover(i);
			inter=super(aux,ar,n);
			system ("pause");
			instrucciones();
			cin>>i;
			break;
			case 't': {		
			inter=super(inter, ar , n);
			system ("pause");
			instrucciones();
			cin>>i;
			break;}			
			case 'e': {break;}	
			
			default: cout<<"Opcion incorrecta. "<<endl<<endl;
			instrucciones();
			cin>>i;
			break;	
				}
			
			
			
			}		
	
	system("pause");
	return 0;
}
