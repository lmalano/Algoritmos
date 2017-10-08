#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;
class Nodo{
    private: 
        int dato;
        Nodo *next;
    public://metodos de la clase nodo
        Nodo() {next=NULL;};//el puntero next se inicializa en NULL
        Nodo(int a) {dato=a; next=NULL;};//a toma el valor de dato y next se inicializa en NULL
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
            void add(int d); //~Lista(void);
            bool esvacia(void);
            int cabeza(void);
            Lista *resto(void);
            string toPrint(string p);          
            void impre(void);
            int suma(int i);
            int suma2(void);//suma la lista
            int size();//calcula tamaño
            void borrar(void); //borra la cabeza
            void borrar_last();//borra el ultimo
            void concat(Lista *l1);//concatena
            Lista *copy();//copia lista
           	void tomar(int );//toma un elemento de la lista
};

int main()
{
    Lista *l=new Lista();//creo la lista l
    Lista *r=new Lista();//creo la lista r
   // Lista *l2=new Lista(); //creo la lista a donde se copiara l
    
    l->add(11);
    l->add(22);
    l->add(33);
    l->add(44);
    l->impre(); //muestra 11, 22, 33 y 44 en columna
    r->add(101);
    r->add(100);
    cout<< l->toPrint("fin de la lista soy l\n")<<endl;
    
   	 r->impre();//muestra 101, 100 en columna
    
      cout<< "suma de l:"<<l->suma(0)<<endl;//suma de l
      
    cout<< "suma2 de 1:"<<l->suma2()<<endl;//suma de l met. 2
   
   cout<<"Cantidad de nodos= "<<l->size()<<endl;//muestra nodos
   Lista *l2=l->copy();
   cout<< l2->toPrint(" soy l2 copiada de l") <<endl;
   l->borrar_last();//borra el ultimo elemento
   l->borrar();//borra el 1er elem
   cout<< l->toPrint(" fin de la lista soy l menos con el ultimo elemento y el 1ro ") <<endl;  //muestra la lista sin el ult elem 
      
    r->concat(l);//concateno r a l
    
    cout<< r->toPrint(" soy r concatenada") <<endl;//muestro concatenacion
    
	l->tomar(1);
    
    cout<< l->toPrint(" soy l tome el 1er elemento") <<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
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
       stm << this->cabeza()<<" - "<< this->resto()->toPrint(p);
      //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
       return stm.str();
     }
}

void Lista::impre(void)
{ Nodo *aux;
  aux=czo;
    while(aux->get_next()!=NULL){
         cout<<aux->get_dato()<<endl;
         aux=aux->get_next();
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

int Lista::size()
{ 
     if (this->esvacia()) {
        return 0;
     } else {
        return 1+this->resto()->size();
     }
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

void Lista::borrar_last()
{ if(!this->esvacia()){
     if((czo->get_next())->get_next()==NULL){
        delete czo->get_next();
        czo->set_next(NULL);
     }
     else this->resto()->borrar_last(); 
  }  
}


void Lista::concat(Lista *l1)
{
   if (!(l1->esvacia())){
      this->concat(l1->resto());
      this->add(l1->cabeza());
      
   }
}


Lista* Lista::copy()
{	Lista *l2=new Lista();
	l2->concat(this);//le pasamos a concat el puntero lista
	return l2;	
	

}
void Lista::tomar(int n)
{
	if(this->size()>n) 
	{
		this->borrar_last();
		this->tomar(n);
	}/*	if(!(this->esvacia()));
		if (n>0) this->resto()->tomar(n-1);
		else czo->set_next(NULL);*/}

	

