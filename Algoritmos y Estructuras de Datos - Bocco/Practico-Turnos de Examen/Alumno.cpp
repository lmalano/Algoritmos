#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Alumno.h"

Alumno::Alumno(  ) 
{ 
   cout<<"\n soy el constructor de alumno\n";
} // fin del constructor Alumno
Alumno::Alumno( string n, int l  ) 
{ 
   setAlumno(n,l);
   cout<<"\n soy el constructor de alumno\n";
} // fin del constructor Alumno
Alumno::~Alumno()
{ 
    cout<<"\n soy el destructor de alumno";
}

void Alumno::setAlumno( string n, int l ) 
{ 
   setNombre( n );
   setLegajo( l );
} 

void Alumno::setNombre( string n ) 
{
   nombre = n; 

} 

void Alumno::setLegajo( int l )
{ 
   legajo = l; 

} 

string Alumno::getNombre() 
{ 
   return nombre; 

} 

int Alumno::getLegajo() 
{
   return legajo; 
} 


string Alumno::asString()
{
   std::ostringstream s;
   s << nombre << " - legajo: "
     << setw( 8 ) << legajo;
   return s.str(); 

} 

void Alumno::imprime()
{
   cout << asString() << endl;

} 





