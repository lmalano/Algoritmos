#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

typedef string tarbol;

struct nodo{
      tarbol inf;
      int valor;
      nodo *der,*izq;
};  typedef nodo * pnodo;

nodo arreglonodo[1000];

class abb{
	
	int Alt;
    pnodo raiz;
    void arbolbusqueda(tarbol x, pnodo &nuevo);
    void ordena(pnodo aux);
    void mostrar(pnodo aux, int n);
    void altura(pnodo aux, int n);   
public:	
    abb() {raiz=NULL;};
    void newarbolbusq(tarbol x) { arbolbusqueda(x,raiz);}
    void ord(){ ordena(raiz); }
    void verarb(){ mostrar(raiz,0); }
    void alt(){ altura(raiz,0); }
    void leerarch();
    int get_Alt(){return Alt;};
   	void set_Alt(int n) {Alt=n;};
};

void abb::leerarch()
{   
	ifstream fin("entrada.txt");
	    
		while (fin.good()){
			string input;
			fin >> input;
					
				this->newarbolbusq(input);
		}		
	fin.close();
}

void abb::altura(pnodo aux, int n)
{ 
   if(aux!=NULL)
   {                      
       altura(aux->der, n+1); 
       altura(aux->izq, n+1);
   }
   
   if (n>this->get_Alt())
   {
   	this->set_Alt(n);
   }
   
}

void abb::arbolbusqueda(tarbol x, pnodo &nuevo)
{
	int i;
  if(nuevo==NULL){
      nuevo= new nodo;
      
      nuevo->inf=x; nuevo->der=nuevo->izq=NULL;
       
  }
  if(x > nuevo->inf) 
  {    arbolbusqueda(x, nuevo->der); 
  	    }
  
  if(x < nuevo->inf)  
  {  arbolbusqueda(x, nuevo->izq);
  				        }
  if(x == nuevo->inf ){
  	nuevo->valor++; 
	cout << "cant de veces que se repitio actualmente: " <<  nuevo->valor << " palabra: " << x  << endl;
  } 
  
}

void abb::ordena(pnodo aux)
{  if(aux!=NULL){
        ordena(aux->izq);
        cout<<"\n"<<aux->inf;
        ordena(aux->der);
          }
}

void abb::mostrar(pnodo aux, int n)
{
   if(aux!=NULL){                  
       mostrar(aux->der, n+1);
       for(int i=1; i<=n; i++) cout<<"   ";
       cout<<aux->inf<<"\n";
       mostrar(aux->izq, n+1); }      
}

int main ()
{  
   abb T;  
   
  T.leerarch();
  T.alt();       
  T.verarb();  //muestra arbol
  T.ord(); 	  //muestra palabras una debajo de la otra

   cout<<"\n\naltura del arbol ordenado: " << T.get_Alt();

   cout<<endl;
   system("PAUSE");
   return 0;
}
