#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;
#include "Fecha.h"
//METODOS DE FECHA
//Geters
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
//Seters
void Fecha::setFecha(int d,int m,int a)
{
     setDia(d);
     setMes(m);
     setAnio(a);
}
void Fecha::setDia(int d)
{
     dia=d;
}
void Fecha::setMes(int m)
{
     mes=m;
}
void Fecha::setAnio(int a)
{
     anio=a;
}
//Otros
bool Fecha::esMayor(Fecha f)
{
     return (anio>f.getAnio() ||
             anio==f.getAnio() && mes>f.getMes() ||
             anio==f.getAnio() && mes==f.getMes() && dia>f.getDia());
}
void Fecha::imprimir()
{
     cout<<setfill('0')<<setw(2)<<dia<<"/"<<setfill('0')<<setw(2)<<mes<<"/"<<anio<<"\n";
}
