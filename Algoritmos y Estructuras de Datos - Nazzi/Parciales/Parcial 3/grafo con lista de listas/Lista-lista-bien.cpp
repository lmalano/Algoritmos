#include <iostream>
#include <sstream>
#include <fstream>
#include "Lista de elementos.cpp"

/*
  Las clases definidas aqui, forman las listas que integran el arreglo 
                       de listas de adyacencia.
*/

using namespace std;

class Nodo{
    private:
            int origen;
            Nodo *next_abajo; 
            Lista_Elementos *next_derecha;
    public:
           Nodo() {next_abajo=NULL;next_derecha=NULL;};
           Nodo(int a) {origen=a; next_abajo=NULL;next_derecha=NULL;};
           void set_origen (int a){origen=a;};
           void set_nextabajo(Nodo* n){next_abajo=n;}
           void set_nextderecha(Lista_Elementos* l) {next_derecha=l;};
           int get_origen(){return origen;};
           Nodo *get_nextabajo() {return next_abajo; };
           Lista_Elementos *get_nextderecha() {return next_derecha; };
           bool nodo_vacio() {return next_abajo==NULL;}
};

class Lista{
    private:
            Nodo *czo_lista;
    public:
           Lista() {czo_lista=new Nodo();};
           Lista(Nodo *n) {czo_lista=n;};
           //~Lista(void);
           void add_nodo(int);
           bool listavacia(void);
           Nodo* get_czo_lista() {return czo_lista; };
           bool is_dato(int a);
           Nodo_Elementos* set_lista_elementos(int, int, int);
           //void borrar(void); //borra la cabeza
           Lista *lista_resto(void); 
           void impresionlista();
};

void Lista::add_nodo(int o)
{  
                    Nodo *nuevo=new Nodo(o);
                    nuevo->set_nextabajo(czo_lista);
                    nuevo->set_nextderecha(NULL);
                    czo_lista=nuevo;
}

bool Lista::listavacia(void)
{   
    return czo_lista->nodo_vacio();
}

/*void Lista::borrar(void)
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
}*/

void Lista::impresionlista(){
     if(!this->listavacia()) {
                       cout<<this->get_czo_lista()->get_origen()<<"----->";
                       czo_lista->get_nextderecha()->imprimir_lista();
                       cout<<endl;
                       this->lista_resto()->impresionlista();
     }
}

Lista *Lista::lista_resto()
{ 
      Lista *l=new Lista(czo_lista->get_nextabajo());
      return (l);
}

bool Lista::is_dato(int a){
     if(this->listavacia()) return false;
     else{
          if(a==this->get_czo_lista()->get_origen()) return true;
          else  return this->lista_resto()->is_dato(a);
     }
}

Nodo_Elementos* Lista:: set_lista_elementos(int o, int p, int d){
                if(this->is_dato(o)){                                                           // Pregunto si el vertice de origen ya existe
                                     int vertice_origen=this->get_czo_lista()->get_origen();                                             
                                     if(o==vertice_origen){
                                                          this->get_czo_lista()->get_nextderecha()->add(p,d);//debo llamar al metodo add de Lista de elementos (ahi hace la asignacion de punteros y agrega datos.) 
                                     }
                                     else return this->lista_resto()->set_lista_elementos(o,p,d);                  
                }
                else{
                     this->add_nodo(o);
                     Lista_Elementos *l=new Lista_Elementos();                           //aca esta el error. No agrego los datos de peso y destino cuando no hay nodo Lista creado
                     l->add(p,d);
                     czo_lista->set_nextderecha(l);
                }             
}


