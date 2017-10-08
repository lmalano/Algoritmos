#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Nodoralo{
    private: 
        int dato;
        Nodoralo *der;
        Nodoralo *inf;
    public:
        Nodoralo() {der=NULL; inf=NULL;};
        Nodoralo(int a) {dato=a;};
        void set_dato(int a) {dato=a; };
        void set_der(Nodoralo *n) {der=n; };
        void set_inf(Nodoralo *n) {inf=n; };
		int get_dato() {return dato; };
        Nodoralo *get_der() {return der; };
        Nodoralo *get_inf() {return inf; };
        //bool es_vacio() {return der==NULL&& inf==NULL}
};

class Nodo{
    private: 
        Nodo *next;
        Nodoralo *nodo;
    public:
        Nodo() {next=NULL; nodo=NULL;};
        Nodo(Nodoralo *a) {nodo=a;};
        void set_nodo(Nodoralo *a) {nodo=a; };
        void set_next(Nodo *n) {next=n; };
        Nodoralo *get_nodo() {return nodo; };
        Nodo *get_next() {return next; };
        //bool es_vacio() {return next==NULL;}
};

class Lista{
    private: 
			Nodo *czo;
			int cant;   
    public:
            Lista(int num) {cant=num; czo=new Nodo();};

            
            //~Lista(void);
            void add();
        
            
};


class Matriz_rala{
	
	private: 
			int rango;
			Lista acces_fila;
			Lista acces_colum;
	public:
			Matriz_rala (int num) {rango=num; acces_fila=new Lista(num);acces_colum=new Lista(num);};
			void add_Nodoralo(int v, int i, int j);
			
};

void Matriz_rala::add_Nodoralo(int v, int i, int j)
{
	Nodo = new nodo (v);
	acces_fila ();
}

void Lista::add()
{  for (i = 0; i< cant; i++)
  {
     Nodo *nuevo=new Nodo(NULL);
     nuevo->set_next(czo);
     czo=nuevo;
}



int main()
{
	return 0;
}
