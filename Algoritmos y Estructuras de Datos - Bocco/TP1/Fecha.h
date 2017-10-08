#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

#ifndef Included_Fecha_H
#define Included_Fecha_H

class Fecha{
private:
              int dia;
              int mes;
              int anio;
public:
             Fecha();
              Fecha(int,int,int);
              ~Fecha();
              
             //Geters
              int getDia();
              int getMes();
              int getAnio();
              //Seters
              void setFecha(int,int,int);
              void setDia(int);
              void setMes(int);
              void setAnio(int);
              //Otros
              int aDias();
              void incrementaUnDia();
              void imprime();
             
            
};

#endif




