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
          //  ~Lista(void);
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
            int topelista();
};

class Cola:public Lista{//hereda los metodos de lista
	
	public:
		Cola(void);
		~Cola(void);
		int tope();
		bool colavacia();
		void encolar(int a);
		void desencolar();
		int ultimo();
		string imprimir(string s);
	
};


Cola::Cola()
{
	Lista();
}

void Cola::encolar(int a)
{
	this->add(a);
	
}
void Cola::desencolar()
{
this->borrar_last();
}


string Cola::imprimir(string s)
{
return	this->toPrint(s);
}

bool Cola::colavacia()
{
	this->esvacia();
}

int Cola::tope()
{
	return topelista();
}

int Cola::ultimo()
{	return this->cabeza();
}

//----------------------

int Lista::topelista()
{

if(!this->esvacia()) {
	if(this->resto()->esvacia())  return this->cabeza();
	return this->resto()->topelista();
	}
	return 0;
	
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
;
    
    
    l->add(11);
    l->add(22);
    l->add(33);
  


    cout<< l->toPrint(" soy l") <<endl;


	Cola *c=new Cola();
	
	
	
	c->encolar(10);
	c->encolar(20);
	c->encolar(40);
//	c->desencolar();
//	cout<<c->colavacia(); //devuelve 0 si no esta vacia y 1 si esta vacia la cola

	cout<<c->imprimir("colaaaa")<<endl;
cout<<"----"<<endl;
cout<<c->ultimo()<<endl;
cout<<c->tope() <<endl;

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

