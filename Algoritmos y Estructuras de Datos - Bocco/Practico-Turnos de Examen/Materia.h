#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Materia {

public:
   Materia() ; 
   Materia(string, int) ; 
   ~Materia(); // destructor predeterminado
   void setMateria( string, int ); 
   void setNombre( string );   
   void setCodigo( int );  

   string getNombre();  
   int    getCodigo();  

   string asString();
   void imprime();         // imprime la hora en formato universal
private:
   string nombre;   
   int codigo;   

}; // fin de la clase Materia

