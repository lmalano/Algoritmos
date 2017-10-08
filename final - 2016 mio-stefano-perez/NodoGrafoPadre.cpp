#ifndef NodoGrafoPadre_cpp
#define NodoGrafoPadre_cpp

#include "Cola.cpp"
#include <iostream>
#include "Pagina.cpp"




using namespace std;



class NodoGrafoPadre
{
    private:
            int a;
            
            
    public:
           
           
            NodoGrafoPadre()
           {
                a=2;
            }
            
            virtual int getNumeroDeNodo(){};
            virtual Cola<Pagina*>* getPaginasRecibidas(){};
            virtual int getNumeroDePC(){};
            
};


#endif
