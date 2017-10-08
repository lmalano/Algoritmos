#include <iostream>
#include <sstream>

using namespace std;
class Nodo{
    private: 
        int costo;
        int source;
        int dest; 
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        Nodo(int v1,int v2,int a) {source=v1; dest=v2;costo=a; next=NULL;};
        void set_source(int a){source=a;}
        void set_dest(int a){dest=a;}
        int get_source(){return source;}
        int get_dest(){return dest;}
        void set_costo(int a) {costo=a; };
        void set_next(Nodo *n) {next=n; };
        int get_costo() {return costo; };
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    private: Nodo *czo;
        Lista *copy2(Lista *l, Nodo *last);
        void take2(Nodo *last);
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            ~Lista(void);
            void add(int source,int dest,int d);
            bool esvacia(void);
            int cabeza(void);
            Lista *resto(void);
            Lista *copy();
            Nodo *get_czo() {return czo; };
            void borrar(void); //borra la cabeza
            void drop(int n);
            void take(int n);
            void toPrint();   
            int suma(int i);
};
void Lista::add(int v1, int v2,int d)
{  
     Nodo *nuevo=new Nodo(v1,v2,d);
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
                cout<<" Error, Cabeza de Lista vacia";
                return -1; 
  }
  return czo->get_costo();
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo->get_next());
      return (l);
}

Lista *Lista::copy2(Lista *l, Nodo *last)
{ 
   if (this->esvacia()){
      return l;
   } else {
      last->set_costo(this->cabeza());
      Nodo *nuevo=new Nodo();
      last->set_next(nuevo);
      return (this->resto())->copy2(l,nuevo);
   }
}

Lista *Lista::copy(void)
{ 
      Lista *l=new Lista();
      return this->copy2(l,l->get_czo());
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

void Lista::drop(int n){
   if (!(this->esvacia()) && (n>0)) {
       this->borrar();
       this->drop(n-1);
   }
}

void Lista::take2(Nodo *last){
     if (!(last->es_vacio())){
        this->take2(last->get_next());
     }
     delete last;

}

void Lista::take(int n)
{ 
   if(!(this->esvacia())) {
      if (n>0){
         this->resto()->take(n-1);
      } else {
         this->take2((this->get_czo())->get_next());
         (this->get_czo())->set_next(NULL);
         
      }
   }
}
 


void Lista::toPrint()
{ 
     if (this->esvacia()) {
        
     } else {
       
       cout<<"source: "<<this->czo->get_source()<<" Destino: "<<this->czo->get_dest()<<" costo: "<<this->czo->get_costo()<<endl; this->resto()->toPrint() ;
       
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
