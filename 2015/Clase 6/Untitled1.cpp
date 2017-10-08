#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;
class Token
{
	private:
		char operador;
		int valor;
	public:
		Token ()
		{
			operador='a';
			valor=314;
		}		
		int getValor(){ return valor;};
		char getOp(){ return operador;};
		void set_Valor (int v){valor=v;};
		void set_Op(char o){ operador=o;};
		bool es_Valor()
		{
			if(operador=='a') return true;
			else return false;			
		};	
};

class Nodo{
    protected: 
        Token dato;
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        Nodo(Token a) {dato=a; next=NULL;};
        void set_dato(Token a) {dato=a; };
        void set_next(Nodo *n) {next=n; };
        Token get_dato() {return dato; };
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    protected: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            void del(void);
            void add1(char d);
            void add2(int d);
            bool esvacia(void);
            Token cabeza(void);
            Lista *resto(void);
            string toPrint(string p);            
};

void Lista::add1(char d)
{  
	 Token tok;
	 tok.set_Op(d);
     Nodo *nuevo=new Nodo(tok);
     nuevo->set_next(czo); 
     czo=nuevo;
}

void Lista::add2(int d)
{  
	 Token tok;
	 tok.set_Valor(d);
     Nodo *nuevo=new Nodo(tok);
     nuevo->set_next(czo);
     czo=nuevo;
}
bool Lista::esvacia(void)
{   
    return czo->es_vacio();
}

Token Lista::cabeza(void)
{ 
  if(esvacia()){
                cout<<" Error, Cabeza de lista vacia";
                //return ' '; 
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
     if (this->esvacia())
	  {
        return p;
      }
	  else 
	  {
        std::ostringstream stm; //se crea un buffe para ir almacenando string
        if(cabeza().es_Valor())
	    {
	   	   stm << this->cabeza().getValor()<<" ; ";
	    }
	    else
	    {
	   	   stm << this->cabeza().getOp()<<" ; ";
	    }
	    stm<< this->resto()->toPrint(p);
        return stm.str();
     }
}

int main ()
{
	string expresion;
	Lista *L=new Lista();
	cout<<endl<<"Ingrese la expresion: ";
	cin>>expresion;
	//int j;
	int i=0; 
	while (i<expresion.length())// la longitud del string tmb te cuenta las comas!!
	{
		if(expresion.at(i)=='+' || expresion.at(i)=='*' || expresion.at(i)=='-' || expresion.at(i)=='/')
		{
			L->add1(expresion.at(i));
		}
		if (expresion.at(i)!=',')
		{
			L->add2(atoi(&expresion.at(i)));//ver pq el ampersan, pq sino no funca
			while ((i+1)<expresion.length() && (expresion.at(i+1)!=','))//la coma es la separacion de operandosen el posfijo
			{                          //se cuelga si le agregas sólo un número sin coma de separación 
				i++;
			}
		}	
		i++;
			
		cout<<expresion.length()<<endl;
		cout<<"i="<<i<<endl;
	}
	cout<<endl<<L->toPrint("lista")<<endl;	
}
















