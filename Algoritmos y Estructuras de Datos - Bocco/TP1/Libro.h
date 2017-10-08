#include <iostream>
#include <iomanip>


using namespace std;

#ifndef Included_Libro_H
#define Included_Libro_H


class Libro
{
      private:
              string nombre;
                              
      public:
             Libro();
             Libro(string);
             ~Libro();
             
             void setNombre(string);
             string getNombre();
             
             
};


#endif

