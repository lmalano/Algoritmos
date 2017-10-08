#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Turno.h"

Turno::Turno(  ) 
{ 
   last=-1;
   cout<<"\n soy el constructor de Turno\n";
} // fin del constructor Turno
Turno::~Turno()
{ cout<<"\n soy el destructor de Turno";
}

void Turno::addExamen( Examen e) 
{ 
   if (last<MAX_EXA-1) {
      last++;
      exs[last]=e;
   }
} 

int Turno::lastPos( ) 
{ 
   return last;
} 

Examen Turno::getExamen( int pos) 
{ 
   if (pos<=MAX_EXA) {
      return exs[pos];
   }
} 

string Turno::asString()
{ 
   int i;
   std::ostringstream s;
   
   for (i=0;i<=last;i++){
      s << exs[i].asString() << endl ;
   }
   return s.str(); 
} 

void Turno::imprime()
{ 
   cout << endl <<
           asString() << endl;

} 

Examen Turno::bestExamen( ) 
{ 
   int b;int i;
   int n=-1;
   for (i=0;i<=last;i++){
       if(exs[i].getNota()>n){
          n=exs[i].getNota();
          b=i;
       }
   }
   return exs[b];
} 

Examen Turno::lastExamen( ) 
{ 
   int b;int i;
   Fecha f;
   f.setFecha(1,1,1900);
   for (i=0;i<=last;i++){
       if(exs[i].getFecha().esMayor(f)){
          f=exs[i].getFecha();
          b=i;
       }
   }
   return exs[b];
} 

