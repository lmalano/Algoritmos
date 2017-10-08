#include <iostream>
#include <sstream>

/* 
   Las clases que se definen aqui, forman parte de las listas que 
   contienen los elementos adyacentes a cada vertice.
*/

using namespace std;

class Nodo_Elementos{
    private: 
        int peso, destino;
        Nodo_Elementos *next;
    public:
        Nodo_Elementos() {next=NULL;};
        Nodo_Elementos(int b, int c) {peso=b; destino=c; next=NULL;};
        void set_peso(int a) {peso=a;};
        void set_destino (int a){destino=a;};
        void set_next(Nodo_Elementos *n) {next=n;};
        int get_peso() {return peso;};
        int get_destino(){return destino;};
        Nodo_Elementos *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista_Elementos{
    private:
            Nodo_Elementos *czo;
    public:
            Lista_Elementos() {czo=new Nodo_Elementos();};
            Lista_Elementos(Nodo_Elementos *n) {czo=n;};
            ~Lista_Elementos(void);
            void add(int p, int d);
            bool esvacia(void);
            Nodo_Elementos *get_czo() {return czo; };
            void borrar(void); //borra la cabeza
            Lista_Elementos* resto();
            void imprimir_lista();
            bool dato_existe(int a);
};
void Lista_Elementos::add(int p, int d)
{  
     Nodo_Elementos *nuevo=new Nodo_Elementos(p, d);
     nuevo->set_next(czo);
     czo=nuevo;
}
bool Lista_Elementos::esvacia(void)
{   
    return czo->es_vacio();
}

void Lista_Elementos::borrar(void)
{ 
  if(esvacia()){
  } else {
         Nodo_Elementos *tmp=czo;
         czo=czo->get_next();
         delete tmp;
  }
}

Lista_Elementos::~Lista_Elementos(void){
   while (!esvacia()){
         this->borrar();
   }
}

Lista_Elementos* Lista_Elementos::resto(){
                                  Lista_Elementos* l=new Lista_Elementos(czo->get_next());
                                  return (l);
}

void Lista_Elementos :: imprimir_lista(){
          if(!this->esvacia()){
                               cout<< " - " <<this->get_czo()->get_destino()<<" ("<<this->get_czo()->get_peso()<<")";
                               resto()->imprimir_lista();
          }         
}

bool Lista_Elementos:: dato_existe(int a){
         if(this->esvacia()) return false;
         else{
              if(a==this->get_czo()->get_destino()) return true;
              else  return this->resto()->dato_existe(a);
         } 
}
