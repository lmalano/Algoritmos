// DEITEL pag 439 en adelante
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class Tiempo {

public:
   Tiempo( int = 0, int = 0, int = 0); // constructor predeterminado
   ~Tiempo(); // destructor predeterminado
   
   // funciones establecer = set
   void estableceHora( int, int, int ); // establece hora, minuto, segundo
   void estableceHora1( int );   // establece hora
   void estableceMinuto( int );  // establece minuto
   void estableceSegundo( int ); // establece segundo

   // funciones obtener = get
   int obtieneHora1();        // obtiene hora
   int obtieneMinuto();       // obtiene minuto
   int obtieneSegundo();      // obtiene segundo

   void imprimeUniversal();         // imprime la hora en formato universal
   void imprimeEstandar();          // imprime la hora en formato est�ndar
private:
   int hora;     // 0 - 23 (formato de reloj de 24 horas)
   int minuto;   // 0 - 59
   int segundo;  // 0 - 59

}; // fin de la clase Tiempo

// funci�n constructor para inicializar datos privados;
// llama a la funci�n miembro estableceHora para asignar los variables;
// los valores predeterminados son 0 (vea la definic�n de la clase)
Tiempo::Tiempo( int hr, int min, int seg ) 
{ 
   cout<<"\n soy el constructor\n";
   estableceHora( hr, min, seg ); 

} // fin del constructor Tiempo
Tiempo::~Tiempo()
{ cout<<"\n soy el destructor ------------";
}
// establece los valores de hora, minuto y segundo
void Tiempo::estableceHora( int h, int m, int s ) 
{ 
   estableceHora1( h );
   estableceMinuto( m );
   estableceSegundo( s );

} // fin de la funci�n estableceHora

// establece el valor de hora
void Tiempo::estableceHora1( int h ) 
{
   hora = ( h >= 0 && h < 24 ) ? h : 0; //lo mismo q if(h >= 0 && h < 24); hora=h;

} // fin de la funci�n estableceHora1

// establece el valor de minuto
void Tiempo::estableceMinuto( int m )
{ 
   minuto = ( m >= 0 && m < 60 ) ? m : 0; 

} // fin de la funci�n estableceMinuto

// establece el valor de segundo
void Tiempo::estableceSegundo( int s )
{ 
   segundo = ( s >= 0 && s < 60 ) ? s : 0; 

} // fin de la funci�n estableceSegundo

// devuelve el valor de hora
int Tiempo::obtieneHora1() 
{ 
   return hora; 

} // fin de la funci�n obtieneHora1

// devuelve el valor de minuto 
int Tiempo::obtieneMinuto() 
{
   return minuto; 

} // fin de la funci�n obtieneMinuto

// devuelve el valor de segundo 
int Tiempo::obtieneSegundo() 
{ 
   return segundo;
   
} // fin de la funci�n obtieneSegundo

// imprime Tiempo en formato universal
void Tiempo::imprimeUniversal()
{
   cout << setfill( '0' ) << setw( 2 ) << hora << ":"
        << setw( 2 ) << minuto << ":"
        << setw( 2 ) << segundo;

} // fin de la funci�n imprimeUniversal

// print Time in standard format
// imprime Tiempo en formato est�ndar
void Tiempo::imprimeEstandar()
{
   cout << ( ( hora == 0 || hora == 12 ) ? 12 : hora % 12 )
        << ":" << setfill( '0' ) << setw( 2 ) << minuto
        << ":" << setw( 2 ) << segundo 
        << ( hora < 12 ? " AM" : " PM" );

} // fin de la funcion imprimeEstandar

void incrementaMinutos( Tiempo , const int ); 
 // prototipo

int main(int argc, char *argv[])
{  
    {Tiempo t(14,40,0),x,y(10);  //en x no se pasa parametro(toma lo q tiene x defecto) // y(10) toma para el de la izq   // crea el objeto de Tiempo
      t.imprimeEstandar(); cout<<endl;
      x.imprimeEstandar(); cout<<endl;
      y.imprimeEstandar(); cout<<endl;
  
      //Tiempo *p= new Tiempo(11,11,11);
      //p->imprimeEstandar();cout<<endl;
      
   // establece la hora mediante funciones establece (set) individuales
   t.estableceHora1( 17 );     // establece hora en un valor v�lido
   t.estableceMinuto( 34 );   // establece minuto en un valor v�lido
   t.estableceSegundo( 25 );   // establece segundo en un valor v�lido

   // funciones obtener (get) para obtener hora, minuto y segundo
   cout << "Resultado de establecer todos los valores validos:\n" 
        << "  Hora: " << t.obtieneHora1()
        << "  Minuto: " << t.obtieneMinuto()
        << "  Segundo: " << t.obtieneSegundo();

   // establece hora mediante el uso de funciones individuales
   t.estableceHora1( 234 );     // establece hora no v�lida en 0
   t.estableceMinuto( 43 );    // establece minuto en un valor v�lido
   t.estableceSegundo( 6373 ); // establece segundo no v�lido en 0

   // despliega hora, minuto y segundo despu�s de establecer 
   // los valores no v�lidos de hora y segundo
   cout << "\n\nResultado del intento de establecer los valores no validos de minuto"
        << " y segundo:\n  Hora: " << t.obtieneHora1()
        << "  Minuto: " << t.obtieneMinuto()
        << "  Segundo: " << t.obtieneSegundo() << "\n\n";

   t.estableceHora( 11, 58, 0 );    // establece hora
   incrementaMinutos( t, 3 );  // incrementa los minutos de t en 3
   t.imprimeEstandar(); cout<<endl;


  }
    
    cout<<endl<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

// agrega el n�mero espec�fico de minutos a un objeto Tiempo
void incrementaMinutos( Tiempo tt, const int cuenta )
{
   cout << "Incrementa minuto " << cuenta
        << " veces:\nHora inicio: ";
   tt.imprimeEstandar();

   for ( int i = 0; i < cuenta; i++ ) {
      tt.estableceMinuto( ( tt.obtieneMinuto() + 1 ) % 60 );  

      if ( tt.obtieneMinuto() == 0 )
         tt.estableceHora1( ( tt.obtieneHora1() + 1 ) % 24 );

      cout << "\nminuto + 1: ";
      tt.imprimeEstandar();

   } // fin de for

   cout << endl;

} // fin de la funci�n incrementaMinutos
