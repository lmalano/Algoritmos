//Crear una clase Rectangulo que almacene las coordenadas cartesianas de las cuatro esquinas de un rectángulo. 
//El constructor debe llamar a un método set que acepta cuatro coordenadas y verifica que cada una de estas se 
//encuentre en el primer cuadrante y que ninguna coordenada x o y sea mayor que 20.0 (por defecto se creará un cuadrado de lado 
//1 donde el vértice inferior izquierdo estará en el origen). 
//El método set verifica también que las coordenadas proporcionadas formen, en realidad, un rectángulo. 
//Proporcione funciones miembro que calculen la longitud, ancho, el perímetro y el área (la longitud es la mayor de las dos dimensiones).
// Incluya un método cuadrado que determine si el rectángulo es un cuadrado.



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
