#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class calculadora{

public:
	calculadora(int=0,int=0);
   Punto3( int = 0, int = 0 ); // constructor predeterminado
	int sumar(int c, int d);
	void restar();
	getsuma();
	getresta();
	imprime();


private: 
   int x;  
   int y; 

};
calculadora::calculadora(int a ,int b )
{	x=a;
	y=b;
	
}
int calculadora::sumar(int c, int d)
{	int e=x+y;
	
}
 

int main(int argc, char *argv[])
{  //Circulo4 *circulo; // crea puntero a Circulo4
   //circulo= new Circulo4( 37, 43, 2.5 ); // crea la instancia del objeto Circulo4
   //circulo->desplX(2);//desplazo x en 2
 

    system("PAUSE");
    return EXIT_SUCCESS;
}
