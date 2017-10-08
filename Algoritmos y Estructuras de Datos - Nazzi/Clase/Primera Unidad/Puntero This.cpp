#include <cstdlib>
#include <iostream>

using namespace std;
class Prueba {

public:
   Prueba( int = 0 );    // constructor predeterminado
   void imprime() const;

private:
   int x;

}; // fin de la clase Prueba

// constructor
Prueba::Prueba( int valor ) 
   : x( valor )  // inicializa x en valor
{ 
   // cuerpo vacío 
   
} // fin del constructor Prueba

// imprime x mediante el uso implícito y explícito de apuntadores this;
// se requieren paréntesis alrededor de *this
void Prueba::imprime() const   
{
   // uso implícito del apuntador this para acceder al miembro x
   cout << "        x = " << x;

   // uso explícito del apuntador this para acceder al miembro x
   cout << "\n  this->x = " << this->x;

   // uso explícito del apuntador this desreferenciado y 
   // el operador punto para acceder al miembro x
   cout << "\n(*this).x = " << ( *this ).x << endl;

} // fin de la función imprime

int main(int argc, char *argv[])
{   Prueba objetoPrueba( 12 );

   objetoPrueba.imprime();

    system("PAUSE");
    return EXIT_SUCCESS;
}
