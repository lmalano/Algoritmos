//#include <cstdlib>
#include <iostream>
#include <sstream>
#define ORDEN 4

//comentar que como es una lista de string, tengo que redefinir el nodo
//resaltar que solo se cambia la parte int de la lista anterior por string
using namespace std;

class NodoArbolB{
    private: 
        int dato[ORDEN+1];
        NodoArbolB *hijos[ORDEN+2];
        NodoArbolB *padre;
        int lastused;
        
    public:
        NodoArbolB();
        ~NodoArbolB(void) {;};
        bool lleno() {return lastused==ORDEN-1;};
        void set_dato(int a) ;
        bool is_dato(int a);
        int  get_pos(int a);
        int  get_dato(int i) {return dato[i];};
        int  get_lastused() {return lastused;};
        NodoArbolB* get_hijo(int a){return hijos[a];}
        void set_padre(NodoArbolB* a){padre=a;}
        NodoArbolB* get_padre(){return padre;}
        bool es_hoja(){return hijos[0]==NULL;}
        void set_hijo(int a,NodoArbolB* b){hijos[a]=b;}
};
typedef NodoArbolB* tipolista;

class Nodo{
    protected: 
        tipolista dato;
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        Nodo(tipolista a) {dato=a; next=NULL;};
        void set_dato(tipolista a) {dato=a; };
        void set_next(Nodo *n) {next=n; };
        tipolista get_dato() {return dato; };
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    protected: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            //~Lista(void);
            //tipolista Lista::ultimo(tipolista x);
            void del(void);
            void add(tipolista d);
            bool esvacia(void);
            tipolista cabeza(void);
            Lista *resto(void);
            tipolista toPrint(tipolista p);   
            string esta(tipolista p,bool t2);
            int dondeesta(tipolista p,int t2,int pos);
            tipolista maslargo(tipolista t2);
};

class Pila:public Lista{
      public:
             Pila(){Lista();};
             void push(tipolista x){add(x);};
             tipolista tope(void){return cabeza();};
             void pop(void){del();};
             bool pilavacia(){return esvacia();};
};                  

void Lista::del(void)
{    Nodo *aux;
     aux=czo;
     czo=czo->get_next();
     delete aux;
}
void Lista::add(tipolista d)
{  
     Nodo *nuevo=new Nodo(d);
     nuevo->set_next(czo);
     czo=nuevo;
}
bool Lista::esvacia(void)
{   
    return czo->es_vacio();
}

tipolista Lista::cabeza(void)
{ 
  if(esvacia()){
                cout<<" Error, Cabeza de lista vacia";
                return NULL; 
  }
  return czo->get_dato();
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo->get_next());
      return (l);
}

/*tipolista Lista::toPrint(tipolista p)
{ 
     if (this->esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm << this->cabeza()<<"-"<< this->resto()->toPrint(p) << endl;
       return stm.str();
     }
}
//mostrar que solo cambia la parte de procesemiento individual en cada funcion
*/
inline string Lista::esta(tipolista p, bool t2)
{ 
     if (this->esvacia()) {
        if(t2) return " si esta";
        else return " no esta";
     } else {
//      esta es la parte que hace el procesamiento
        if (p==this->cabeza()) {
           t2=true;
        }
//        
        return this->resto()->esta(p,t2);
     }
}

int Lista::dondeesta(tipolista p, int t2, int pos)
{ 
     if (this->esvacia()) {
        return t2;
     } else {
//      esta es la parte que hace el procesamiento
        if (p==this->cabeza()) {
           t2=pos;
        }
        pos++;
//        
        return this->resto()->dondeesta(p,t2,pos);
     }
}
/*tipolista Lista::maslargo(tipolista t2)
{ 
     if (this->esvacia()) {
        return t2;
     } else {
//      esta es la parte que hace el procesamiento
        if (this->cabeza().size()>t2.size()){
           t2=this->cabeza();
        }
//        
        return this->resto()->maslargo(t2);
     }
}*/
