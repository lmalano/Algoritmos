#include <iostream>
#include <sstream>

using namespace std;
class Nodo1{
    private: 
        int dato;
        Nodo1 *next;
    public:
        Nodo1() {next=NULL;};
        Nodo1(int a) {dato=a; next=NULL;};
        void set_dato(int a) {dato=a; };
        void set_next(Nodo1 *n) {next=n; };
        int get_dato() {return dato; };
        Nodo1 *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista1{
    private: Nodo1 *czo;
        Lista1 *copy2(Lista1 *l, Nodo1 *last);
        void take2(Nodo1 *last);
    public:
            Lista1() {czo=new Nodo1();};
            Lista1(Nodo1 *n) {czo=n;};
            ~Lista1(void);
            void add(int d);
            bool esvacia(void);
            int cabeza(void);
            Lista1 *resto(void);
            Lista1 *copy();
            Nodo1 *get_czo() {return czo; };
            void borrar(void); //borra la cabeza
            void drop(int n);
            void take(int n);
            void concat(Lista1 *l1);
            string toPrint(string p);   
            int suma(int i);
};
void Lista1::add(int d)
{  
     Nodo1 *nuevo=new Nodo1(d);
     nuevo->set_next(czo);
     czo=nuevo;
}
bool Lista1::esvacia(void)
{   
    return czo->es_vacio();
}

int Lista1::cabeza(void)
{ 
  if(esvacia()){
                cout<<" Error, Cabeza de Lista1 vacia";
                return -1; 
  }
  return czo->get_dato();
}

Lista1 *Lista1::resto(void)
{ 
      Lista1 *l=new Lista1(czo->get_next());
      return (l);
}

Lista1 *Lista1::copy2(Lista1 *l, Nodo1 *last)
{ 
   if (this->esvacia()){
      return l;
   } else {
      last->set_dato(this->cabeza());
      Nodo1 *nuevo=new Nodo1();
      last->set_next(nuevo);
      return (this->resto())->copy2(l,nuevo);
   }
}

Lista1 *Lista1::copy(void)
{ 
      Lista1 *l=new Lista1();
      return this->copy2(l,l->get_czo());
}

void Lista1::borrar(void)
{ 
  if(esvacia()){
  } else {
         Nodo1 *tmp=czo;
         czo=czo->get_next();
         delete tmp;
  }
}

Lista1::~Lista1(void){
   while (!esvacia()){
         this->borrar();
   }
}

void Lista1::drop(int n){
   if (!(this->esvacia()) && (n>0)) {
       this->borrar();
       this->drop(n-1);
   }
}

void Lista1::take2(Nodo1 *last){
     if (!(last->es_vacio())){
        this->take2(last->get_next());
     }
     delete last;

}

void Lista1::take(int n)
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
 
void Lista1::concat(Lista1 *l1)
{
   if (!(l1->esvacia())){
      this->concat(l1->resto());
      this->add(l1->cabeza());
   }
}

string Lista1::toPrint(string p)
{ 
     if (this->esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm << this->cabeza()<<"-"<< this->resto()->toPrint(p) ;
       return stm.str();
     }
}
int Lista1::suma(int i)
{ 
     if (this->esvacia()) {
        return i;
     } else {
        return this->resto()->suma(i+this->cabeza());
     }
}
