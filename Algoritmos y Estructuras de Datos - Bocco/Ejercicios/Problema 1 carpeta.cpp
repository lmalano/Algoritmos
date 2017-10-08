#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

class Fecha
{
public:
      Fecha(int=0,int=0,int=0); //constructor
      ~Fecha(); //destructor

//SETERS
      void setFecha(int,int,int);
      void setDia(int);
      void setMes(int);
      void setAnio(int);
//GETERS
      int getDia();
      int getMes();
      int getAnio();
//IMPRIMIR
      void imprimir();
//OTROS
      int enDias();
private:
      int dia;
      int mes;
      int anio;
      
};
Fecha::Fecha(int d,int m,int a)//inicializa constructor // ¿SIEMPRE ES OBLIGATORIO INICIALIZAR EL CONSTRUCTOR ASI?
{
     setFecha(d,m,a);
}
Fecha::~Fecha(){} //¿ES NECESARIO INICIALIZAR EL DESTRUCTOR?

void Fecha::setFecha(int d,int m, int a)
{
     setDia(d);
     setMes(m);
     setAnio(a);
}
void Fecha::setDia(int d)
{
     if(d>31||d<1){cout<<"Dia invalido\n";}
     else{dia=d;}
}
void Fecha::setMes(int m)
{
     if(m>12||m<1){cout<<"Mes invalido\n";}
     else{mes=m;}
}
void Fecha::setAnio(int a)
{
     anio=a;
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
void Fecha::imprimir()
{
     cout<<setfill('0')<<setw(2)<< dia <<"/"<<setfill('0')<<setw(2)<< mes <<"/"<< anio <<"\n\n";
     cout<<"La fecha en dias es "<<enDias()<<"\n\n";
}
int Fecha::enDias()
{
     int d,m,a,s;
     a = (2013 - getAnio())*365;
     m = getMes()*31;
     d = getDia();
     s=a+m+d;
     return s;
}
int main ()
{
    Fecha fecha(25,7,1992);
    Fecha fecha2(20,7,1992);
    Fecha antigua(0,0,0);
    fecha.imprimir();
    fecha2.imprimir();
    if(fecha.enDias()<fecha2.enDias()){antigua = fecha2;}
    else{antigua = fecha;}
    cout<<"Fecha mas antigua: ";
    antigua.imprimir();
    
    system("PAUSE");

    return 0;
}


