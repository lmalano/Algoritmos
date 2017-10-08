#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <sstream>
#include <fstream>
using namespace std;

struct nodoLISTA{
       string palabra;
       int FB, izq, der, repeticion; // FB es la altura del subarbol izq menos la altura del subarbol der
};

struct nodoAVL{
       int FB,pos; // FB es la altura del subarbol izq menos la altura del subarbol der
       nodoAVL *izq, *der;
       nodoLISTA *plista;
};

class Nodo{
    private: 
        nodoLISTA *dato;
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        Nodo(nodoLISTA *a) {dato=a; next=NULL;};
        void set_dato(nodoLISTA *a) {dato=a; };
        void set_next(Nodo *n) {next=n; };
        nodoLISTA *get_dato() {return dato; };
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};
/*------------------------------------------------------------------*/
class Lista{
    private: Nodo *czo;
    	
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            void add(nodoLISTA *d);
            bool esvacia(void); 
            void impre(void);
            };

void Lista::impre(void)
{ Nodo *aux;
int c=0;
  aux=czo;
    while(aux->get_next()!=NULL){
         cout<<aux->get_dato()->palabra<<"   "<<aux->get_dato()->repeticion<<endl;
         aux=aux->get_next();
         c++;
         if (c%50==0)system("PAUSE");
    }
}
void Lista::add(nodoLISTA *d)
{  
     Nodo *nuevo=new Nodo(d);
     nuevo->set_next(czo);
     czo=nuevo;
}
bool Lista::esvacia(void)
{   
    return czo->es_vacio();
}

/*------------------------------------------------------------------*/

typedef nodoAVL * pnodo;
class arbolAVL{
    pnodo raiz;
    void Insert(int x, bool &aumento, nodoAVL* &A);
    void show(pnodo aux, int n);
    void rotarLL(nodoAVL* &A);
    void rotarRR(nodoAVL* &A);
    void rotarLRalter(nodoAVL* &A);
    void rotarRLalter(nodoAVL* &A);
    nodoLISTA *getLi(pnodo aux, int p);
    void setLi(int p, pnodo aux, nodoLISTA *nuevo);
	    
public:
	arbolAVL(){raiz=NULL;};
    ~arbolAVL(){};
    void CreaArbolAVL(int x);
    void VerArbol(){ show(raiz,0); }
    nodoLISTA *getL(int p){return getLi(raiz,p);};
    void setL(int p,nodoLISTA *nuevo){setLi(p, raiz, nuevo);};
};

void arbolAVL::setLi(int p, pnodo aux, nodoLISTA *nuevo){
	if (aux->pos==p) aux->plista=nuevo;
	else if (aux->pos<p) setLi(p,aux->der,nuevo);
	else setLi(p,aux->izq,nuevo);
}

nodoLISTA *arbolAVL::getLi(pnodo aux, int p){
	if (aux->pos==p) return aux->plista;
	else if (aux->pos<p) return getLi(aux->der,p);
	else return getLi(aux->izq,p);	
}

void arbolAVL::CreaArbolAVL(int x)
{    bool aumento;
     aumento=false;
     Insert(x,aumento,raiz);
}

void arbolAVL::Insert(int x, bool &aumento, nodoAVL* &A){
        if (A == NULL){
                A = new nodoAVL;
                A->pos = x;
                A->FB = 0;
                A->izq = NULL;
                A->der = NULL;
                aumento = true;
        }else{
                if (x < A->pos){                       
                        Insert(x, aumento, A->izq);                     
                        if (aumento){
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
                        Insert(x, aumento, A->der);                     
                        if (aumento){
                                switch (A->FB){
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
      //  cout<<"\ L>> "<<A->pos<<endl<<endl;
        nodoAVL* aux = A->izq->der;
        A->izq->der = A;
        A->izq->FB = 0; 
        nodoAVL* aux2 = A->izq;
        A->izq = aux;
        A->FB = 0;
        A = aux2;
}
 
void arbolAVL::rotarRR(nodoAVL* &A){ 
       // cout<<"\ R>> "<<A->pos<<endl<<endl;
        nodoAVL* aux = A->der->izq;
        A->der->izq = A;
        A->der->FB = 0; 
        nodoAVL* aux2 = A->der;
        A->der = aux;
        A->FB = 0;
        A = aux2;
}
 
void arbolAVL::rotarLRalter(nodoAVL* &A){ 
      //  cout<<"\ Rotacion Doble R+L"<<endl;
        rotarRR(A->izq);
        VerArbol();
        rotarLL(A);
        A->izq->FB=1;
}
 
void arbolAVL::rotarRLalter(nodoAVL* &A){ 
      //  cout<<"\ Rotacion Doble L+R"<<endl;
        rotarLL(A->der);
        VerArbol();
        rotarRR(A);
        A->der->FB=-1;
}

void arbolAVL::show(pnodo aux, int n)
{ int i;
   if(aux!=NULL){                      //OjO este es un recorrido dri
       show(aux->der, n+1);
       for(i=1; i<=n; i++) cout<<"        ";
       cout<<"("<<aux->pos<<" "<<aux->FB<<")"<<"\n";
       show(aux->izq, n+1);
   }
}

/*------------------------------------------------------------------*/
class listaAVL{
	int raizL;
	int max;
	void Insert(string s, bool &aumento, int ind,int anterior, int derOizq);
   	void show(int aux, int n);
   	void rotarLL(int ind, int anterior,int derOizq);
   	void rotarRR(int ind, int anterior,int derOizq);
   	void rotarLRalter(int ind, int anterior,int derOizq);
    void rotarRLalter(int ind, int anterior,int derOizq);
    bool esta(string s,int ind);
    int altura(int ind);
    void QS(int pri, int ult);
    
public:
    Lista *lista= new Lista();
    int v[1000];
    arbolAVL arbol= arbolAVL();
    listaAVL(){raizL=-1;max=1;};
    void CreaArbolAVL(string s);
    void VerArbol(){ show(raizL,0); };
    int Altura(){ altura(raizL);	};
    void Quicksort();
    void mostrar();
};

void listaAVL::mostrar(){
	for (int i=1; i<max;i++){
		cout<<arbol.getL(v[i-1])->palabra<<"   "<<arbol.getL(v[i-1])->repeticion<<endl;
        if (i%50==0)system("PAUSE");
	}
}

void listaAVL::Quicksort(){
	for (int i=0; i<max-1;i++)
	v[i]=i+1;
	QS(0, max-2);
	
}

void listaAVL::QS(int primero, int ultimo)
{ int i,j,pivot,aux;
      if(ultimo>primero){
             pivot=ultimo;
             i=primero-1; j=ultimo;      
             for(;;){ 
                     while(arbol.getL(v[++i])->repeticion > arbol.getL(v[pivot])->repeticion);
                     while(arbol.getL(v[--j])->repeticion < arbol.getL(v[pivot])->repeticion);
                     if(i>=j)break;
                     aux=v[i];v[i]=v[j];v[j]=aux;      
             }// fin for
            aux=v[i];v[i]=v[ultimo];v[ultimo]=aux;
            QS(primero,i-1);
            QS(i+1,ultimo);
      } //fin if 
}// fin ordena

void listaAVL::CreaArbolAVL(string s){   
	if (!esta(s,raizL)){ 
	bool aumento;
    aumento=false;
    Insert(s,aumento,raizL,raizL,0);
}}

bool listaAVL::esta(string s, int ind){
	if (ind==-1) return false;
	else if (s==arbol.getL(ind)->palabra){
		arbol.getL(ind)->repeticion ++;
		return true;
	}
	else if(s<arbol.getL(ind)->palabra) return esta(s,arbol.getL(ind)->izq);
	else if(s>arbol.getL(ind)->palabra) return esta(s,arbol.getL(ind)->der);
	else
	 return false;
}

void listaAVL::Insert(string s, bool &aumento, int ind, int anterior, int derOizq){//derOizq si es 1 es izq, 2 der, 0 si el arbol esta vacio 
        if (ind == -1){
        		nodoLISTA *nuevo= new nodoLISTA();
        		nuevo->palabra=s;
                nuevo->FB = 0;
                nuevo->izq = -1;
                nuevo->der = -1;
                nuevo->repeticion=1;
        		arbol.CreaArbolAVL(max);
        		arbol.setL(max,nuevo);
        		lista->add(nuevo);

                switch (derOizq){
                	case 0:{
                		raizL=max;
						break;
					}
					case 1:{
						arbol.getL(anterior)->izq=max;
						break;
					}
					case 2:{
						arbol.getL(anterior)->der=max;
						break;
					}
				}
                max++;
                aumento = true;
        }else{
                if (s < arbol.getL(ind)->palabra){                       
                        Insert(s, aumento, arbol.getL(ind)->izq,ind,1);                     
                        if (aumento){
                                switch (arbol.getL(ind)->FB){
                                        case -1:{
                                                arbol.getL(ind)->FB = 0;
                                                aumento = false;
                                                break;
                                        }
                                        case 0:{
                                                arbol.getL(ind)->FB = 1;
                                                aumento = true;
                                                break;
                                        }
                                        case 1:{  
                                                if (arbol.getL(arbol.getL(ind)->izq)->FB == 1){ //1 necesita LL, si es -1 necesita LR
                                                     rotarLL(ind,anterior,derOizq);
                                                }else{
                                                	arbol.getL(arbol.getL(ind)->izq)->FB=1;
                                                      rotarLRalter(ind,anterior,derOizq);
                                                      
                                                }
                                                aumento = false;
                                                break;
                                        }
                                }//fin switch
                        }//fin aumento==true
                }//fin subarbol izquierdo
                else{
                        Insert(s, aumento, arbol.getL(ind)->der,ind,2);                     
                        if (aumento){
                                switch (arbol.getL(ind)->FB){
                                        case -1:{
                                                if (arbol.getL(arbol.getL(ind)->der)->FB == 1){ //1 necesita RL, si es -1 necesita RR
                                                      arbol.getL(arbol.getL(ind)->der)->FB=-1;
													  rotarRLalter(ind,anterior,derOizq);
                                                }else{
                                                    rotarRR(ind, anterior,derOizq);
                                                }
                                                aumento = false;                                                
                                                break;
                                        }
                                        case 0:{
                                                arbol.getL(ind)->FB = -1;
                                                aumento = true;
                                                break;
                                        }
                                        case 1:{
                                                arbol.getL(ind)->FB = 0;
                                                aumento = false;
                                                break;
                                        }
                                }//fin switch
                        }//fin aumento==true
                }//fin subarbol derecho
        }//fin A!=NULL
}

void listaAVL::rotarLL(int ind,int anterior,int derOizq){ 
        //cout<<"\ LL>> "<<arbol.getL(ind)->palabra<<endl<<endl;
        int aux = arbol.getL(arbol.getL(ind)->izq)->der;
        arbol.getL(arbol.getL(ind)->izq)->der=ind;		
        arbol.getL(arbol.getL(ind)->izq)->FB = 0; 
        int aux2 = arbol.getL(ind)->izq;
        arbol.getL(ind)->izq = aux;
        arbol.getL(ind)->FB = 0;  

        if(anterior==raizL && derOizq==0)
        	raizL=aux2;
    	else if(derOizq==1)
			arbol.getL(anterior)->izq= aux2;
		else 
			arbol.getL(anterior)->der= aux2;
}

void listaAVL::rotarRR(int ind, int anterior,int derOizq){ 
       // cout<<"\ RR>> "<<arbol.getL(ind)->palabra<<endl<<endl;
        int aux = arbol.getL(arbol.getL(ind)->der)->izq;
        arbol.getL(arbol.getL(ind)->der)->izq = ind;
        arbol.getL(arbol.getL(ind)->der)->FB = 0; 
        int aux2 = arbol.getL(ind)->der;
        arbol.getL(ind)->der = aux;
       arbol.getL(ind)->FB = 0;
       
        if(anterior==raizL && derOizq==0 ){
		   	raizL=aux2;}
    	else if(derOizq==1)
			arbol.getL(anterior)->izq= aux2;
		else 
			arbol.getL(anterior)->der= aux2;
}

void listaAVL::rotarLRalter(int ind, int anterior,int derOizq){ 
        //cout<<"\ Rotacion Doble RR+LL"<<endl;
        rotarRR(arbol.getL(ind)->izq,ind,1);
        rotarLL(ind,anterior,derOizq);     
}


void listaAVL::rotarRLalter(int ind, int anterior,int derOizq){ 
        //cout<<"\ Rotacion Doble LL+RR"<<endl;
        rotarLL(arbol.getL(ind)->der,ind,2);
        rotarRR(ind,anterior,derOizq);
}

void listaAVL::show(int aux, int n)
{ int i;
   if(aux!=-1){                      //OjO este es un recorrido dri
       show(arbol.getL(aux)->der, n+1);
       for(i=1; i<=n; i++) cout<<"        ";
       cout<<"("<<arbol.getL(aux)->palabra<<" "<<arbol.getL(aux)->repeticion<<" "<<arbol.getL(aux)->FB<<")"<<"\n";
       show(arbol.getL(aux)->izq, n+1);
   }
}

int listaAVL::altura(int ind){
	if (ind==-1) return 0;
	else{
		//return altura(arbol.getL(ind)->izq)+altura(arbol.getL(ind)->der)+1;  //en vez de altura calcula nodos, comentar el resto del else
		if(altura(arbol.getL(ind)->der)>altura(arbol.getL(ind)->izq))
			return altura(arbol.getL(ind)->der)+1;
		else
			return altura(arbol.getL(ind)->izq)+1;		
	}
}

int main(){
	listaAVL T=listaAVL();
	ifstream in("texto.txt");
  	string s, line;
  	while(getline(in,s,' '))
  	T.CreaArbolAVL(s); 
	T.VerArbol();
	cout<<"-----------------------------------"<<endl<<endl;
	T.Quicksort();
	T.mostrar();
	cout<<"-----------------------------------"<<endl<<endl;
	cout<<"La altura es: "<<T.Altura()<<endl;
   	system("PAUSE");
   	return 0;
}
