#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

typedef string tarbol;
struct nodo{
      tarbol info;
      int valor;
      nodo *der,*izq;
};
typedef nodo * pnodo;
class arbol{
	int Alt;
    pnodo raiz;
    void ArbolBusq(tarbol x, pnodo &nuevo);
    void rid(pnodo aux);
    void ird(pnodo aux);
    void idr(pnodo aux);
    void show(pnodo aux, int n);
    void altura(pnodo aux, int n);
    void borrar(pnodo &p, tarbol x);
    void bor(pnodo &d);

 
public:	
    arbol(){raiz=NULL;};
    ~arbol(){};
    void CreaArbolBus(tarbol x);
    void RID(){ rid(raiz); }
    void IRD(){ ird(raiz); }
    void IDR(){ idr(raiz); }
    void VerArbol(){ show(raiz,0); }
    void ALTURA(){ altura(raiz,0); }
    void Borrar(tarbol x){ borrar(raiz,x);}
    void leerDesdeArchivo();
    int get_Alt(){return Alt;};
   	void set_Alt(int n) {Alt=n;};
};

//void arbol::borrar(pnodo &p, tarbol x)
//{ if(p==NULL) cout<<"\n El dato NO esta\n\n";
//  else if(x>p->info) borrar(p->der,x);
//  else if(x<p->info) borrar(p->izq,x);
//  else {// lo encontre en el nodo p
//        q=p;
//        if (q->der==NULL) p=q->izq;
//        else if (q->izq==NULL) p=q->der;
//        else bor(q->izq);//busca en el sub arbol izq
//        delete q;
//  }
//}
//void arbol::bor(pnodo &d)
//{ if(d->der!=NULL) bor(d->der);//busca el elemento mas a la derecha
//  else{ q->info = d->info;
//        q=d;
//        d=d->izq;
//  }
//}
//


void arbol::leerDesdeArchivo()
{   
	ifstream fin("texto.txt");
	    
		while (fin.good()){
			string palabra;
			fin >> palabra;
		
			
				this->CreaArbolBus(palabra);
	
		}
		
	fin.close();
}




void arbol::altura(pnodo aux, int n)
{ 
   if(aux!=NULL){                      
       altura(aux->der, n+1); 
       altura(aux->izq, n+1);
   }
   
   if (n>this->get_Alt()){
   		this->set_Alt(n);
   }
}





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
  
  if(x == nuevo->info ){
  	nuevo->valor++; 
	cout << "valor: " <<  nuevo->valor << "palabra: " << x  << endl;
  } 
  
  cout << endl;
  
}
void arbol::ird(pnodo aux)
{  if(aux!=NULL){
        ird(aux->izq);
        cout<<"\n"<<aux->info;
        ird(aux->der);
   }
}
//void arbol::rid(pnodo aux)
//{  if(aux!=NULL){
//        cout<<"\n"<<aux->info;
//        rid(aux->izq);
//        rid(aux->der);
//   }
//}
//void arbol::idr(pnodo aux)
//{  if(aux!=NULL){
//        idr(aux->izq);
//        idr(aux->der);
//        cout<<"\n"<<aux->info;
//   }
//}





void arbol::show(pnodo aux, int n)
{ int i;
  

   if(aux!=NULL){                      //OjO este es un recorrido dri
       show(aux->der, n+1);
       for(i=1; i<=n; i++) cout<<"     ";
       cout<<aux->info<<"\n";
       show(aux->izq, n+1);
       
       
   
   
   }
   
      
}
























//-------------------------------------------------------
int main (int argc, char *argv[])
{  int i; tarbol x;
   arbol T;
   
   
   T.leerDesdeArchivo();
   
   
   
   
   
   
  // string vec[10]={"casa","auto","perro","mesa","auto","auto","casa","compu","taza","led"};
   //for(i=0;i<10;i++){ 
  //                    T.CreaArbolBus(vec[i]);
                      //T.VerArbol();
                      //system("PAUSE");
 //  } 
              
   T.ALTURA();       
   T.VerArbol();
   T.IRD();
   cout<<"\n--------------------------------";
  // T.RID();
   cout<<"altura: " << T.get_Alt();
  // T.IDR();  
  
   
/*
   for(i=1;i<5;i++){
     cout<<"\n -------------------------------- Ing dato a borrar= "; cin>>x;
     T.Borrar(x);
     T.VerArbol();
   }
  */
   cout<<endl;
   system("PAUSE");
   return 0;
}
