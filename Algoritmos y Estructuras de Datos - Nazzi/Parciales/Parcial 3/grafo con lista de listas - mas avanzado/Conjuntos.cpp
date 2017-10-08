#include <cstdlib>
#include <iostream>
using namespace std;
const int N = 100;
//declarando la clase conjunto
class conjunto{
public:
       conjunto(); //constructor
       ~conjunto(); //destuctor
       void imprimir();
       void ordenar();
       bool pertenece(int x);
       int cardinalidad();
       void operator+(int x);
//funciones amigas
       friend conjunto operator+(conjunto c1 , conjunto c2);
       friend conjunto operator*(conjunto c1 , conjunto c2);
       friend conjunto operator-(conjunto c1 , conjunto c2);
//comparaciones
       friend bool operator<=(conjunto c1, conjunto c2);
       friend bool operator==(conjunto c1, conjunto c2);
       friend bool operator!=(conjunto c1, conjunto c2);
       friend bool operator<(conjunto c1, conjunto c2);
       
private:
        int elem[N], ne;               //ne = cardinalidad
};
//constructor
conjunto::conjunto()
{
  int i;
  for(i=0;i<N;i++) elem[i] = 0;
  ne = 0;
}
//destuctor
conjunto::~conjunto()
{
}
//sobrecarga para el operador + para insertar un nuevo elemento
void conjunto::operator+(int x )
{
  if ( pertenece(x) == false ){ 
       elem[ne] = x;
       ne++;
  }
  //else cout<<"Elemento ya existe "<<x<<endl;
}
//imprimir los elementos del conjunto
void conjunto::imprimir()
{ int i;
  if ( ne > 0 ){ 
       ordenar();
       for(i=0;i<ne;i++)cout<<elem[i]<<"\t";
       cout<<endl;
  }else cout<<"El conjunto esta vacio"<<endl;
}
//ordenar los elementos del conjunto
void conjunto::ordenar()
{ int i,j,x;
  if ( ne > 1 ){
       for(i=0;i<ne-1;i++)
          for(j=i+1;j<ne;j++)
             if ( elem[i] > elem[j] ){
                  x = elem[i];
                  elem[i] = elem[j];
                  elem[j] = x;
             }
  }
}
// el elemento pertenece al conjunto?
bool conjunto::pertenece(int x)
{ int i=0;
  bool b= false;
  while( b == false && i < ne)
      if (elem[i] == x)b = true;
      else i++;
  return b;
}
//cardinalidad: numero de elementos del conjunto
int conjunto::cardinalidad()
{ 
    return ne;
}
//definiendo la union de conjuntos
conjunto operator+(conjunto c1, conjunto c2)
{ conjunto c3;
  int x, i;
  for(i=0;i<c1.ne;i++) c3+c1.elem[i];//copio c1 en c3
  for(i=0;i<c2.ne;i++){ 
      x = c2.elem[i];
      if (c3.pertenece(x) == false){
             c3+x;// copio c2 en c3, si no estaba
      }
  }
  return c3;
}
//definiendo la interseccion de conjuntos
conjunto operator*(conjunto c1, conjunto c2)
{ conjunto c3;
  int x,i;
  for(i=0;i<c1.ne;i++){ 
      x = c1.elem[i];
      if ( c2.pertenece(x) == true ) c3+x;
  }
  return c3;
}
//definiendo la diferencia de conjuntos
conjunto operator-(conjunto c1, conjunto c2)
{ conjunto c3;
  int x,i;
  for(i=0;i<c1.ne;i++){
        x = c1.elem[i];
        if ( c2.pertenece(x) == false )c3+x;
  }
return c3;
}
//definiendo el subconjunto
// si c1 esta en c2 retorna true
bool operator<=(conjunto c1, conjunto c2)
{ int x,i;
  for(i=0;i<c1.ne;i++){ 
       x = c1.elem[i];
       if ( c2.pertenece(x) == false )return false;
  }
  return true;
}
//definiendo la igualdad de conjuntos
bool operator==( conjunto c1, conjunto c2 )
{ if ( ( c1 <= c2 ) && ( c2 <= c1 ) )return true;
  else return false;
}
//definiendo la desigualdad de conjuntos
bool operator!=( conjunto c1, conjunto c2 )
{ return !(c1 == c2);
}
//definiendo el subconjunto propio
bool operator<(conjunto c1, conjunto c2)
{ if ((c1 <= c2) && (c1 != c2))return true;
  else return false;
}
// fin de la clase conjunto
