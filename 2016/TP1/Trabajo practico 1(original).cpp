#include <iostream>

using namespace::std;

class Rectangulo
{       

 	  public:
   Rectangulo( float = 0, float = 0);
   void setCoordenadas(float, float);
   void setCoordenadas_Usuario();
   void setLongitud();
   void setAnchura(); 
   float getAbscisa();
   float getOrdenada();
   void Utileria();
   void Cuadrado( float, float );
   
  	 private:
   float x;
   float y;
   float Perimetro( float, float);
   float Area( float, float);
   };         

Rectangulo::Rectangulo( float a, float b)
{  x = a;
   y = b;
} 

void Rectangulo::setCoordenadas_Usuario()
{  float aux1;
   float aux2;
   cout << "\nPor favor introduzca un valor valido para x seguido del valor para y"
        << "( mayor que 0.0 y menor que 20.0)" << endl;
   cin >> aux1; 
   cin >> aux2;
   setCoordenadas( aux1, aux2); 
}       


void Rectangulo::setCoordenadas( float m, float n)
{   x = ( 0 < m && 20 >= m)? m: 1;
    y = ( 0 < n && 20 >= n)? n: 1;  
} 

float Rectangulo::getAbscisa()
{return x;}

float Rectangulo::getOrdenada()
{return y;}

void Rectangulo::Utileria()
{   int rectangulo = 0;
    float auxiliar1 = 0;
    float auxiliar2 = 0;

  Rectangulo punto1;//creo cada coordenada
  Rectangulo punto2;
  Rectangulo punto3;
  Rectangulo punto4;
  punto1.setCoordenadas_Usuario();//establesco cada coordenada
  punto2.setCoordenadas_Usuario(); 
  punto3.setCoordenadas_Usuario();
  punto4.setCoordenadas_Usuario();

if ( punto1.getAbscisa() == punto2.getAbscisa() )
	 {if ( punto3.getAbscisa() == punto4.getAbscisa() )
		 	if ( punto1.getOrdenada() == punto3.getOrdenada() )
					 if ( punto2.getOrdenada() == punto4.getOrdenada())
							 {		rectangulo = 1; 
									auxiliar1 = punto2.getOrdenada() - punto1.getOrdenada();
									auxiliar2 = punto4.getAbscisa() - punto2.getAbscisa();
							 }

  				if ( punto1.getOrdenada() == punto4.getOrdenada()) 
  					if ( punto2.getOrdenada() == punto3.getOrdenada())
  						{ rectangulo = 1;
							auxiliar1 = punto2.getOrdenada() - punto1.getOrdenada(); 
							auxiliar2 = punto3.getAbscisa() - punto2.getAbscisa(); 
						} 
 	 }     

if ( punto1.getAbscisa() == punto3.getAbscisa() )
	{if ( punto2.getAbscisa() == punto4.getAbscisa() )
		{if ( punto1.getOrdenada() == punto2.getOrdenada() )
			{if ( punto3.getOrdenada() == punto4.getOrdenada() )
				{ rectangulo = 1;
					auxiliar1 = punto3.getOrdenada() - punto1.getOrdenada();
				     auxiliar2 = punto4.getAbscisa() - punto3.getAbscisa();
				}
			}
			
				if ( punto1.getOrdenada() == punto4.getOrdenada())
 					 if ( punto3.getOrdenada() == punto2.getOrdenada() )
					  		{ rectangulo = 1;
							  auxiliar1 = punto3.getOrdenada() - punto1.getOrdenada();
							  auxiliar2 = punto2.getAbscisa() - punto3.getAbscisa();
							}
		}       
   }         

if ( punto1.getAbscisa() == punto4.getAbscisa())
	{if ( punto2.getAbscisa() == punto3.getAbscisa())
		{if ( punto1.getOrdenada() == punto2.getOrdenada())
 			 if ( punto4.getOrdenada() == punto3.getOrdenada())
				{ rectangulo = 1;
  					auxiliar1 = punto4.getOrdenada() - punto1.getOrdenada();
					auxiliar2 = punto3.getAbscisa() - punto4.getAbscisa();
				}
			if ( punto1.getOrdenada() == punto3.getOrdenada())
				if ( punto2.getOrdenada() == punto4.getOrdenada())
					{ rectangulo = 1;
					auxiliar1 = punto4.getOrdenada() - punto1.getOrdenada();
					auxiliar2 = punto4.getAbscisa() - punto2.getAbscisa();
					}
		}        		
	}          
	
if ( 1 == rectangulo )
	cout << "\nLas coordenadas forman un rectangulo." << endl;
else
	cout << "\nLas coordenadas no forman  un rectangulo. " << endl;
if ( auxiliar1 < 0 )
	auxiliar1 = -auxiliar1; 
if ( auxiliar2 < 0 )
	auxiliar2 = -auxiliar2;
	
if ( auxiliar1 > auxiliar2 )
		{ cout << "\nLa longitud es: " << auxiliar1 << endl;
  		  cout << "\nEl ancho es: " << auxiliar2 << endl;
		}
else
	{cout << "\nLa longitud es: " << auxiliar2 << endl;
     cout << "\nEl ancho es: " << auxiliar1 << endl;
	}
	
cout <<"\nEl perimetro es: " << Perimetro( auxiliar1, auxiliar2) << endl;
cout << "\nEl area es: " << Area( auxiliar1, auxiliar2 ) << endl;

if ( 0 != Area( auxiliar1, auxiliar2 ) )
  Cuadrado( auxiliar1, auxiliar2);

}     

void Rectangulo::Cuadrado( float a, float b)
{if ( a == b )
	cout << "\nEl rectangulo es un cuadrado. " << endl;
else
    cout << "\nEl rectangulo no es un cuadrado. " << endl;
}

float Rectangulo::Perimetro( float n, float m)
{ return 2*n + 2*m;}      

 float Rectangulo::Area( float s, float t)
{ return s*t;}       

  int main(){  

   Rectangulo Rect1;
   Rect1.Utileria();

   return 0;
  }   
