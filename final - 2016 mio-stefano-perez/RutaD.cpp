#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string> 
#include <fstream>
#include <cmath>

#ifndef RutaD_cpp
#define RutaD_cpp

#include "NodoGrafo.cpp"



using namespace std;



// pensalo como una tabla

// desde....hasta.....costo_total
class RutaD
{
      
    private: 
             NodoGrafo* desde;
             NodoGrafo* hasta;
             float costoTotal;
             
               
    public:
             RutaD(){desde=NULL; hasta=NULL; costoTotal=0;}
             RutaD(NodoGrafo* a, NodoGrafo* b, float costo){desde=a; hasta=b; costoTotal=costo;}
             void setDesde(NodoGrafo desde){this->desde=&desde;}
             void setHasta(NodoGrafo hasta){this->hasta=&hasta;}
             void setCostoTotal(int ct){costoTotal=ct;}
             NodoGrafo* getDesde(){return desde;}
             NodoGrafo* getHasta(){return hasta;}
             float getCostoTotal(){return costoTotal;}
             
             void toPrint()
             {
                  cout<<"   "<<desde->getNumeroDeNodo()<<"     "<<hasta->getNumeroDeNodo()<<"     "<<costoTotal<<"    "<<hasta->getFuevisitado()<<endl;
              }
             
            
            
};

#endif
