#include <cstdlib>
#include <iostream>
#include <sstream>
//#define MAX=50

using namespace std;
class Nodo{
    private: 
        int dato;
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        Nodo(int a) {dato=a; next=NULL;};
        void set_dato(int a) {dato=a; };
        void set_next(Nodo *n) {next=n; };
        int get_dato() {return dato; };
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    private: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            //~Lista(void);
            void add(int d);
            bool esvacia(void);
            int cabeza(void);
            Lista *resto(void);
            string toPrint(string p);   
            int suma(int i);
            void impre(void);
            int suma2(void);
            int size();
            void borrar(void); //borra la cabeza
            void borrar_last();//borra el ultimo
            int last(void);
            void concat(Lista *l1);
            Lista *copy(void);
            void tomar(int n);
};

class Cola{
private: 
	int pi, pf;
	int Q[100];
public:
	
	Cola(void){pi=0;pf=0;};
	//~Cola(void);
	int tope();
	bool colavacia();
	void encolar(int a);
	void desencolar();
	int ultimo();
	//string imprimir(string s);
};

int Cola::tope(){
	if(!this->colavacia())
		return Q[pf];
};

bool Cola::colavacia(){
	return (pi==pf);
};

void Cola::encolar(int a){
		Q[pf]=a;
		pf++;
		}
	
void Cola::desencolar(){
	if(!this->colavacia())
	    --pf;
	
}


int Cola::ultimo(){
	if(!this->colavacia())
	return Q[pi];
}



int main()
{

    
    Cola *c = new Cola();
    cout<< c->colavacia()<<endl;
    c->encolar(11);
    c->encolar(22);
    c->encolar(33);
    c->encolar(40);
   
    //cout<< c->toPrint(" soy cola") <<endl;
    cout<< c->colavacia()<<endl;
	cout<< c->tope()<<endl;
	c->desencolar();
	cout<< c->tope()<<endl;
	//cout<< c->toPrint(" soy cola") <<endl;
	cout<< c->ultimo()<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
    
}

