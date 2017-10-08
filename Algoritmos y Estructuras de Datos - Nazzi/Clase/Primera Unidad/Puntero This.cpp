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
   // cuerpo vac�o 
   
} // fin del constructor Prueba

// imprime x mediante el uso impl�cito y expl�cito de apuntadores this;
// se requieren par�ntesis alrededor de *this
void Prueba::imprime() const   
{
   // uso impl�cito del apuntador this para acceder al miembro x
   cout << "        x = " << x;

   // uso expl�cito del apuntador this para acceder al miembro x
   cout << "\n  this->x = " << this->x;

   // uso expl�cito del apuntador this desreferenciado y 
   // el operador punto para acceder al miembro x
   cout << "\n(*this).x = " << ( *this ).x << endl;

} // fin de la funci�n imprime

int main(int argc, char *argv[])
{   Prueba objetoPrueba( 12 );

   objetoPrueba.imprime();

    system("PAUSE");
    return EXIT_SUCCESS;
}
