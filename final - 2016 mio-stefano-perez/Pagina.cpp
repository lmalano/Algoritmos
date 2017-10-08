#include <cstdlib>
#include <iostream>
//#include "NodoGrafo.cpp"

using namespace std;

#ifndef Pagina_cpp
#define Pagina_cpp

#include <iostream>
#include "Lista.cpp"
#include "Cola.cpp"
#include <sstream>

class Pagina
{
    private: 
             int routerOrigen;
             int routerDestino;
             int pcOrigen;
             int pcDestino;
             int peso;
             string nombre;
             int numeroDePagina;
             Cola<char>* mensaje;
             
             //NodoGrafo* a; puede ser tmb un int sin problemas pero de la pc desde la q viene
             
    public:
             Pagina(int peso, int routerOrigen,int routerDestino, int pcOrigen, int pcDestino,int numeroDePagina,Cola<char>* mensaje)
             {
                 this->routerDestino=routerDestino;
                 this->pcDestino=pcDestino;
                 this->peso=peso;
                 this->pcOrigen=pcOrigen;
                 this->numeroDePagina=numeroDePagina;
                 this->routerOrigen=routerOrigen;
                 nombre="pag_";
                 
                 stringstream s;
                 s<<getPcOrigen();
                 
                 nombre+=s.str();
                 nombre+="_";
                 s.str("");
                 s<<getNumeroDePagina();
                 nombre+=s.str();
                 
                 this->mensaje=mensaje;
 
             }
             Cola<char>* getMensaje(){return mensaje;}
             
             void generarMensaje(){};
             
             string getNombre(){return nombre;}
             
             void setPcOrigen(int nom){pcOrigen=nom;}
             int getPcOrigen(){return pcOrigen;}
             
             void setNumeroDePagina(int numeroDePagina){this->numeroDePagina=numeroDePagina;}
             int getNumeroDePagina(){return numeroDePagina;}
             
             void setRouterOrigen(int a){routerOrigen=a;}
             int getRouterOrigen(){return routerOrigen;}
             
             
             void setRouterDestino(int a){routerDestino=a;}
             int getRouterDestino(){return routerDestino;}
             
             void setPcDestino(int a){pcDestino=a;}
             int getPcDestino(){return pcDestino;}
             
             
             int getPeso(){return peso;}
             
             void toPrint()
             {
                  cout<<nombre<<endl;
              }
              
              void imprimirPagina()
              {
                   if(this!=NULL)
                   {
                       cout<<"imprimiendo la pagina!!!!";
                       cout<<endl<<getNombre()<<"  Con un peso de "<<getPeso()<<":  ";
                       for (int i=0;i<mensaje->getCantidadDeDatos();i++)
                       {
                           cout<<getMensaje()->getNodo(i)->getDato();//fiajte que si pones solamente get q devolveria el char hay un problemon!!!
                       }
                       cout<<endl<<endl;
                   }
                   else
                   {
                       cout<<"La pagina es NULL no se puede imprimir"<<endl;
                   }
               }
               
               
               
               void ordenarPagina()
                {
                     int iMax=0;
                     Cola<char>* cola=getMensaje();
                     
                     //for(int z=0;z<cola->getCantidadDeDatos();z++)
                     for(int i=0;i<cola->getCantidadDeDatos()-1;i++)
                     {
                             iMax=0;
                     
                             for (int j=i+1;j<cola->getCantidadDeDatos();j++)
                             {
                                 int aa=cola->getNodo(i)->getDato();
                                 int bb=cola->getNodo(j)->getDato();
                                 if(bb <= aa)
                                 {
                                     iMax=j;
                                     char a=cola->getNodo(i)->getDato();
                                     char b=cola->getNodo(iMax)->getDato();
                                     cola->getNodo(i)->set_dato(b);
                                     cola->getNodo(iMax)->set_dato(a);
                                 }
                                 
                             }
                             
                             
                             
                 }
                }
               
             
             
};

/*
int main()
{
    
    
    system("PAUSE");
}
*/
#endif
