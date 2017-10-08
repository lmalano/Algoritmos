#include<cstdlib>
#include<iomanip>
#include<iostream>

using namespace std;


#include "Fecha.h"

//METODOS DE FECHA
Fecha::Fecha()
{
              dia = 0;
              mes = 0;
              anio = 0;
}

Fecha::Fecha(int d, int m, int an)
{
                 setFecha(d, m, an);
}

Fecha::~Fecha()
{}

// devuelve el dia 
int Fecha::getDia()
{
    return dia;
}

//devuelve el mes
int Fecha::getMes()
{
    return mes;
}

//devuelve el año.
int Fecha::getAnio()
{
    return anio;
}

//cambia la fecha
void Fecha::setFecha(int d,int m,int a)
{
     setDia(d);
     setMes(m);
     setAnio(a);
}

//cambia el dia
void Fecha::setDia(int d)
{
     if (0 <= d <= 30)
     {
           dia =d;
     }
     else
     { dia = 0;
     }
}

//cambia el mes
void Fecha::setMes(int m)
{
      if (0 <= m <= 12)
     {
           mes = m;
     }
     else
     { mes = 0;
     }
     
}


//cambia el año
void Fecha::setAnio(int a)
{
     anio=a;
}

//hace que pase un dia. 
void Fecha::incrementaUnDia()
{   
    
      dia = ((dia+1) % 31 );  //Suponemos que todos los meses tienen 30 dias. 

      if ( getDia() == 0 )
         {
                  mes = ( mes++  ) % 13 ;
         }

      if(getMes() == 0) 
      {
                anio = anio++;
      }
  

} 


void Fecha::imprime()
{
     cout<< "dia:" << dia << endl;
     cout<< "mes:" << mes << endl;
     cout<< "anio:" << anio << endl;
     
}
int Fecha::aDias()
{
    int a,b,c;
    a=getAnio()*365;
    if(getMes()==1||getMes()==3||getMes()==5||getMes()==7||getMes()==8||getMes()==10||getMes()==12)
    {b=getMes()*31;}
    if(getMes()==4||getMes()==6||getMes()==9||getMes()==11)
    {b=getMes()*30;}
    if(getMes()==2)
    {b=getMes()*28;}
    c=getDia();
    return a+b+c;
}
