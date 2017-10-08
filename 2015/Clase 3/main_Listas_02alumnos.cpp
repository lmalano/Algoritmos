#include <cstdlib>
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

string Lista::toPrint(string p)
{ 
     if (this->esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm << this->cabeza()<<"-"<< this->resto()->toPrint(p) << endl;
      //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
       return stm.str();
     }
}
int Lista::suma(int i)
{    cout<<" i al entrar= "<<i<<endl;
     if (this->esvacia()) {
        return i;
     } else {
        
        cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
        return this->resto()->suma(i+this->cabeza());
     }
}

int main()
{
    Lista *l=new Lista();
    Lista *r=new Lista();
    Lista *l2=new Lista();
    l->add(11);
    l->add(23);
    l->add(33);
    r->add(1);
    r->add(2);
    r->add(5);
    cout<< l->toPrint("fin") <<endl;
    cout<< "suma:"<<l->suma(0)<<endl;
   
    system("PAUSE");
    return EXIT_SUCCESS;
    
}
