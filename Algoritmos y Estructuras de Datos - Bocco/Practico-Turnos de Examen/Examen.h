#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

#include "Fecha.h"
#include "Materia.h"
#include "Alumno.h"

class Examen {

public:
   Examen() ;
   Examen(Fecha, Materia, Alumno, int ) ; 
   ~Examen(); // destructor predeterminado
   void setExamen( Fecha, Materia, Alumno, int ); 
   void setFecha( Fecha ); 
   void setMateria( Materia );   
   void setAlumno( Alumno );  
   void setNota( int );  

   Fecha   getFecha();  
   Materia getMateria();  
   Alumno  getAlumno();  
   int  getNota();  

   string asString();
   void imprime();         // imprime la hora en formato universal
private:
   Fecha fecha;   
   Materia materia;   
   Alumno alumno;
   int nota;

}; // fin de la clase Examen

