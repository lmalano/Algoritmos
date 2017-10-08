#include <cstdlib>
#include <iostream>
//#include "NodoGrafo.cpp"

using namespace std;

#ifndef Paquete_cpp
#define Paquete_cpp

#include <sstream>

class Paquete
{
    private: 
             char letra;
             int routerOrigen;
             int pcOrigen;
             int pcDestino;
             int peso;
             string nombre;
             int parte;
             int numeroDePagina;
             int routerDestino;
             int cantidadDePaquetesTotal;
             string prefijo;//no tiene q ser un entero, tiene q ser una direccion de memoria a un NodoGrafo fijate ocmo lo pones... 
             //NodoGrafo* a; puede ser tmb un int sin problemas pero de la pc desde la q viene
             
    public:
             Paquete(int peso, int parte, int routerOrigen,int routerDestino, int pcOrigen, int pcDestino ,int cantidadDePaquetesTotal,char letra, int numeroDePagina)
             {
                 this->letra=letra;
                 this->routerDestino=routerDestino;
                 this->pcDestino=pcDestino;
                 this->peso=peso;
                 this->parte=parte;
                 this->pcOrigen=pcOrigen;
                 this->cantidadDePaquetesTotal=cantidadDePaquetesTotal;
                 this->routerOrigen=routerOrigen;
                 this->numeroDePagina=numeroDePagina;
                 prefijo="pag_";
                 
                 stringstream s;
                 s<<getPcOrigen();
                 
                 prefijo+=s.str();
                 prefijo+="_";
                 
                 s.str("");
                 s<<getNumeroDePagina();
                 prefijo+=s.str();
                 
                 cout<<"El nombre del pquete essss.:::   "<<prefijo<<endl;
                 
                 nombre="";
                 
                 
                 nombre+=prefijo;
                 nombre+="_parte_";
                 
                 s.str("");
                 s<<getParte();
                 nombre+=s.str();
                 
                 nombre+=".rar";
 
             }
             
             int getParte(){return parte;}
             
             int getCantidadDePaquetesTotal(){return cantidadDePaquetesTotal;}
             
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
                  cout<<"nombre paquete: "<<nombre<<",  Peso paq: "<<peso<<", Parte: "<<parte<<endl;
              }
             
             void imprimirPaquete()
             {
                  cout<<nombre<<"   contiene el caracter:  "<<letra<<endl<<"Con un peso total de: "<<getCantidadDePaquetesTotal();
              }
              
              string getNombre(){return nombre;}
             
             string getPrefijo(){return prefijo;}
             char getLetra(){return letra;}
             
};

/*
int main()
{
    
    
    system("PAUSE");
}
*/
#endif
