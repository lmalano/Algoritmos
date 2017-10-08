#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

typedef int tarbol;



struct nodoAVL{ //
       tarbol dato;
       int FB;                   // FB es la altura del subarbol izq menos la altura del subarbol der
       nodoAVL *izq, *der;
};
typedef nodoAVL * pnodo;
class arbolAVL{//stbol
    pnodo raiz;  //ocultamos la raiz
    void Insert(int x, bool &aumento, nodoAVL* &A);//inserta
    void show(pnodo aux, int n);//muestra
    void rotarLL(nodoAVL* &A); //rotacionees
    void rotarRR(nodoAVL* &A);
    void rotarLRalter(nodoAVL* &A);
    void rotarRLalter(nodoAVL* &A);
    
public:
    arbolAVL(){raiz=NULL;};//constructor poner raiz en null
    ~arbolAVL(){};
    void CreaArbolAVL(tarbol x);//crea arbol
    void VerArbol(){ cout<<endl;show(raiz,0); }//ver arbol
};

void arbolAVL::CreaArbolAVL(tarbol x)
{    bool aumento;//para saber si inserta un valor 
     aumento=false;
     Insert(x,aumento,raiz);//metodo privado con acceso a la raiz y pasa la variable aumento//mete el valor de arreglo 
}

void arbolAVL::Insert(int x, bool &aumento, nodoAVL* &A){//cuando crea el  50
        if (A == NULL){//para el 1er valor 
                A = new nodoAVL;//si esta en null crea un nuevo nodo y //new crea una direccion y se la pasa a A
                A->dato = x;//y en el nodo se pone el 1er valor del arreglo
                A->FB = 0;
                A->izq = NULL;
                A->der = NULL;
                aumento = true;   
                
        }else{//ya cuando el arbol no es nulo
                if (x < A->dato){     //si el nuevo valor del arreglo es menor  al anterior                 
                        Insert(x, aumento, A->izq); //x=valor de un num de arreglo                    
                        if (aumento){//si aumento es true se cumple y pregunta
                                switch (A->FB){
                                        case -1:{
                                                A->FB = 0;
                                                aumento = false;
                                                break;
                                        }
                                        case 0:{
                                                A->FB = 1;
                                            aumento = true;
                                                break;
                                        }
                                        case 1:{
                                                if (A->izq->FB == 1){ //1 necesita LL, si es -1 necesita LR
                                                        rotarLL(A);
                                                }else{
                                                        rotarLRalter(A);
                                                }
                                                aumento = false;
                                                break;
                                        }
                                }//fin switch
                        }//fin aumento==true
                }//fin subarbol izquierdo
                else{
                        Insert(x, aumento, A->der); //  vuelve la recursion                  
                        if (aumento){//si aumento= true, hace el switch
                                switch (A->FB){//pregunta el estado de FB
                                        case -1:{
                                                if (A->der->FB == 1){ //1 necesita RL, si es -1 necesita RR
                                                        rotarRLalter(A);
                                                }else{
                                                        rotarRR(A);
                                                }
                                                aumento = false;                                                
                                                break;
                                        }
                                        case 0:{
                                                A->FB = -1;
                                                aumento = true;
                                                break;
                                        }
                                        case 1:{
                                                A->FB = 0;
                                                aumento = false;
                                                break;
                                        }
                                }//fin switch
                        }//fin aumento==true
                }//fin subarbol derecho
        }//fin A!=NULL
}

void arbolAVL::rotarLL(nodoAVL* &A){ 
        cout<<"\ LL>> "<<A->dato<<endl<<endl;
        nodoAVL* aux = A->izq->der;
        A->izq->der = A;
        A->izq->FB = 0; 
        nodoAVL* aux2 = A->izq;
        A->izq = aux;
        A->FB = 0;
        A = aux2;
}
 
void arbolAVL::rotarRR(nodoAVL* &A){ 
        cout<<"\ RR>> "<<A->dato<<endl<<endl;
        nodoAVL* aux = A->der->izq;
        A->der->izq = A;// A der, izq q apunte a A
        A->der->FB = 0; // A der fb en 0
        nodoAVL* aux2 = A->der; //un aux2 en A der
        A->der = aux; // a A der ponele el valor de aux 
        A->FB = 0; // a FB es 0
        A = aux2;
}
 
void arbolAVL::rotarLRalter(nodoAVL* &A){ 
        cout<<"\ Rotacion Doble RR+LL"<<endl;
        rotarRR(A->izq);
        VerArbol();
        rotarLL(A);
}
 
void arbolAVL::rotarRLalter(nodoAVL* &A){ 
        cout<<"\ Rotacion Doble LL+RR"<<endl;
        rotarLL(A->der);
        VerArbol();
        rotarRR(A);
}

void arbolAVL::show(pnodo aux, int n)
{ int i;
   if(aux!=NULL){                      //OjO este es un recorrido dri
       show(aux->der, n+1);
       for(i=1; i<=n; i++) cout<<"        ";
       cout<<"("<<aux->dato<<" "<<aux->FB<<")"<<"\n";
       show(aux->izq, n+1);
   }
}
//-------------------------------------------------------
int main (int argc, char *argv[])
{  int i; tarbol x;
   arbolAVL T;
   int vec[15]={50,120,180,240,270,360,410,425,445,495,510,260,530,540,550};//datos de forma creciente para ver como se reacomoda y se rota el arbol
   for(i=0;i<15;i++){ 
   					  cout<<"Nuevo Dato : "<<vec[i]<<endl;
                      T.CreaArbolAVL(vec[i]);
                      T.VerArbol();
                      cout<<endl;system("PAUSE");
                      cout<<"-------------------------------------------------------------------------------"<<endl;
   } 
                     
   T.VerArbol();
  
   cout<<endl;
   
   return 0;
}
