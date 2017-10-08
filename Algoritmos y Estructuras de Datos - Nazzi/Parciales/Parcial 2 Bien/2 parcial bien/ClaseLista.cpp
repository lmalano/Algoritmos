#include <iostream>
#include <sstream>

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
        Lista *copy2(Lista *l, Nodo *last);
        void take2(Nodo *last);
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            ~Lista(void);
            void add(int d);
            bool esvacia(void);
            int cabeza(void);
            Lista *resto(void);
            Lista *copy();
            Nodo *get_czo() {return czo; };
            void borrar(void); //borra la cabeza
            void drop(int n);
            void take(int n);
            void concat(Lista *l1);
            string toPrint(string p);   
            int suma(int i);
};

class Pila:public Lista{
      public:
             Pila(){Lista();};
             void push(int x){add(x);};
             int tope(void){return cabeza();};
             void pop(void){borrar();};
             bool pilavacia(){return esvacia();};
}; 

void Lista::add(int d)
{  
     Nodo *nuevo=new Nodo(d);
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
  return czo->get_dato();
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
      last->set_dato(this->cabeza());
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
 
void Lista::concat(Lista *l1)
{
   if (!(l1->esvacia())){
      this->concat(l1->resto());
      this->add(l1->cabeza());
   }
}

string Lista::toPrint(string p)
{ 
     if (this->esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm << this->cabeza()<<"-"<< this->resto()->toPrint(p) ;
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

int main()
{
    Lista *l=new Lista();
    l->add(8);
    l->add(6);
    l->add(4);
    l->add(2);
    cout<< "l:"<< l->toPrint("") <<endl;
    cout<< "suma:"<<l->suma(0)<<endl;
    Lista *l2=l->copy();
    Lista *l3=l->copy();
    l->borrar();
    cout<< "suma:"<<l->suma(0)<<endl;

    cout<<"l2:"<< l2->toPrint("") <<endl;
    l2->add(15);
    cout<<"l2 ++ 15:"<< l2->toPrint("") <<endl;
    l2->borrar();
    cout<<"l2 --15:"<< l2->toPrint("") <<endl;
    l2->take(2);
    cout<<"l2 :"<< l2->toPrint("") <<endl;
    l3->drop(2);
    cout<<"l3 :"<< l3->toPrint("") <<endl;

    Lista *l4=l3->copy();
    l4->concat(l2);
    cout<<"l4 :"<< l4->toPrint("") <<endl;
    cout<<"l orig:"<< l->toPrint("") <<endl;
    delete l;
    delete l2;
    delete l3;
    delete l4;
//    system("PAUSE");
    
}
