<pre><p>//#include &lt;cstdlib&gt;
#include &lt;iostream&gt;
#include &lt;sstream&gt;
#include &quot;ListaClase.cpp&quot;

#define ORDEN 4

using namespace std;
class NodoArbolB{
    private: 
        int dato[ORDEN];
        NodoArbolB *hijos[ORDEN];
        NodoArbolB *last;
        int lastused;
    public:
        NodoArbolB();
        ~NodoArbolB(void) {;};
        bool lleno() {return lastused==ORDEN-1;};
        void set_dato(int a) ;
        bool is_dato(int a);
        int  get_pos(int a);
        int  get_dato(int i) {return dato[i];};
        int  get_lastused() {return lastused;};

};

NodoArbolB::NodoArbolB() {
   for (int i=0;i&lt;ORDEN;i++)
       hijos[i]==NULL;
   last==NULL;
   lastused=-1;
}

void NodoArbolB::set_dato(int a) {
   if (!(this-&gt;lleno())) {
      lastused++;
      dato[lastused]=a;
   }
   ///cambiar esta funcion por una que inserte ordenando por insercion
}

bool NodoArbolB::is_dato(int a) {
   bool ret=false;
   for (int i=0;i&lt;=lastused;i++){
        if (dato[i]==a)
           ret=true;
   }
   return ret;
   ///cambiar por una funcion que haga busqueda binaria
}

int NodoArbolB::get_pos(int a) {
   int ret=-1;
   for (int i=0;i&lt;=lastused;i++){
        if (dato[i]==a)
           ret=i;
   }
   return ret;
   ///cambiar por una funcion que haga busqueda binaria
}

class ArbolB{
    private: 
             NodoArbolB *nodo;
    public:
            ArbolB() {nodo=NULL;};
            ArbolB(NodoArbolB *p) {nodo=p;};
            ~ArbolB(void) ;
            NodoArbolB *get_nodo() {return nodo;};
            bool esvacio(void) {return nodo==NULL;};
            int altura();
            void insert(int a);
            Lista *toLista(Lista *l);
};

ArbolB::~ArbolB(void){
   if (!esvacio()){
      delete nodo;
      ///completar
   }
}

int ArbolB::altura(){
   if (esvacio()){
      return 0;
   } else {
      ///reemplazar por el computo correcto
      return 1;
   }
}

void ArbolB::insert(int a){
   if (this-&gt;esvacio()){
      nodo=new NodoArbolB();
   }
   nodo-&gt;set_dato(a);
}

Lista *ArbolB::toLista(Lista *l){
      for (int i=0;i&lt;=this-&gt;get_nodo()-&gt;get_lastused();i++){
         l-&gt;add(this-&gt;get_nodo()-&gt;get_dato(i));
      }
      return l;
      ///reemplazar por la version correcta
}


int main()
{
    ArbolB *a=new ArbolB();
    a-&gt;insert(7);
    a-&gt;insert(9);
    
    cout&lt;&lt; &quot;altura&quot; &lt;&lt; a-&gt;altura() &lt;&lt;endl;
    cout&lt;&lt; a-&gt;toLista(new Lista())-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    delete a;    

//    system(&quot;PAUSE&quot;);
 
}

</p></pre>