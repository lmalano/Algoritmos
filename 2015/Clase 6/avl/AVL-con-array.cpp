#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <sstream>
#include <fstream>
using namespace std;

struct nodoAVL{
       string palabra;
       int FB, izq, der, repeticion; // FB es la altura del subarbol izq menos la altura del subarbol der
};

class Nodo{
    private: 
        nodoAVL *dato;
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        Nodo(nodoAVL *a) {dato=a; next=NULL;};
        void set_dato(nodoAVL *a) {dato=a; };
        void set_next(Nodo *n) {next=n; };
        nodoAVL *get_dato() {return dato; };
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    private: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            void add(nodoAVL *d);
            bool esvacia(void); 
            void impre(void);
            void insertion_sort();
};

void Lista::insertion_sort(){
	 	Nodo *aux, *aux2;
	aux2=czo;	
	while(aux2->get_next()!=NULL){
		aux=czo;
		while (aux!=aux2->get_next()){
			if((aux->get_dato()->repeticion) < (aux2->get_dato()->repeticion)){
			  nodoAVL *temp=aux->get_dato();
			  aux->set_dato(aux2->get_dato());
			  aux2->set_dato(temp);
			}
			aux=aux->get_next();
			}
			aux2=aux2->get_next();
	}
}

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

void Lista::add(nodoAVL *d)
{  
     Nodo *nuevo=new Nodo(d);
     nuevo->set_next(czo);
     czo=nuevo;
}

bool Lista::esvacia(void)
{   
    return czo->es_vacio();
}

/********************************************************************/
class arbolAVL{
	int raiz;
   	void Insert(string s, bool &aumento, int ind,int anterior, int derOizq);
   	void show(int aux, int n);
   	void rotarLL(int ind, int anterior,int derOizq);
   	void rotarRR(int ind, int anterior,int derOizq);
   	void rotarLRalter(int ind, int anterior,int derOizq);
    void rotarRLalter(int ind, int anterior,int derOizq);
    bool esta(string s,int ind);
    int altura(int ind);
    void armarLista(int ind);
    
public:
	int max=0;
	nodoAVL A[1000];
	Lista *l=new Lista();
    arbolAVL(){raiz=-1;};
    ~arbolAVL(){};
    void CreaArbolAVL(string s);
    void VerArbol(){ show(raiz,0); }
    int Altura(){ altura(raiz);	};
    void armLista(){armarLista(raiz);};
};

void arbolAVL::armarLista(int ind){
	if (ind!=-1) {
	l->add(&A[ind]);
	armarLista(A[ind].izq);
	armarLista(A[ind].der);	
	}
}

void arbolAVL::CreaArbolAVL(string s){   
	if (!esta(s,raiz)){ 
	bool aumento;
    aumento=false;
    Insert(s,aumento,raiz,raiz,0);
}}

bool arbolAVL::esta(string s, int ind){
	
	if (ind==-1) return false;
	else if (s==A[ind].palabra){
		A[ind].repeticion ++;
		return true;
	}
	else if(s<A[ind].palabra) return esta(s,A[ind].izq);
	else if(s>A[ind].palabra) return esta(s,A[ind].der);
	else
	 return false;
}

void arbolAVL::Insert(string s, bool &aumento, int ind, int anterior, int derOizq){//derOizq si es 1 es izq, 2 der, 0 si el arbol esta vacio 
        if (ind == -1){
                A[max].palabra=s;
                A[max].FB = 0;
                A[max].izq = -1;
                A[max].der = -1;
                A[max].repeticion=1;
                switch (derOizq){
                	case 0:{
                		raiz=max;
						break;
					}
					case 1:{
						A[anterior].izq=max;
						break;
					}
					case 2:{
						A[anterior].der=max;
						break;
					}
                	
				}
                max++;
                aumento = true;       
        }else{
                if (s < A[ind].palabra){                       
                        Insert(s, aumento, A[ind].izq,ind,1);                     
                        if (aumento){
                                switch (A[ind].FB){
                                        case -1:{
                                                A[ind].FB = 0;
                                                aumento = false;
                                                break;
                                        }
                                        case 0:{
                                                A[ind].FB = 1;
                                                aumento = true;
                                                break;
                                        }
                                        case 1:{
                                                if (A[A[ind].izq].FB == 1){ //1 necesita LL, si es -1 necesita LR
                                                     rotarLL(ind,anterior,derOizq);
                                                }else{
                                                      rotarLRalter(ind,anterior,derOizq);
                                                }
                                                aumento = false;
                                                break;
                                        }
                                }//fin switch
                        }//fin aumento==true
                }//fin subarbol izquierdo
                else{
                        Insert(s, aumento, A[ind].der,ind,2);                     
                        if (aumento){
                                switch (A[ind].FB){
                                        case -1:{
                                                if (A[A[ind].der].FB == 1){ //1 necesita RL, si es -1 necesita RR
                                                      rotarRLalter(ind,anterior,derOizq);
                                                }else{
                                                    rotarRR(ind, anterior,derOizq);
                                                }
                                                aumento = false;                                                
                                                break;
                                        }
                                        case 0:{
                                                A[ind].FB = -1;
                                                aumento = true;
                                                break;
                                        }
                                        case 1:{
                                                A[ind].FB = 0;
                                                aumento = false;
                                                break;
                                        }
                                }//fin switch
                        }//fin aumento==true
                }//fin subarbol derecho
        }//fin A!=NULL
}

void arbolAVL::rotarLL(int ind,int anterior,int derOizq){ 
        int aux = A[A[ind].izq].der;
        A[A[ind].izq].der=ind;		
        A[A[ind].izq].FB = 0; 
        int aux2 = A[ind].izq;
        A[ind].izq = aux;
        A[ind].FB = 0;     
        if(anterior==raiz && derOizq==0)
        	raiz=aux2;
    	else if(derOizq==1)
			A[anterior].izq= aux2;
		else 
			A[anterior].der= aux2;
}

void arbolAVL::rotarRR(int ind, int anterior,int derOizq){ 
        int aux = A[A[ind].der].izq;
        A[A[ind].der].izq = ind;
        A[A[ind].der].FB = 0; 
        int aux2 = A[ind].der;
        A[ind].der = aux;
        A[ind].FB = 0;
        if(anterior==raiz && derOizq==0 )
        	raiz=aux2;
    	else if(derOizq==1)
			A[anterior].izq= aux2;
		else 
			A[anterior].der= aux2;
}

void arbolAVL::rotarLRalter(int ind, int anterior,int derOizq){ 
        rotarRR(A[ind].izq,ind,1);
        rotarLL(ind,anterior,derOizq);
        A[A[ind].izq].FB=1;
}


void arbolAVL::rotarRLalter(int ind, int anterior,int derOizq){ 
        rotarLL(A[ind].der,ind,2);
        rotarRR(ind,anterior,derOizq);
        A[A[ind].der].FB=-1;
}

void arbolAVL::show(int aux, int n)
{ int i;
   if(aux!=-1){                      //OjO este es un recorrido dri
       show(A[aux].der, n+1);
       for(i=1; i<=n; i++) cout<<"        ";
       cout<<"("<<A[aux].palabra<<" "<<A[aux].repeticion<<" "<<A[aux].FB<<")"<<"\n";
       show(A[aux].izq, n+1);
   }
}

int arbolAVL::altura(int ind){
	if (ind==-1) return 0;
	else{
		//return altura(A[ind].izq)+altura(A[ind].der)+1;  //en vez de altura calcula nodos, comentar el resto del else
		if(altura(A[ind].der)>altura(A[ind].izq))
			return altura(A[ind].der)+1;
		else
			return altura(A[ind].izq)+1;		
	}
}

int main(){
	arbolAVL T=arbolAVL();
	ifstream in("texto.txt");
  	string s, line;
  	while(getline(in,s,' '))
   	T.CreaArbolAVL(s);
	
	T.VerArbol();
	cout<<"-----------------------------------"<<endl<<endl;
	T.armLista();
	T.l->insertion_sort();
	T.l->impre();
	cout<<"-----------------------------------"<<endl<<endl;
	cout<<"La altura es: "<<T.Altura()<<endl;
   	system("PAUSE");
   	return 0;
}
