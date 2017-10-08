#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Examen.h"

Examen::Examen(  ) 
{ 
   cout<<"\n soy el constructor de Examen\n";
} // fin del constructor Examen
Examen::Examen( Fecha f, Materia m, Alumno a,int n  ) 
{ 
   setExamen(f,m,a,n);
   cout<<"\n soy el constructor de Examen\n";
} // fin del constructor Examen
Examen::~Examen()
{ cout<<"\n soy el destructor de Examen";
}

void Examen::setExamen( Fecha f, Materia m, Alumno a,int n ) 
{ 
   setFecha( f );
   setMateria( m );
   setAlumno( a );
   setNota( n );
} 

void Examen::setFecha( Fecha f ) 
{
   fecha = f; 

} 

void Examen::setMateria( Materia m )
{ 
   materia = m; 

} 

void Examen::setAlumno( Alumno a )
{ 
   alumno = a; 

} 

void Examen::setNota( int n ) 
{
   nota = ( n > 0 && n < 10 ) ? n : 0; ; 

} 

Fecha Examen::getFecha() 
{ 
   return fecha; 

} 

Materia Examen::getMateria() 
{
   return materia; 
} 

Alumno Examen::getAlumno() 
{
   return alumno; 
} 


int Examen::getNota() 
{ 
   return nota; 

} 

string Examen::asString()
{
   std::ostringstream s;
   s << materia.asString()  << " - "
     << fecha.asString() << " - "
     << alumno.asString() << " - "
     << nota ;
   return s.str(); 

} 

void Examen::imprime()
{
   cout << asString() << endl;

} 

