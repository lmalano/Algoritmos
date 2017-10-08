#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Materia.h"

Materia::Materia( ) 
{ 
   cout<<"\n soy el constructor de Materia\n";
} // fin del constructor Materia

Materia::Materia( string n, int c ) 
{ 
   cout<<"\n soy el constructor de Materia\n";
   setMateria(n,c);
} // fin del constructor Materia
Materia::~Materia()
{ cout<<"\n soy el destructor de Materia";
}

void Materia::setMateria( string n, int c ) 
{ 
   setNombre( n );
   setCodigo( c );
} 

void Materia::setNombre( string n ) 
{
   nombre = n; 

} 

void Materia::setCodigo( int c )
{ 
   codigo = c; 

} 

string Materia::getNombre() 
{ 
   return nombre; 

} 

int Materia::getCodigo() 
{
   return codigo; 
} 


string Materia::asString()
{
   std::ostringstream s;
   s << nombre << " - codigo: "
     << setw( 4 ) << codigo;
   return s.str(); 

} 

void Materia::imprime()
{
   cout << asString() << endl;

} 

