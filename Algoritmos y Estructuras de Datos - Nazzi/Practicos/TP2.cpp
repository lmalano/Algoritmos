#include <iostream>
using namespace std;
int posicion(char oracion[],int pos,int posActual,int posMax,int largoactual,int largoMax);

int posicion(char oracion[],int posPalabra,int posActual,int posMax,int largoactual,int largoMax)
{ if (oracion[posActual]==NULL)
{if (largoactual>largoMax)
return posPalabra;
     else
     return posMax;}
    
    else
    {if (oracion[posActual]==' ')
     {  if (largoactual>largoMax)
    {return posicion(oracion,posActual+1,posActual+1,posPalabra,0,largoactual);}
      
       else
    { return posicion(oracion,posActual+1,posActual+1,posMax,0,largoMax);}
}
    else
    {return posicion(oracion,posPalabra,posActual+1,posMax,largoactual+1,largoMax);}
    }}
    
main()
{char c[]={"hol hola hola"};
cout<<posicion(c,0,0,0,0,0)<<endl;
system("pause");
      
      
      
      }
