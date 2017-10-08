//#include <cstdlib>
#include <iostream>
#include <sstream>

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
            void del(void);
            void add(tipolista d);
            bool esvacia(void);
            tipolista cabeza(void);
            Lista *resto(void);
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

// prcd(o1,'(') = 0 para todo o1 != de ')'
// prcd(o1,')') = 1 para todo o1 != de '('
// prcd('(',o2) = 0 para todo 02
// prcd(o1,o2)  = 1 para todo o1 >= precedencia que o2
int prcd(int o1,int o2)
{ if(o2=='(')
	 if(o1==')') return 1;
            else return 0;
  if(o2==')')
	 if(o1=='(') return 0;
		    else return 1;
  if(o1=='(') return 0;

  if((o1=='*')||(o1=='/')) return 1;
  if(((o1=='+')||(o1=='-'))&&((o2=='+')||(o2=='-'))) return 1;
						                        else return 0;
}


int main()
{
    string cadena,pf;
    Pila *p=new Pila();

 cout<<endl<<"Ingrese cadena= "; cin>>cadena;
 cout<<"cadena= "<<cadena;
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
   
   cout<<"\n inicio conversion a POSTFIJO:"<<cadena<<endl;
      int i,j,k=0;
      char d,p1;
      for(j=0;j<cadena.length();j++)
      { d=cadena.at(j); cout<<"d= "<<d<<endl;
	    if ((d>='0')&&(d<='9')){pf[k]=d;k++; for(i=0;i<k;i++)cout<<pf[i];cout<<endl;
	    }else
	       { while((!p->pilavacia())&&(prcd(p->tope(),d)))
	             {p1=p->tope();p->desapilar();pf[k]=p1;k=k+1;cout<<"    pf= ";for(i=0;i<k;i++)cout<<pf[i];cout<<endl;
             }
	         if((p->pilavacia())||(d!=')')) p->apilar(d);
			 else p->desapilar();
	    }
      }
      while(!p->pilavacia())
	      {p1=p->tope();p->desapilar();pf[k]=p1;k++;}
      pf[k]='\0';
      cout<<"\n TERMINE la conversion a POSTFIJO: ";
      for(i=0;i<k;i++)cout<<pf[i];cout<<endl;
      
      //for(i=0;i<=k;i++){cout<<pf[i]; cadena[i]=pf[i];}
     
     cout<<endl;
     system("PAUSE");
     return 0;
}
