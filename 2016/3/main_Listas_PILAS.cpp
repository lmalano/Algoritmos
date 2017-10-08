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
            void impre(void);
            int suma2(void);
            int size();
            void borrar(void); //borra la cabeza
            void borrar_last();//borra el ultimo
            void concat(Lista *l1);
            Lista *copy(void);
            void tomar(int n);
};

class Pila:public Lista{//hereda los metodos de lista
	
	public:
		Pila() {Lista();};//constructor pila
		void apilar(int x);
		int tope(void);
		void desapilar(void) {borrar();};
		bool pilavacia() {return esvacia();};
	
	
};

void Pila::apilar(int x)
{	add(x);	}

int Pila::tope()
{
return cabeza();
}

int Lista::size()
{ 
     if (this->esvacia()) return 0;
     return 1+this->resto()->size();
}
void Lista::impre(void)
{ Nodo *aux;
  aux=czo;
    while(aux->get_next()!=NULL){
         cout<<aux->get_dato()<<endl;
         aux=aux->get_next();
    }
}
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
  if(this->esvacia()){
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
       stm << this->cabeza()<<" - "<< this->resto()->toPrint(p) << endl;
      //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
       return stm.str();
     }
}
int Lista::suma(int i)
{    //cout<<" i al entrar= "<<i<<endl;
     if (esvacia()) {return i;
     } else {
        
        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
        return resto()->suma(i+cabeza());
     }
}
int Lista::suma2(void){
     if (esvacia()) return 0;
     
     else return cabeza()+resto()->suma2();
}

int main()
{
    Lista *l=new Lista();
    Lista *r=new Lista();
    
    l->add(11);
    l->add(22);
    l->add(33);
    //l->impre();
   // l->add(532);
   /*
    r->add(1);
    r->add(2);*/
    //cout<< l->toPrint(" fin de la lista") <<endl;
   // cout<< "suma:"<<l->suma(0)<<endl;
   // cout<< "suma2:"<<l->suma2()<<endl;
   // cout<<"Cantidad de nodos= "<<l->size()<<endl;
    l->add(44);
    l->add(55);
    //cout<< l->toPrint(" fin de la lista") <<endl;
    /*l->borrar_last();
    cout<<"-------------------------------"<<endl;
    cout<< l->toPrint(" soy l") <<endl;
    //cout<<"Cantidad de nodos= "<<l->size()<<endl;
    r->add(101);
    r->add(100);
    
    r->concat(l);
    
    cout<< r->toPrint(" soy r concatenada") <<endl;
    cout<< l->toPrint(" soy la l ") <<endl;
    */
    Lista *l2=l->copy();
    //l->borrar_last();
    //l->borrar_last();
    l->tomar(3);
    cout<< l2->toPrint(" soy l2") <<endl;
    cout<< l->toPrint(" soy l") <<endl;
    
  //--------------------------------------------------------------------  
   Pila *p1=new Pila();
   p1->apilar(10);
   p1->apilar(20);
   cout<<p1->toPrint("hola pila");
//----------------------------------------------------------------------

string cadena ,pf;
Pila *p=new Pila();

cout<<endl<<"ingrese cadena= ";cin>>cadena;
int error=0;
for(int i=0;(i<cadena.length())&&(!error);i++){//length metodo de la clase string q me da el largo del la cadena
          if (cadena.at(i)=='{') p->apilar('{');    //si detecta algo abierto lo apila   
          if (cadena.at(i)=='[') p->apilar('[');//el .at es metodo q lee cada caracter de la cadena
          if (cadena.at(i)=='(') p->apilar('(');
         
          if (cadena.at(i)=='}'){//si detecta el cierre verifica si hay error, si la pila esta vacia es error, sino desapila
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
    
    if((!error)&&p->pilavacia())cout<<endl<<"OK"<<endl;
    else cout<<endl<<"ERROR"<<endl;

    system("PAUSE");
    return EXIT_SUCCESS;  
}
void Lista::borrar(void)
{ //borra el nodo cabeza
  if(esvacia()){
  } else {
         Nodo *tmp=czo;
         czo=czo->get_next();
         delete tmp;
  }
}
void Lista::borrar_last()
{ // borra el ultimo nodo
   if(!this->esvacia()){
      if((czo->get_next())->get_next()==NULL){
         delete czo->get_next();
         czo->set_next(NULL);
      }
      else this->resto()->borrar_last(); 
   }  
}
void Lista::concat(Lista *l1)
{// le transfiere los datos de l1 a this
   if (!(l1->esvacia())){
      this->concat(l1->resto());
      this->add(l1->cabeza());
   }
}
Lista *Lista::copy(void)
{ 
      Lista *aux=new Lista();
      aux->concat(this);
      return aux;
}
void Lista::tomar(int n)
{ //deja "vivos" los n primeros nodos y borra el resto
/*   if(!(this->esvacia())) {
      if (n>0) this->resto()->tomar(n-1);
      else     czo->set_next(NULL);
   }
*/
   if(this->size()>n){
      this->borrar_last();
      this->tomar(n);
   }
}
 

//ingresar dentro un string una expresion aritmeticaq contendra partentesis, llaves y corchetes. 
//se debera chequear q la secuencia ingresada es la correcta

