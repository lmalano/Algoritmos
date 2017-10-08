<pre><p>#include &lt;cstdlib&gt;
#include &lt;iostream&gt;
using namespace std;
const int N = 15;
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
       friend bool operator&lt;=(conjunto c1, conjunto c2);
       friend bool operator==(conjunto c1, conjunto c2);
       friend bool operator!=(conjunto c1, conjunto c2);
       friend bool operator&lt;(conjunto c1, conjunto c2);
private:
        int elem[N],ne;
};
//constructor
conjunto::conjunto()
{
  int i;
  for(i=0;i&lt;N;i++) elem[i] = 0;
  ne = 0;
}
//destuctor
conjunto::~conjunto()
{
}
//sobrecarga para el operador + para insertar un nuevo elemento
void conjunto::operator+(int x )
{ int i,b;
  if ( pertenece(x) == false ){ 
    i=x/8;
    b=x%8;
    elem[i]=elem[i]|1&lt;&lt;b;
  }
  else cout&lt;&lt;&quot;Elemento ya existe&quot;&lt;&lt;endl;
}
//imprimir los elementos del conjunto
void conjunto::imprimir()
{ int i,j,b,a;
  for(i=0;i&lt;N;i++)
       for(j=0;j&lt;8;j++){
                        a=elem[i]&amp;1&lt;&lt;j;
                        if(a!=0){
                                 b=i*8+j;
                                 cout&lt;&lt;b&lt;&lt;&quot;\t&quot;;
                        }
       }
}
//ordenar los elementos del conjunto
void conjunto::ordenar()
{ cout&lt;&lt;&quot;\n Esta ordenado\n&quot;;
}
// el elemento pertenece al conjunto?
bool conjunto::pertenece(int x)
{ int i,b;
    i=x/8;
    b=x%8;
    if (elem[i]&amp;(1&lt;&lt;b)!=0)return true;
    return false;
}
//cardinalidad: numero de elementos del conjunto
int conjunto::cardinalidad()
{  int i,j,a,ne;
   ne=0;
   for(i=0;i&lt;N;i++)
       for(j=0;j&lt;8;j++){
                        a=elem[i]&amp;1&lt;&lt;j;
                        if(a!=0) ne++;
       } 
    return ne;
}
//definiendo la union de conjuntos
conjunto operator+(conjunto c1, conjunto c2)
{ conjunto c3;
  int x, i;
  for(i=0;i&lt;N;i++) c3.elem[i]=c1.elem[i] | c2.elem[i];
  return c3;
}
//definiendo la interseccion de conjuntos
conjunto operator*(conjunto c1, conjunto c2)
{ conjunto c3;
  int x, i;
  for(i=0;i&lt;N;i++) c3.elem[i]=c1.elem[i] &amp; c2.elem[i];
  return c3;
}
//definiendo la diferencia de conjuntos
conjunto operator-(conjunto c1, conjunto c2)
{ conjunto c3;
  int x, i;
  for(i=0;i&lt;N;i++) c3.elem[i]=c1.elem[i] ^ c2.elem[i];
  return c3;
}
//definiendo el subconjunto
// si c1 esta en c2 retorna true
bool operator&lt;=(conjunto c1, conjunto c2)
{ int i,a;
  for(i=0;i&lt;N;i++){
       if(c1.elem[i]!=0){
                         a=c1.elem[i]&amp;c2.elem[i];
                         if(a!=c1.elem[i])return false;
       }
  }
  return true;
}
//definiendo la igualdad de conjuntos
bool operator==( conjunto c1, conjunto c2 )
{ if ( ( c1 &lt;= c2 ) &amp;&amp; ( c2 &lt;= c1 ) )return true;
  else return false;
}
//definiendo la desigualdad de conjuntos
bool operator!=( conjunto c1, conjunto c2 )
{ return !(c1 == c2);
}
//definiendo el subconjunto propio
bool operator&lt;(conjunto c1, conjunto c2)
{ if ((c1 &lt;= c2) &amp;&amp; (c1 != c2))return true;
  else return false;
}
// fin de la clase conjunto

int main(int argc, char *argv[])
{ conjunto A,B,C,D,E;
  int i,x,n;
  cout&lt;&lt;&quot;Cuantos elementos desea ingresar para el Conjunto A ? &quot;;
  cin&gt;&gt;n;
  for(i=1;i&lt;=n;i++){ 
         cout&lt;&lt;&quot;Ingrese elemento &quot;&lt;&lt;i&lt;&lt;&quot;: &quot;;
         cin&gt;&gt;x;  A + x;
  }
  A.imprimir();
  cout&lt;&lt;&quot;\nCuantos elementos desea ingresar para el Conjunto B ? &quot;;
  cin&gt;&gt;n;
  for(i=1;i&lt;=n;i++){ 
         cout&lt;&lt;&quot;Ingrese elemento &quot;&lt;&lt;i&lt;&lt;&quot;: &quot;;
         cin&gt;&gt;x; B + x;
  }
  B.imprimir();
  C = A + B;
  cout&lt;&lt;endl&lt;&lt;&quot;\nC = A UNION B&quot;&lt;&lt;endl;
  C.imprimir();
  cout&lt;&lt;&quot;La cardinalidad de C es &quot;&lt;&lt;C.cardinalidad()&lt;&lt;endl;
  D = A * B;
  cout&lt;&lt;endl&lt;&lt;&quot;\nD = A INTERSECCION B&quot;&lt;&lt;endl;
  D.imprimir();
  cout&lt;&lt;&quot;La cardinalidad de D es &quot;&lt;&lt;D.cardinalidad()&lt;&lt;endl;
  E = A - B;
  cout&lt;&lt;endl&lt;&lt;&quot;\nE = DIFERENCIA de A y B&quot;&lt;&lt;endl;
  E.imprimir();
  cout&lt;&lt;&quot;La cardinalidad de E es &quot;&lt;&lt;E.cardinalidad()&lt;&lt;endl;
  if (A &lt;= B){ 
        cout&lt;&lt;&quot;\nA es subconjunto de B&quot;&lt;&lt;endl;
        if (A &lt; B)cout&lt;&lt;&quot;\nA es subconjunto propio de B&quot;&lt;&lt;endl;
  }
  else cout&lt;&lt;&quot;\nA no es subconjunto de B&quot;&lt;&lt;endl;
  if (A == B) cout&lt;&lt;&quot;\nA y B son iguales&quot;&lt;&lt;endl;
  else cout&lt;&lt;&quot;\nA y B son diferentes&quot;&lt;&lt;endl;
  cout&lt;&lt;endl;
  system(&quot;PAUSE&quot;);
  return EXIT_SUCCESS;
}
</p></pre>