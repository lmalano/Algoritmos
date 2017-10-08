//#include <cstdlib>
#include <iostream>
#include <sstream>

//comentar que como es una lista de string, tengo que redefinir el nodo
//resaltar que solo se cambia la parte int de la lista anterior por string
using namespace std;

typedef long int tipolista;

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
            string toPrint(string p);   
            
};

class Pila:public Lista{
      public:
             Pila(){Lista();};
             void apilar(tipolista x){add(x);};
             tipolista tope(void){return cabeza();};
             void desapilar(void){del();};
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
                return ' '; 
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
       return stm.str();
     }
}

int main()
{
    string cadena,pf;
    Pila *p=new Pila();

 cout<<endl<<"Ingrese cadena= "; cin>>cadena;
  int error=0;
  for(int i=0;(i<cadena.length())&&(!error);i++){
          if (cadena.at(i)=='{') p->apilar('{');       
          if (cadena.at(i)=='[') p->apilar('[');
          if (cadena.at(i)=='(') p->apilar('(');
          
          if (cadena.at(i)=='}'){
                                 if (p->pilavacia()) error=1;
                                 else
                                     if(p->tope()!='{') error=1;
                                     else p->desapilar();                     
          }                               
          if (cadena.at(i)==']'){
                                 if (p->pilavacia()) error=1;
                                 else
                                     if(p->tope()!='[') error=1;
                                     else p->desapilar();                     
          }                               
          if (cadena.at(i)==')'){
                                 if (p->pilavacia()) error=1;
                                 else
                                     if(p->tope()!='(') error=1;
                                     else p->desapilar();                     
          }   
		  
		                            
    }  
    
    
    if((!error)&&p->pilavacia())cout<<endl<<"TOdo OK";
    else cout<<endl<<"ERROR";
    
  
     cout<<endl;
     system("PAUSE");
     return 0;
}

