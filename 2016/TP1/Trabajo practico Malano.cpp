//Trabajo practico de Algoritmos y estructuras de datos - Leandro Malano
//He decidido hacer solo este trabajo,aunque tenga grupo.

#include <iostream>

using namespace::std;

class Rectangulo
{       
public:
   Rectangulo( float = 0, float = 0);
   void set(float,float);
   void setcoordusuario();
   float getabs();
   float getord();
   void calc(); 
   void cuadrado( float, float );
   void verifrect(int rec);//verifica si es rectangulo
   void anchoylong(float aux1,float aux2);//calcula ancho y largo
   float perimetro( float, float);
   float area( float, float);
   
private:
   float x;
   float y; 
   };         

Rectangulo::Rectangulo( float a, float b)
{set(a,b);} 

void Rectangulo::set(float a, float b)
{
if(a<20) x=a;
else
x=1;
if(b<20) y=b;
else
y=1;	
}

void Rectangulo::setcoordusuario()
{  float aux1,aux2;
   cout << "\nPor favor introduzca un valor valido para x seguido del valor para y "
        << "(que sea menor que 20.0)" << endl;
   cin >> aux1>>aux2; 
   
   set( aux1, aux2); 
}       

float Rectangulo::getabs()
{return x;}

float Rectangulo::getord()
{return y;}

void Rectangulo::calc()
{   int rectangulo = 0;
    float auxiliar1 = 0;
    float auxiliar2 = 0;

  Rectangulo p1;//creo cada coordenada
  Rectangulo p2;
  Rectangulo p3;
  Rectangulo p4;
  p1.setcoordusuario();//establesco cada coordenada
  p2.setcoordusuario(); 
  p3.setcoordusuario();
  p4.setcoordusuario();

if ( p1.getabs() == p2.getabs() )
	 {if ( p3.getabs() == p4.getabs() )
		 	if ( p1.getord() == p3.getord() )
					 if ( p2.getord() == p4.getord())
							 {		rectangulo = 1; 
									auxiliar1 = p2.getord() - p1.getord();
									auxiliar2 = p4.getabs() - p2.getabs();
							 }

  				if ( p1.getord() == p4.getord()) 
  					if ( p2.getord() == p3.getord())
  						{ rectangulo = 1;
							auxiliar1 = p2.getord() - p1.getord(); 
							auxiliar2 = p3.getabs() - p2.getabs(); 
						} 
 	 }     

if ( p1.getabs() == p3.getabs() )
	{if ( p2.getabs() == p4.getabs() )
		{if ( p1.getord() == p2.getord() )
			{if ( p3.getord() == p4.getord() )
				{ rectangulo = 1;
					auxiliar1 = p3.getord() - p1.getord();
				     auxiliar2 = p4.getabs() - p3.getabs();
				}
			}
			
				if ( p1.getord() == p4.getord())
 					 if ( p3.getord() == p2.getord() )
					  		{ rectangulo = 1;
							  auxiliar1 = p3.getord() - p1.getord();
							  auxiliar2 = p2.getabs() - p3.getabs();
							}
		}       
   }         

if ( p1.getabs() == p4.getabs())
	{if ( p2.getabs() == p3.getabs())
		{if ( p1.getord() == p2.getord())
 			 if ( p4.getord() == p3.getord())
				{ rectangulo = 1;
  					auxiliar1 = p4.getord() - p1.getord();
					auxiliar2 = p3.getabs() - p4.getabs();
				}
			if ( p1.getord() == p3.getord())
				if ( p2.getord() == p4.getord())
					{ rectangulo = 1;
					auxiliar1 = p4.getord() - p1.getord();
					auxiliar2 = p4.getabs() - p2.getabs();
					}
		}        		
	}          
	
if ( auxiliar1 < 0 )
	auxiliar1 = -auxiliar1; 
if ( auxiliar2 < 0 )
	auxiliar2 = -auxiliar2;
//en caso de los lados den negativo	
cout<<"------------------------------------------------------------------------------------"<<endl;	
verifrect(rectangulo);

if (auxiliar1!=0 && auxiliar2!=0) //verifica si los lados son 0
  cuadrado( auxiliar1, auxiliar2);
	
anchoylong(auxiliar1,auxiliar2);

cout <<"\nEl perimetro es: " << perimetro( auxiliar1, auxiliar2) << endl;
cout << "\nEl area es: " << area( auxiliar1, auxiliar2 ) << endl;
}     

void Rectangulo::cuadrado( float a, float b)
{if ( a == b )
	cout << "\nEl rectangulo es un cuadrado. " << endl;
else
    cout << "\nEl rectangulo no es un cuadrado. " << endl;
}

float Rectangulo::perimetro( float n, float m)
{ return 2*n + 2*m;}      

 float Rectangulo::area( float s, float t)
{ return s*t;}       

void Rectangulo::verifrect(int rect)
{
	if ( 1 == rect)
	cout << "\nLas coordenadas forman un rectangulo." << endl;
else
	cout << "\nLas coordenadas no forman  un rectangulo. " << endl;
}

void Rectangulo::anchoylong(float aux1,float aux2)
{
	if ( aux1 > aux2 )
		{ cout << "\nLa longitud es: " << aux1 << endl;
  		  cout << "\nEl ancho es: " << aux2 << endl;
		}
	else
	{cout << "\nLa longitud es: " << aux2 << endl;
     cout << "\nEl ancho es: " << aux1 << endl;
	}
		
}
  int main(){  

   Rectangulo Rect1;
   Rect1.calc();

   return 0;
  }   
