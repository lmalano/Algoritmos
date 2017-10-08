#include <cstdlib>
#include <iostream>
#include <sstream>
#define MAX 4

using namespace std;
// almacena MAX-1 elementos
class Cola{
      private:
              int Q[MAX];
              int pi,pf;
  public:
      Cola(void){pi=0;pf=MAX-1;};
      ~Cola(void);
      int tope(){return Q[pi];};
      bool colavacia(){return pi==(pf+1)%MAX;};//si pi es =(pf+1)%max el modulo lo q sobra del maxima, de la posi final sobrante va al inicio,sila cola esta vacia
      bool colallena(){return pi==(pf+2)%MAX;};//condicion de la cola llena
      void encolar(int a);
      void desencolar();
      int ultimo();
      string imprimir(string s);
};
//-------- Metodos de Cola --------------------
void Cola::encolar(int a)
{  if (!colallena()){//sila cola no esta llena, pf=.... y Q[pf]=a
     pf=(pf+1)%MAX;
     Q[pf]=a; 
   }
   else cout<<"Cola llena"<<endl;  
}
void Cola::desencolar(void)
{  if (!colavacia())pi=(pi+1)%MAX;//pregunta si la cola no esta vacia , incrementa el valor de pi 
   else cout<<"Cola vacia"<<endl;  
}
int Cola::ultimo(void)
{   return Q[pf];//pf señala el ultimo
}
string Cola::imprimir(string s)
{    if(!colavacia()){  //pregunta si la cola esta vacia-->si pi es menor o igual a pf--> recorrre de pi a pf e imprime. sino va de pi a MAX y de 0 a pf
		
       if(pi<=pf){
            for(int i=pi;i<=pf;i++)
               cout<<Q[i]<<"*";
       }else{
            for(int i=pi;i<MAX;i++)cout<<Q[i]<<"-";
            for(int i=0;i<=pf;i++)cout<<Q[i]<<"+";
       }
     }  
               
       return "";//para q salga algo
}
//------------------------------------------------------
int main()
{
    Cola *c=new Cola();
   if (c->colavacia()) cout<<endl<<"La cola esta VACIA"<<endl<<endl;
   c->encolar(15);
    c->encolar(2);
    c->encolar(3);
    c->encolar(33);//si este se encola m da q la cola esta llena debido al max
    cout<<c->imprimir(" >>>")<<endl;
   cout<<"en cola:"<<c->tope()<<endl;
   cout<<"ultimo ingresado= "<<c->ultimo()<<endl;
    if(!c->colavacia())c->desencolar();

   cout<<"en cola:"<<c->tope()<<endl;
    cout<<c->imprimir(" >>>")<<endl;
 if(!c->colavacia())c->desencolar();
    cout<<"en cola:"<<c->tope()<<endl;
  cout<<c->imprimir(" >>>")<<endl;
   if(!c->colavacia())c->desencolar();
  cout<<"en cola:"<<c->tope()<<endl;
   cout<<c->imprimir(" >>>")<<endl;
    
   c->encolar(44);
  c->encolar(55);
    cout<<"en cola:"<<c->tope()<<endl;
   cout<<c->imprimir(" >>>")<<endl;
   if(!c->colavacia())c->desencolar();
   cout<<c->imprimir(" >>>")<<endl;
    if(!c->colavacia())c->desencolar();
    cout<<c->imprimir(" >>>")<<endl;
    if(!c->colavacia())c->desencolar();
    cout<<c->imprimir(" >>>")<<endl;
    
    c->encolar(33);
    c->encolar(32);
    c->encolar(23);
   
    cout<<c->imprimir(" >>>")<<endl;
  if(!c->colavacia())c->desencolar();
    cout<<c->imprimir(" >>>")<<endl;
   
    system("PAUSE");
    return EXIT_SUCCESS;
    
}
/*
class Cola{
      private:
              int Q[MAX];
              int pi,pf;
  public:
      Cola(void);
      ~Cola(void);
      int tope();
      bool colavacia();
      void encolar(int a) ;
      void desencolar();
      int ultimo();
      string imprimir(string s);
};
*/
