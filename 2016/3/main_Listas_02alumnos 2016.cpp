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
            bool esta (int x);//verifica si esta un numero
            int cantNodos(int i);
            void impre(void);
};

void Lista::impre(void)
{
	Nodo *aux;
	aux=czo;
	while(aux->get_next()!=NULL)
	{
		cout<<"dato= "<<aux->get_dato();
			aux=aux->get_next();//pongo lo q tiene aux a lo q apunta a aux next 
	}
	
}


int Lista::cantNodos(int i)
{
	if(this->esvacia())
	return i;	
	else
	return this->resto()->cantNodos(i+1);
	
}

bool Lista::esta(int x)
{
  if(this->esvacia())
	return false;
	
	else if(x==this->cabeza())
	return true;
	
	return this->resto()->esta(x);//para caso general seria (en el resto
	
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
        return p; //si es vacia imprime p
     } else {
       std::ostringstream stm;// sttm funciona como un buffer de salida de una cadena
       stm << this->cabeza()<<"-"<< this->resto()->toPrint(p) << endl;//a este buffer le asignamos cosas, cout imprime em pantalla loq hay en buffer(cabeza y resto hay en el buffer)
      //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
       return stm.str();//transforma lo q esta en el buffer en un string
     }
}
int Lista::suma(int i)
{    cout<<" i al entrar= "<<i<<endl;
     if (this->esvacia()) {
        return i;
     } else {
        
        cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
        return this->resto()->suma(i+this->cabeza());//si no esta vacia, llama a resto y suma con la nueva cabeza
     }
}

int main()
{
    Lista *l=new Lista();
    Lista *r=new Lista();
    Lista *l2=new Lista();
    l->add(11);
    l->add(22);
    l->add(33);
    r->add(1);
    r->add(2);
    
    cout<< l->toPrint("fin") <<endl;
    cout<< "suma:"<<l->suma(0)<<endl;
 cout<<"verifico un numero si esta en la lista :"<< l->esta(36)<<endl;
  
  cout<<"cantidad de nodos :"<<l->cantNodos(0)<<endl;
  l->impre();
    system("PAUSE");
    return EXIT_SUCCESS;
    
}
