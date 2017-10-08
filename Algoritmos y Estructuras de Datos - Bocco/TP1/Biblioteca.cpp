#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Biblioteca.h"


 
 
Biblioteca::Biblioteca(int d, int m, int a)
{
       fechaActual.setFecha(d,m,a);
       contadorLib = 0;
       contadorAfil = 0;         
}
                          
Biblioteca::~Biblioteca()
{
        
} 

int Biblioteca::getCantDeLibros()
{
    return contadorLib;
}


//Cambia la fecha Actual
void Biblioteca::cambiarFechaActual(int d, int m, int a)
{
     fechaActual.setFecha(d,m,a);
}


//hace que pase un dia. 
void Biblioteca::pasaDia()
{
     fechaActual.incrementaUnDia(); 
}

//Agrega un libro a la biblioteca                        
void Biblioteca::agregarLibro(Libro book)
{
     int ubicacion= buscarLibro("nada");
     if(ubicacion!= -1)
     {
                    libros[ubicacion] = book;
                     contadorLib++;
     }
     else
     {
         cout << "no hay mas lugar en la biblioteca." << endl;
     } 
}
    
void Biblioteca::imprimirAfiliados()
{
     for(int i=0; i<MAX_AFILIADOS; i++ )
     {
              cout << ("Socio ") << i  << (" : ") << afiliados[i].getNombre() << endl;
     }
}

void Biblioteca::imprimirLibros()
{
     for(int i=0; i<MAX_LIBROS; i++ )
     {
              cout << ("Libro: ")  << libros[i].getNombre() << endl;
     } 
}
    
    
//Agrega un afiliado a la biblioteca. Cuando se lo agrega se le cambia el estado a habilitado.
void Biblioteca::agregarAfiliado (Afiliado afil)
{
     int ubicacion = buscarAfiliado("nada");
     if (ubicacion !=  -1)
     {
        afiliados[contadorAfil] = afil;
        afiliados[contadorAfil].cambiarCondicion(true);//
        contadorAfil++;
     } 
     else
     {
         cout << "Ya no hay cupos para inscribirse." << endl;
     }
} 




//Entrega un libro a un afiliado si este esta en condiciones. 
void Biblioteca::entregarLibro(string nombreLibro, string nombreAfil)
{
     int ubicaLibro = buscarLibro(nombreLibro);
     int ubicaAfi = buscarAfiliado(nombreAfil);
     
     if(ubicaLibro == (-1))                 // controla que el libro se encuentre en la biblioteca.
     {
                   cout << ("El libro no se encuentra en el registro") << endl;
     } 
     else
     {
         if (ubicaAfi == (-1))                                   //controla que la persona este afiliada
         {
                      cout <<("Ud no esta afiliado a esta biblioteca.") << endl;
         }
         else
         {
            if ((afiliados[ubicaAfi].controlDeCondicion(fechaActual)) != true)                   //Controla la condicion del afiliado                     
            {       
                                                          
            }
            else 
            {
                 extraerLibro(ubicaLibro, ubicaAfi);           // Se saca el libro de la biblioteca y se lo entrega al afiliado
            }
         }
     }
}

//se entrega el libro a afiliado y se lo saca del registro y 
void Biblioteca::extraerLibro(int ubicaLibro, int ubicaAfil)
{
     afiliados[ubicaAfil].agregarLibro(libros[ubicaLibro], fechaActual);
     
     libros[ubicaLibro].setNombre("nada");
     contadorLib = contadorLib -1;
     
}

//Busca la ubiacion de un libro, ingresando el nombre del libro que desee.
int Biblioteca::buscarLibro(string name)
{
    for(int i = 0;i < MAX_LIBROS; i++  )
    {
            if(name == libros[i].getNombre())
            {
                    return (i);
            }
    }
    return (-1);
}


//Busca la ubiacion de un Afiliado, ingresando el nombre del afiliado.
int Biblioteca::buscarAfiliado(string name)
{
    for(int i =0 ;i < MAX_AFILIADOS; i++  )
    {
            if(name == afiliados[i].getNombre())
            {
                    return (i);
            }
    }
    return (-1);
}


// recibe el libro de un afiliado. 
void Biblioteca::recibirLibro(string nombreAfil, string nombreLib)
{
     int ubiAfil = buscarAfiliado(nombreAfil);                       
     int espacioLibre = buscarLibro("nada"); 
     
     if (ubiAfil == -1)                          // verifica que este afiliado
     {
                 cout <<("Ud no esta afiliado");
     }
     else                                   
     {
          if (espacioLibre == -1)                                 // verifica que haya espacio en la biblioteca
          {
                      cout << "No hay mas espacio en la biblioteca.";
          }
          else 
          {
             libros[espacioLibre] = afiliados[ubiAfil].entregaLibro(nombreLib);           // recibe el libro del afiliado
             contadorLib++;                              // suma uno a contador de libros. 
          }
     }   

} 


void Biblioteca::consultarLibrosDeAfiliado(string nombreAfil)
{
     int ubicacion = buscarAfiliado(nombreAfil);
     afiliados[ubicacion].imprimirMisLibros();
}
