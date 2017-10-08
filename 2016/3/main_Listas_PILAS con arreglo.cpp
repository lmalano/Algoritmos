#include <cstdlib>
#include <iostream>
#include <sstream>
//unso arreglo en vez de lista
using namespace std;

typedef long int tipolista;

class Pila {
	private:
		tipolista d[100];
		int p;
	public:
		Pila() {p=-1;} ;//constructor pila hago -1 xq es la posicion q me indica q no hay nada
		void apilar(tipolista x) {d[++p]=x;};		
		tipolista tope(void) {return d[p];};
		void desapilar(void){p--;}; 
		bool pilavacia();	
};

bool Pila::pilavacia()
{return p==-1;}

int main()
{

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

//ingresar dentro un string una expresion aritmeticaq contendra partentesis, llaves y corchetes. 
//se debera chequear q la secuencia ingresada es la correcta

