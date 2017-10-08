#include <cstdlib>
#include <iostream>

using namespace std;


#include "Biblioteca.h"


int main()
{
/* Fecha f;
    
    f.imprime();
  */
   
    
     /* 
     //af.setNombre("ahora no");
     //cout << ("nombre : ") << af.getNombre() << endl;
     //cout << ("condicion: ") << af.getCondicion()<< endl;
     af.agregarLibro(l,f); 
     cout <<( "cantidad: ")<< af.getCantidad() << endl; 
    
    */
    Fecha fe(4,3,2014);
    
    /*fe.imprime();
    cout << endl;
    af.imprimirFechaExtraccion();
    af.cambiarCondicion(true);
     cout << ("luego de controlar la condicion: ") << af.controlDeCondicion(fe) << endl;
     
     
  
    */
    
    Libro l0("Harry Potter");
    Libro l1("Los picapiedras");
    Libro l2("El señor de los anillos");
    Libro l3("Fisica I - Fisica general");
    Libro l4("Fisica II - Electromagnetismo");
    Libro l5("Fisica III - Fisica cuantica");
    Libro l6("El protocolo sigma");
    Libro l7("En el blanco");
    Libro l8("La dama de noche");
    Libro l9("Angeles y demonios");
    
    
    
    Biblioteca biblio(2,3,2014);
    biblio.cambiarFechaActual(2,3,2014);
    
    
    biblio.agregarLibro(l0);
    biblio.agregarLibro(l1);   
    biblio.agregarLibro(l2);
    biblio.agregarLibro(l3); 
    biblio.agregarLibro(l4);
    biblio.agregarLibro(l5);
    biblio.agregarLibro(l6);
    biblio.agregarLibro(l7);
    biblio.agregarLibro(l8);
    biblio.agregarLibro(l9);

    
    cout<<"                       **** BIENVENIDO A LA BIBLIOTECA ****"<<endl<<endl;

    Afiliado af("Martin");  //Crea tres afiliados
    Afiliado af2("Juan");
    Afiliado af3("Nahuel");
    biblio.agregarAfiliado(af); //Agrega los afiliados a la biblioteca
    biblio.agregarAfiliado(af2);
    biblio.agregarAfiliado(af3);
    cout<<endl;


     cout<<"Libros de Martin"<<endl;  //Muestra los libros que tienen cada uno (en este caso ninguno porque aun no han buscado libros)
     biblio.consultarLibrosDeAfiliado("Martin");
     cout<<endl;
     cout<<"Libros de Juan"<<endl;
     biblio.consultarLibrosDeAfiliado("Juan");
     cout<<endl;
     cout<<"Libros de Nahuel"<<endl;
     biblio.consultarLibrosDeAfiliado("Nahuel");
     cout<<endl;
     
     
     cout << endl << "Lista de libros:" << endl;  //Muestra la lista de libros disponibles en la biblioteca
     biblio.imprimirLibros();
     
     
     biblio.entregarLibro("Harry Potter","Martin");  //Se le entregan algunos libros a los usuarios
     biblio.entregarLibro("La dama de noche","Juan");
     biblio.entregarLibro("En el blanco","Nahuel");
     cout<<endl;
     
     
     cout<<"Libros de Martin"<<endl;   //Se vuelven a imprimir los libros de cada afiliado
     biblio.consultarLibrosDeAfiliado("Martin");
     cout<<endl;
     cout<<"Libros de Juan"<<endl;
     biblio.consultarLibrosDeAfiliado("Juan");
     cout<<endl;
     cout<<"Libros de Nahuel"<<endl;
     biblio.consultarLibrosDeAfiliado("Nahuel");
     cout<<endl;
     
     
     biblio.cambiarFechaActual(6,3,2014);      //Se cambia la fecha actual y se comienzan a devolver algunos libros
     biblio.recibirLibro("Martin", "Harry Potter");    //Martin devuelve el libro antes de los 7 dias
     biblio.cambiarFechaActual(7,3,2014);                     //Juan devuelve el libro antes de los 7 dias y decide llevarse otro
     biblio.recibirLibro("Juan", "La dama de noche");      //Nahuel se olvida de devolver el libro y queda inhabilitado a retirar otro libro
     biblio.entregarLibro("Harry Potter","Juan");
     cout<<"Libros de Juan"<<endl;
     biblio.consultarLibrosDeAfiliado("Juan");
      
     biblio.cambiarFechaActual(10,3,2014);
     biblio.entregarLibro("Los picapiedras","Nahuel");
     
     
     

     
      
    system("PAUSE");
    return EXIT_SUCCESS;
}
