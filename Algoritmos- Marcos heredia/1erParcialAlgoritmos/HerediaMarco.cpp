// Parcial realizado por Heredia Marco, Matricula: 93560445

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Token{
    protected: 
    double num;
    char ope;
    int tipo;
    public:
    Token(){};
    Token(string a);
	bool es_ope(){	if(tipo==0) return true;
					else return false;};
	char getOpe(){if (this->es_ope()) return ope;};
	double getNum(){if (!this->es_ope()) return num;};
};

Token::Token(string a){
			if (a.at(0)=='+' ||a.at(0)=='-' ||a.at(0)=='*' ||a.at(0)=='/'){ ope=a.at(0);tipo=0;}
			else{
			num=atof(a.c_str()); tipo=1;
			}
	}

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
            void add(Token d);
            bool esvacia(void);
            Token cabeza(void);
            Lista *resto(void);
            string toPrint(string p);   
            int cantOpe(void);
            int cantNum(void);
            int size();          
};

class Pila:public Lista{
      public:
             Pila(){Lista();};
             void apilar(Token x){add(x);};
             Token tope(void){return cabeza();};
             void desapilar(){del();};
             bool pilavacia(){return esvacia();};
};                  

int Lista::size()
{ 
     if (this->esvacia()) {
        return 0;
     } else {
        return 1+this->resto()->size();
     }
}

int Lista::cantOpe()
{ 
     if (this->esvacia())  return 0;
     else if (this->cabeza().es_ope())     return 1+this->resto()->cantOpe();
     else return this->resto()->cantOpe();     
}

int Lista::cantNum()
{ 
     if (this->esvacia())  return 0;
     else if (this->cabeza().es_ope())     return this->resto()->cantNum();
     else return 1+this->resto()->cantNum();     
}

void Lista::del(void)
{    Nodo *aux;
     aux=czo;
     czo=czo->get_next();
     delete aux;
}

void Lista::add(Token d)
{  
     Nodo *nuevo=new Nodo(d);
     nuevo->set_next(czo);
     czo=nuevo;
}

bool Lista::esvacia(void)
{   
    return czo->es_vacio();
}

Token Lista::cabeza(void)
{ 
  if(esvacia())
                cout<<" Error, Cabeza de lista vacia";
  else
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
      if (this->cabeza().es_ope()) stm << this->cabeza().getOpe()<<"   "<< this->resto()->toPrint(p);// << endl;
      else stm << this->cabeza().getNum()<<"   "<< this->resto()->toPrint(p);// << endl;
      return stm.str();
     }
}

Pila *pila= new Pila();
class Calculadora{ 
    protected: Lista *lista;
    public:
            Calculadora(Lista *l) {lista= l;};
            Lista *verL(){return lista;} ;
        	Pila *verP(){return pila;};
        	Calculadora avanza();
        	Calculadora opera();
        	Token calcula(Token,Token,Token);
        	Token evaluar();
        	bool verificar();
};

Calculadora Calculadora::avanza(){
	pila->apilar(lista->cabeza());
	return Calculadora(lista->resto());
}

Calculadora Calculadora::opera(){
	Token t1=pila->tope();
	pila->desapilar();
	Token t= calcula(lista->cabeza(),pila->tope(),t1);
	pila->desapilar();
	pila->apilar(t);
	return Calculadora(lista->resto());
}

Token Calculadora::calcula(Token ope, Token n1, Token n2){
	switch (ope.getOpe()){
	case '+':{	std::stringstream s;
				s << n1.getNum() + n2.getNum();
				return s.str();
				break;}
	case '-':{	std::stringstream s;
				s << n1.getNum() - n2.getNum();
				return s.str();
				break;}
	case '*':{	std::stringstream s;
				s << n1.getNum() * n2.getNum();
				return s.str();
				break;}
	case '/':{	if (n2.getNum()==0)cout<<"ERROR: Division por cero."<<endl<<endl;
				else{
				std::stringstream s;
				s << n1.getNum() / n2.getNum();
				return s.str();
				break;}
}}}

bool Calculadora::verificar(){
	return lista->cantNum()==(lista->cantOpe()+1);
}
bool yaverifico=false;
Token Calculadora::evaluar(){
	if (!verificar() && !yaverifico)cout<<"ERROR: vuelva a revisar los valores ingresados."<<endl<<endl;
	else{ yaverifico=true;
	if (this->verL()->esvacia())return pila->tope();
	else if (lista->cabeza().es_ope()){ 
								if (pila->size()<2) //Controla el orden de los operadores
								cout<<"Error: vuelva a revisar los valores ingresados"<<endl<<endl;
								else opera().evaluar();}
	else avanza().evaluar();
}}

int main(){
	Lista *l= new Lista();
	cout<<"La expresion infija a calcular es: (70+[(13+7)*4])/60"<<endl<<endl;
	
	l->add(Token("/"));
	l->add(Token("60"));
	l->add(Token("+"));
	l->add(Token("*"));
	l->add(Token("4"));
	l->add(Token("+"));
	l->add(Token("7"));
	l->add(Token("13"));
	l->add(Token("70"));

	cout<<l->toPrint("<-- Expresion postfija")<<endl<<endl;
    Calculadora c= Calculadora(l);
    c.evaluar();
	cout<<"El resultado es:"<<c.verP()->toPrint("")<<endl;
     
    system("PAUSE");
    return EXIT_SUCCESS; 
}
