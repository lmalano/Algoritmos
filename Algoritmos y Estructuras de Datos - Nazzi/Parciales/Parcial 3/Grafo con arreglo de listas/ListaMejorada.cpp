#include <iostream>
#include <sstream>

using namespace std;
class Nodo{
    private: 
        int peso, origen, destino;
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        //Nodo(int d) {origen=a; peso=b; destino=c; next=NULL;};
        void set_peso(int a) {peso=a;};
        void set_origen (int a){origen=a;};
        void set_destino (int a){destino=a;};
        void set_next(Nodo *n) {next=n;};
        int get_peso() {return peso;};
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    private:
            Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            ~Lista(void);
            void add(int d);
            bool esvacia(void);
            int cabeza(void);
            Lista *resto(void);
            Nodo *get_czo() {return czo; };
            void borrar(void); //borra la cabeza
            string toPrint(string p);   
            int suma(int i);
};

void Lista::add(int d)
{  
     Nodo *nuevo=new Nodo();
     nuevo->set_next(czo);
     czo=nuevo;
}
bool Lista::esvacia(void)
{   
    return czo->es_vacio();
}

int Lista::cabeza(void)
{ 
  if(esvacia()){
                cout<<" Error, Cabeza de lista vacia";
                return -1; 
  }
  return czo->get_peso();
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

Lista::~Lista(void){
   while (!esvacia()){
         this->borrar();
   }
}

string Lista::toPrint(string p)
{ 
     if (this->esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm << this->cabeza()<<"-"<< this->resto()->toPrint("") ;
       return stm.str();
     }
}

int Lista::suma(int i)
{ 
     if (this->esvacia()) {
        return i;
     } else {
        return this->resto()->suma(i+this->cabeza());
     }
}
