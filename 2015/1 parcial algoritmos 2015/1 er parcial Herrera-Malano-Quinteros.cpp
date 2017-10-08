#include <iostream>    


using namespace std;

typedef long int calculadora;

class Nodo{
    private: 
        calculadora dato;
        Nodo *next;
    public:
	    Nodo() {next=NULL;	};//se inicializa nodo sin parametro next=null 
        Nodo(calculadora a) {dato=a; next=NULL;};//se inicializa nodo para cuando se ingresa a del tipo calculadora
	    void set_next(Nodo *n) {next=n; };
        calculadora get_dato() {return dato; };
        Nodo *get_next() {return next; };
        bool vacio() {return next==NULL;}
};

class Lista{ 
    private: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            void anadir(calculadora a);   
            bool verifvacia(void);
            void del(void);
            calculadora vercabeza(void);
            Lista *resto(void);
            void impre(void);
            int suma(void);
            int resta(void);
            int mult(void);
            int div(void);
              
};

class Tokens:public Lista{//hereda de lista
      public:
             Tokens(){Lista();};//la clase token se hereda de la clase lista
             void apilar(calculadora x){anadir(x);};//la funcion apilar utiliza el metodo de la clase lista heredaro
             void desapilar(void) {del();};
        
}; 

int main()
{ 

Tokens *calc= new Tokens();

int a,b,d;
char c;
cout<<"inserte el 1er operando : ";
cin>>a;	
cout<<"inserte el 2do operando : ";
cin>>b;
 
cout<<"inserte el operador : ";
cin>>c;


calc->apilar(b);
calc->apilar(a);
calc->apilar(c);

switch(c)
{

case '+':

calc->desapilar();
cout<<"la suma es: "<<a<<b<<"+="<<calc->suma()<<endl;
d=a+b;			
break;	

	
	
case '-':

calc->desapilar();
cout<<"la resta es: "<<a<<b<<"-="<<calc->resta()<<endl;
d=a-b;
break;

   
case '*':

calc->desapilar();
cout<<"la multiplicacion es: "<<a<<b<<"*="<<calc->mult()<<endl;
d=a*b;
break;  

case '/':

calc->desapilar();
cout<<"la division es: "<<a<<b<<"/="<<calc->div()<<endl;
d=a/b;
break;


default:
	calc->desapilar();
      cout<<"operador no valido,corra el programa nuevamnete"<<endl;
		   break;
		   
		   
}


calc->desapilar();
calc->desapilar();

calc->apilar(d);
cout<<"el resultado se alamacena en un token, y su valor es : "<<endl;
calc->impre();
	
system("PAUSE");
return 0; 
}

void Lista::anadir(calculadora a)
{  
     Nodo *nuevo=new Nodo(a);
     nuevo->set_next(czo);
     czo=nuevo;
}

bool Lista::verifvacia(void)
{   
    return czo->vacio();
}


void Lista::del(void)
{    Nodo *aux;
     aux=czo;
     czo=czo->get_next();
     delete aux;
}


calculadora Lista::vercabeza(void)
{ 
  if(verifvacia()){
                cout<<" Error, Cabeza de lista vacia";
                return 1; 
  }
  return czo->get_dato();}
  
  Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo->get_next());
      return (l);
}

void Lista::impre(void)
{ Nodo *aux;
  aux=czo;
    while(aux->get_next()!=NULL){
         cout<<aux->get_dato()<<endl;
         aux=aux->get_next();
    }
}


int Lista::suma(void){
	
     if (verifvacia()) return 0;
     
     
     else return vercabeza()+resto()->suma(); 
     
}


int Lista::resta(void){
     if (verifvacia()) return 0;
     
     
     else return vercabeza()-resto()->resta();
}


int Lista::mult(void){	
  if (verifvacia()) return 0;
     
	   
    else return vercabeza()*resto()->suma();
   }
   
     



int Lista::div(void){
	

	
     if (verifvacia()) return 0;
     
     
     else return vercabeza()/resto()->suma();
}



