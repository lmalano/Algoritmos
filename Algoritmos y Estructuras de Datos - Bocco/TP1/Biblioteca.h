#include <iostream>
#include <iomanip>
#include <sstream>

#define MAX_LIBROS 10
#define MAX_AFILIADOS 10
using namespace std;

#include "Afiliado.h"
#include "Fecha.h"
#include "Libro.h"

class Biblioteca
{
      private:
              Libro libros[MAX_LIBROS];
              Afiliado afiliados[MAX_AFILIADOS];
              Fecha fechaActual;
              int contadorLib;
              int contadorAfil;
              
      public :
                 //Constructor
             Biblioteca(int,int,int);
              ~Biblioteca();    //Destructor
              
             void agregarLibro(Libro);
             void agregarAfiliado(Afiliado);
             void cambiarFechaActual(int,int,int);
             void pasaDia();
             int buscarAfiliado(string);
             int buscarLibro(string);
             void extraerLibro(int , int);
             void entregarLibro(string , string );
             void recibirLibro(string, string);
            void imprimirAfiliados();
            void imprimirLibros();
             
             void consultarLibrosDeAfiliado(string);
             int getCantDeLibros();
};   // fin de la clase biblioteca             
             







