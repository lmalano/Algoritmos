#include <iostream>
#include <fstream>

using namespace std;
class Nodo{
    private: 
        int peso, origen, destino;
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        Nodo(int a,int b, int c) {origen=a; peso=b; destino=c; next=NULL;};
        void set_peso(int a) {peso=a;};
        void set_origen (int a){origen=a;};
        void set_destino (int a){destino=a;};
        void set_next(Nodo *n) {next=n;};
        int get_destino() {return destino;};
        int get_origen(){return origen;};
        int get_peso() {return peso;};
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista : public Nodo{
    private:
            Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            ~Lista();
            void add(int o, int p, int d);
            bool esvacia();
            int cabeza(void);
            Lista *resto(void);
            Nodo *get_czo() {return czo; };
            void borrar(void); //borra la cabeza
            void impresion(/*Lista**/);
};

Lista::~Lista(){
   while (!this->esvacia()){
         this->borrar();
   }
}

void Lista::add(int o, int p, int d)
{  
     Nodo *nuevo=new Nodo(o, p, d);
     nuevo->set_next(czo);
     czo=nuevo;
}

bool Lista::esvacia()
{   
    return czo->es_vacio();
}

int Lista::cabeza(void)
{ 
  if(esvacia()){
                cout<<" Error, Cabeza de lista vacia";
                return -1; 
  }
  return czo->get_destino();
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo->get_next());
      return (l);
}

void Lista::borrar(void)
{ 
  if(esvacia()){
  } else {
         Nodo *tmp=czo;
         czo=czo->get_next();
         delete tmp;
  }
}

void Lista::impresion(){
     if(!esvacia()) {
                    int a=this->cabeza();
                    cout<<"-"<<a;
                    return resto()->impresion();
     }
}
