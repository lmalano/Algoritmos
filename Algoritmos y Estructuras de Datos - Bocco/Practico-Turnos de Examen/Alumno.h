#include <iostream>
#include <iomanip>
#include <sstream>

#define RENDIDAS 40

using namespace std;


class Alumno {

public:
   Alumno() ; 
   Alumno(string, int) ; 
   ~Alumno(); // destructor predeterminado
   void setAlumno( string, int ); 
   void setNombre( string );   
   void setLegajo( int );  

   string getNombre();  
   int    getLegajo();  

   string asString();
   void imprime();         // imprime la hora en formato universal
private:
   string nombre;   
   int legajo;   

}; // fin de la clase Alumno

