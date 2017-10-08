#include<iostream>
#include<iomanip>
#include<string.h>


using namespace std;

#include "Afiliado.h"

//METODOS DE AFILIADO
Afiliado::Afiliado()
{                     setNombre("nada");   
                     condicion = false;
                     cantidad = 0;
                     fechaPrimeraExtraccion.setFecha(0,0,0);
                     libroNulo.setNombre("nada");
}
                     
 Afiliado::Afiliado(string name)
 {
                     setNombre(name);   
                     condicion = false;
                     cantidad = 0;
                     fechaPrimeraExtraccion.setFecha(0,0,0);
                     libroNulo.setNombre("nada");
                    
 }
 
 Afiliado::~Afiliado()
 {}
 
 
 //devuelve el nombre del afiliado.
 string Afiliado::getNombre()
 {
        return nombre;
 }
 
 
 bool Afiliado::getCondicion()
 {
      return condicion;
 }
 
 
 // devuelve la cantidad de libros que tiene el afiliado. 
 int Afiliado::getCantidad()
 {
     return cantidad;
 }
 
 
 
 //cambia el nombre del afiliado. 
 void Afiliado::setNombre(string nom)
 {
      nombre = nom;
 }
 
void Afiliado::cambiarCondicion(bool c)
{
     condicion = c;
}
 
 
 
 
 //controla la condicion del afiliado, y devuelve la condicion
 bool Afiliado::controlDeCondicion(Fecha fecActu)
 {
      if (cantidad == MAX_LIBRO_X_AFIL)                    // primero controla que el afiliado no tenga mas de 3 libros
      {
          condicion = false;
          cout << ("Ud. no puede sacar mas de tres libros.") << endl;
         
          
      }
      else
      {
          controlFechas(fecActu)  ;          //   
      }
      
      return condicion;
 }
 
 
 
 
 
 //agrega un libro al afiliado que se saco de la biblioteca. 
 
 void Afiliado::agregarLibro(Libro libro, Fecha fechaActual)
 {
         for(int i=0;i<MAX_LIBRO_X_AFIL;i++)
             {
             if(mis_libros[i].getNombre() == "nada")
                {
                             
                  mis_libros[i]=libro;
                                             
                  if(cantidad == 0)
                     {
                       fechaPrimeraExtraccion = fechaActual;
                     
                     }
                  cantidad++;
                  i = 5;
                }
                   
             }
          
}

 
 
 
 //controla que las fechas de los libros que tiene el afiliado, no haya superado los 7 dias. 
 // Si es asi lo deshabilita al afiliado.
 /*void Afiliado::controlFechas(Fecha fechaActual)
 {
      
          
          if (fechaPrimeraExtraccion.getDia() == 0 && fechaPrimeraExtraccion.getAnio() == 0 && fechaPrimeraExtraccion.getMes() ==0)                 
          {                                               //si la fecha del libro es 0/0/0, entonces es un libro nulo 
          }
          else 
          {
             
               int difeDias = 0;         // lleva la cuenta de la diferencia de dias entre la fecha actual y la fecha de extraccion
          
               while(fechaActual.getDia() != fechaPrimeraExtraccion.getDia() ||                 //se va sumando dias a la fecha de extraccion, hasta que las dos fechas sean iguales
               fechaActual.getMes() != fechaPrimeraExtraccion.getMes() || 
               fechaActual.getAnio() != fechaPrimeraExtraccion.getAnio())
               {
                     fechaPrimeraExtraccion.incrementaUnDia();                
                     difeDias++;         
               }
               
               
               
               if(difeDias > 7)                            // si la diferencia de dias es mayor a 7, se deshabilita al afiliado
               {
                     condicion = false;
                     cout << ("Ud esta deshabilitado, debe devolver los libros que tiene.") << endl;
                     
               } 
          }
      
 }*/
  void Afiliado::controlFechas(Fecha f)
 {
      
          
          if (fechaPrimeraExtraccion.getDia() == 0 && fechaPrimeraExtraccion.getAnio() == 0 && fechaPrimeraExtraccion.getMes() ==0)                 
          {                                               //si la fecha del libro es 0/0/0, entonces es un libro nulo 
          }
          else 
          {
             
               int difeDias = 0;         // lleva la cuenta de la diferencia de dias entre la fecha actual y la fecha de extraccion
          
               difeDias=f.aDias()- fechaPrimeraExtraccion.aDias();
                              
               
               if(difeDias > 7)                            // si la diferencia de dias es mayor a 7, se deshabilita al afiliado
               {
                     condicion = false;
                     cout << ("Ud esta deshabilitado, debe devolver los libros que tiene.") << endl;
                     
               } 
          }
      
 }


//Entrega un libro, ingresando el nombre del libro que se quiere devolver. 
Libro Afiliado::entregaLibro(string nameBook)
{
      
      int ubicaLibro = buscaLibro(nameBook); 
      if (ubicaLibro == -1)
      {
                     cout << "Ud no tiene ese libro.";
                     return libroNulo;            // tienes que definir el libro nulo en algun lugar
      }
      else
      {
          Libro lib = mis_libros[ubicaLibro];
          mis_libros[ubicaLibro] = libroNulo;
          cantidad = cantidad -1;
          if (cantidad = 0)
          {
                  fechaPrimeraExtraccion.setFecha(0,0,0);
          }
          return lib;
      }
  
}
 
 //busca un libro por su nombre en la lista de libros. 
int Afiliado::buscaLibro(string nombre)
{
    for(int i = 0;i <MAX_LIBRO_X_AFIL; i++  )
    {
            if(nombre == mis_libros[i].getNombre())
            {
                    return (i);
            }
    }
    return (-1);
} 

 
 
void Afiliado::imprimirFechaExtraccion()
{
     fechaPrimeraExtraccion.imprime();
}


void Afiliado::imprimirMisLibros()
{
     for(int i=0; i<MAX_LIBRO_X_AFIL; i++ )
     {
              cout << ("Libro: ")  << mis_libros[i].getNombre() << endl;
     } 
}
