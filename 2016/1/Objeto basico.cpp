//Crear una clase Rectangulo que almacene las coordenadas cartesianas de las cuatro esquinas de un rect�ngulo. 
//El constructor debe llamar a un m�todo set que acepta cuatro coordenadas y verifica que cada una de estas se 
//encuentre en el primer cuadrante y que ninguna coordenada x o y sea mayor que 20.0 (por defecto se crear� un cuadrado de lado 
//1 donde el v�rtice inferior izquierdo estar� en el origen). 
//El m�todo set verifica tambi�n que las coordenadas proporcionadas formen, en realidad, un rect�ngulo. 
//Proporcione funciones miembro que calculen la longitud, ancho, el per�metro y el �rea (la longitud es la mayor de las dos dimensiones).
// Incluya un m�todo cuadrado que determine si el rect�ngulo es un cuadrado.



#include <iostream>
using namespace std;

class point{
	
	int xval,yval;
	public:
		void setpt(int,int);
		void offsetpt(int,int);
	
	
};

int main()
{
  
  //point *p=new point();
  //p->offsetpt(10,20);    FORMA 1 con puntero
 
  point p;
  p.offsetpt(10,20);//forma 2

//x referencia
point q;
p.offsetpt(30,40);//forma 3


}

void point::setpt(int x,int y)
{
	xval=x;
	yval=y;
}

void point::offsetpt(int x,int y)
{
		xval+=x;
	yval+=y;
	
	cout<<x;
}
