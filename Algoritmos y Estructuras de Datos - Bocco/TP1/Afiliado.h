#include <iostream>
#include <iomanip>
#include <sstream>


#define MAX_LIBRO_X_AFIL 3

using namespace std;

#include "Fecha.h"
#include "Libro.h"

class Afiliado
{
      private:
              string nombre;
              bool condicion;
              int cantidad;
              Libro libroNulo;
              Fecha fechaPrimeraExtraccion;
              Libro mis_libros[MAX_LIBRO_X_AFIL];
     
      public:
             Afiliado(string);
             Afiliado();
             ~Afiliado();
             
           
             string getNombre();
             int getCantidad();
              
              bool getCondicion();             
             void setNombre(string);
             bool controlDeCondicion(Fecha);
             void agregarLibro(Libro, Fecha);
             void setCantidad(int);
             void controlFechas(Fecha);
             Libro entregaLibro(string );
             int buscaLibro(string );
             void cambiarCondicion(bool);
            
            void imprimirFechaExtraccion() ;  
            void imprimirMisLibros()  ;     
};
