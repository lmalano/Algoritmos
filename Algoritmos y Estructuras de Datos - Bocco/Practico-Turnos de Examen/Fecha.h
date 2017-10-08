#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Fecha {

public:
   Fecha( int = 1, int = 1, int = 2000); // constructor predeterminado
   ~Fecha(); // destructor predeterminado
   // funciones establecer = set
   void setFecha( int, int, int ); 
   void setDia( int );   
   void setMes( int );  // establece mes
   void setAnio( int ); // establece anio

   // funciones obtener = get
   int getDia();  
   int getMes();  
   int getAnio(); 

   bool esMayor(Fecha f);
   string asString();
   void imprime();         // imprime la hora en formato universal
private:
   int dia;   
   int mes;   
   int anio;  

}; // fin de la clase Fecha


