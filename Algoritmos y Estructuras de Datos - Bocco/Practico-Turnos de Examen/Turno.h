#include <iostream>
#include <iomanip>
#include <sstream>

#define MAX_EXA 10

using namespace std;

#include "Examen.h"

class Turno {

public:
   Turno() ; // constructor predeterminado
   ~Turno(); // destructor predeterminado
   void addExamen( Examen ); 
   Examen getExamen( int );   
   int lastPos( );   

   string asString();
   void imprime();         // imprime la hora en formato universal
   
   Examen bestExamen( );   
   Examen lastExamen( );   
private:
   int last;   
   Examen exs[MAX_EXA];   

}; // fin de la clase Examen

