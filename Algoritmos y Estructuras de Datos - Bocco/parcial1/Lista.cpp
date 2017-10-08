#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

#include "Lista.h"


Lista::Lista() {czo = new Nodo();}

Lista::Lista(Nodo* n) {czo=n;}   // con la n como parametro no funciona, lo que hice fue sacarla para que pase como correcto ese error.

void Lista::add(int a)
{  for (int i = 0;  i < a; i++)
  {
     Nodo *nuevo=new Nodo(NULL);
     nuevo->set_next(czo);
     czo=nuevo;
  }
}

Nodo* Lista::cabeza(void)
{ 
  return czo;
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo->get_next());
      return (l);
}

