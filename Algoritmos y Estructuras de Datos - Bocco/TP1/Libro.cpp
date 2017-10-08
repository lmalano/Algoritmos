#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Libro.h"

Libro::Libro()
{
              nombre = "nada";
              
}

Libro::Libro(string n)
{
       nombre = n;
       
}

Libro::~Libro()
{}


//cambia el nombre del libro
void Libro::setNombre(string name)
{
     nombre = name;
}


//entre el nombre del libro-
string Libro::getNombre()
{
       return nombre;
}


 
