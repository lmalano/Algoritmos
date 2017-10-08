#include <cstdlib>
#include <iostream> 
#include <sstream>

using namespace std;

#include "Lista.h"
#include "Nodo.h"
#include "Nodoralo.h"

#ifndef Included_Matrizrala_H
#define Included_Matrizrala_H

class Matrizrala
{ 
      private: 
               int rango;
               Lista *acces_fila;
               Lista *acces_colum; 
      public: 
               
               Matrizrala (int );
               void add_Nodoralo(int , int , int ); 
               Nodo* buscarNodo(Lista* , int ); 
               void apuntar(Lista* , Nodoralo* ,int ); 
               int buscarNodoralo(int , int ); 
               void recibirDatos(FILE*);
               void imprimirMatriz2();
               void imprimirMatriz();
               void devolverNodos();
               int getRango();
}; 
#endif
