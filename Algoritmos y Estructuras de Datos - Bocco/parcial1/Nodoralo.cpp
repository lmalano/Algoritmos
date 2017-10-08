#include<cstdlib>
#include<iomanip>
#include<iostream>

using namespace std;


#include "Nodoralo.h"


Nodoralo::Nodoralo() 
{
    der=NULL;
    inf=NULL;
}

Nodoralo::Nodoralo(int a, int i, int j) 
{
     der=NULL;
     inf=NULL;
     dato=a;
     fil = i;
     col= j;
     //cout<<"NODO RALO "<<i<<j<<a<<" CREADO CON EXITO"<<endl;  
}

void Nodoralo::set_fil(int i)
 {
     fil = i;
 }
 
void Nodoralo::set_col(int j)
{
     col = j;
}

void Nodoralo::set_dato(int a) 
{
     dato=a; 
}

void Nodoralo::set_der(Nodoralo *n) 
{
     der=n;
}

void Nodoralo::set_inf(Nodoralo *n)
{
     inf=n;
}

int Nodoralo::get_dato() 
{
    return dato; 
}

int Nodoralo::get_fil()
{
    return fil;
} 

int Nodoralo::get_col()
{
    return col;
}

Nodoralo* Nodoralo::get_der() 
{
    return der;
}

Nodoralo* Nodoralo::get_inf() 
{
    return inf; 
}


