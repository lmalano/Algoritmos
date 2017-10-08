#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

typedef int tarbol;

struct nodo{
      tarbol info;
      nodo *izq,*der;
};
typedef nodo * pnodo;

class arbol{
    pnodo raiz, q;
    void ArbolBusq(tarbol x, pnodo &nuevo);
    void rid(pnodo aux);
    void ird(pnodo aux);
    void idr(pnodo aux);
    void show(pnodo aux, int n);
 	void showhojas(pnodo aux);
 	 int menor(pnodo aux);
 	bool esta (pnodo aux,tarbol x);
 	
public:
    arbol(){raiz=NULL;};
    ~arbol(){};
    void CreaArbolBus(tarbol x);
    void RID(){ rid(raiz); }
    void IRD(){ ird(raiz); }
    void IDR(){ idr(raiz); }
    void VerArbol(){ show(raiz,0); }
    void Mostrarhojas () { showhojas(raiz); }
    tarbol Vermenor ()   { return menor(raiz); }
 	bool veresta(tarbol x)   { return esta(raiz,x); }
};

void arbol::CreaArbolBus(tarbol x)
{ ArbolBusq(x,raiz);
}
void arbol::ArbolBusq(tarbol x, pnodo &nuevo)
{
  if(nuevo==NULL){
      nuevo= new nodo;
      nuevo->info=x; nuevo->der=nuevo->izq=NULL;
  }
  if(x > nuevo->info) ArbolBusq(x, nuevo->der);
  if(x < nuevo->info) ArbolBusq(x, nuevo->izq);
}
void arbol::ird(pnodo aux)
{  if(aux!=NULL){
        ird(aux->izq);
        cout<<"\n"<<aux->info;
        ird(aux->der);
   }
}
void arbol::rid(pnodo aux)
{  if(aux!=NULL){
        cout<<"\n"<<aux->info;
        rid(aux->izq);
        rid(aux->der);
   }
}
void arbol::idr(pnodo aux)
{  if(aux!=NULL){
        idr(aux->izq);
        idr(aux->der);
        cout<<"\n"<<aux->info;
   }
}
void arbol::show(pnodo aux, int n)
{ int i;
   if(aux!=NULL){                      //OjO este es un recorrido dri
       show(aux->der, n+1);
       for(i=1; i<=n; i++) cout<<"     ";
       cout<<aux->info<<"\n";
       show(aux->izq, n+1);
   }
}

void arbol::showhojas(pnodo aux)
{ if(aux!=NULL){
	
  showhojas(aux->izq);
		if(aux->izq==NULL && aux->der==NULL)
				 { cout<<"  ";
				 cout<<aux->info; } 
 					 showhojas(aux->der);}  
} 
  
tarbol arbol::menor(pnodo aux)
{	
	if(aux->izq==NULL) return aux->info;
	return menor(aux->izq);
	}
 
 
bool arbol::esta( pnodo aux,tarbol x)
{
 if(aux==NULL) return false;
 else if (x>aux->info) return esta(aux->der,x);
 else if (x<aux->info) return esta(aux->izq,x);
 return true;
}     
//-------------------------------------------------------
int main (int argc, char *argv[])
{  int i; tarbol izq;
   arbol T;
   int vec[10]={50,12,18,240,222,45,410,325,38,95};
   for(i=0;i<10;i++){ 
                      T.CreaArbolBus(vec[i]);
                      T. VerArbol();
                      cout<<"--------------------------------\n";
                      
   } 
                     

   cout<<"IRD -----------\n";//izq-raiz-der
   T.IRD();
   cout<<"\n--------------------------------";
   cout<<"RID -----------\n"; //raiz-izq-der
   T.RID();
   cout<<"\n--------------------------------";
   cout<<"IDR -----------\n";//izq-der-raiz
   T.IDR();  
	cout<<"\n------- mostrar hojas----";
	T.Mostrarhojas();
	 
	cout<<"\n------- mostrar menor = "<<T.Vermenor();
	
	cout<<"\n------- mostrar menor = "<<T.veresta(12);//devuelve 0 si esta o 1 si no esta
	  
   cout<<endl;
   system("PAUSE");
   return 0;
}
