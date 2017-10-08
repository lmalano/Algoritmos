#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Fecha.h"

Fecha::Fecha( int d, int m, int a ) 
{ 
   cout<<"\n soy el constructor\n";
   setFecha( d, m, a ); 

} // fin del constructor Fecha
Fecha::~Fecha()
{ cout<<"\n soy el destructor ------------";
}

void Fecha::setFecha( int d, int m, int a ) 
{ 
   setDia( d );
   setMes( m );
   setAnio( a );
} 

void Fecha::setDia( int d ) 
{
   dia = ( d > 0 && d < 31 ) ? d : 0; 

} 

void Fecha::setMes( int m )
{ 
   mes = ( m > 0 && m <= 12 ) ? m : 0; 

} 

void Fecha::setAnio( int a )
{ 
   anio =  a ; 

} 

int Fecha::getDia() 
{ 
   return dia; 

} 

int Fecha::getMes() 
{
   return mes; 
} 

int Fecha::getAnio() 
{ 
   return anio; 
} 

bool Fecha::esMayor(Fecha f) 
{ 
   return (anio>f.getAnio()) ||
          (anio==f.getAnio() && mes>f.getMes()) ||
          (anio==f.getAnio() && mes==f.getMes() && dia>f.getDia())    ;  
} 

string Fecha::asString()
{ 
   std::ostringstream s;
   s << setfill( '0' ) << setw( 2 ) << dia << "/"
        << setw( 2 ) << mes << "/"
        << setw( 4 ) << anio;
   return s.str(); 
} 


void Fecha::imprime()
{
   cout << asString() << endl;

} 




