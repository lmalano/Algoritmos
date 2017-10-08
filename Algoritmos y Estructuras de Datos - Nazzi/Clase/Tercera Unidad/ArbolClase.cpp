<pre><p>//#include &lt;cstdlib&gt;
#include &lt;iostream&gt;
#include &lt;sstream&gt;
#include &quot;ListaClase.cpp&quot;

using namespace std;
class NodoArbol{
    private: 
        int dato;
        NodoArbol *izq;
        NodoArbol *der;
    public:
        NodoArbol() {izq=NULL;der=NULL;};
        NodoArbol(int a) {dato=a; izq=NULL;der=NULL;};
        NodoArbol(int a,NodoArbol *pizq,NodoArbol *pder) {dato=a; izq=pizq;der=pder;};
        ~NodoArbol(void) {;};
        void set_dato(int a) {dato=a; };
        void set_izq(NodoArbol *n) {izq=n; };
        void set_der(NodoArbol *n) {der=n; };
        int get_dato() {return dato; };
        NodoArbol *get_izq() {return izq; };
        NodoArbol *get_der() {return der; };
        bool es_hoja() {return (izq==NULL) &amp;&amp; (der==NULL);}
};

class ArbolBin{
    private: 
             NodoArbol *nodo;
    public:
            ArbolBin() {nodo=NULL;};
            ArbolBin(NodoArbol *p) {nodo=p;};
            ArbolBin(int a,NodoArbol *izq,NodoArbol *der); 
            void set_nodo(NodoArbol *p) {nodo=p;};
            ~ArbolBin(void) ;
            bool esvacio(void) {return nodo==NULL;};
            NodoArbol *get_nodo() {return nodo;};
            int cabeza(void) {return nodo-&gt;get_dato();};
            ArbolBin *hi(void) {return new ArbolBin(nodo-&gt;get_izq());};
            ArbolBin *hd(void) {return new ArbolBin(nodo-&gt;get_der());};
            void set_izq(ArbolBin *n) {nodo-&gt;set_izq(n-&gt;get_nodo());};
            void set_der(ArbolBin *n) {nodo-&gt;set_der(n-&gt;get_nodo());};
            int altura();
            Lista *inorden(Lista *l) ;
            Lista *preorden(Lista *l) ;
            Lista *posorden(Lista *l) ;
};

ArbolBin::ArbolBin(int a,NodoArbol *izq,NodoArbol *der) {
   nodo=new NodoArbol(a,izq,der);
}

ArbolBin::~ArbolBin(void){
   if (!esvacio()){
      delete hi();
      delete hd();
      delete nodo;
   }

}
int ArbolBin::altura(){
   if (esvacio()){
      return 0;
   } else {
      return 1+max(hi()-&gt;altura(),hd()-&gt;altura());
   }
}

Lista *ArbolBin::inorden(Lista *l){
         if (esvacio()) {
            return l;
         } else {
            hd()-&gt;inorden(l);
            l-&gt;add(cabeza());
            hi()-&gt;inorden(l);
            return l;
         }
}

Lista *ArbolBin::preorden(Lista *l){
         if (esvacio()) {
            return l;
         } else {
            hd()-&gt;preorden(l);
            hi()-&gt;preorden(l);
            l-&gt;add(cabeza());
            return l;
         }
}

Lista *ArbolBin::posorden(Lista *l){
         if (esvacio()) {
            return l;
         } else {
            l-&gt;add(cabeza());
            hd()-&gt;posorden(l);
            hi()-&gt;posorden(l);
            return l;
         }
}

int main()
{
    ArbolBin *a=new ArbolBin();
    a-&gt;set_nodo(new NodoArbol(7,NULL,NULL));
    cout&lt;&lt; &quot;altura&quot; &lt;&lt; a-&gt;altura() &lt;&lt;endl;
    a-&gt;set_izq(new ArbolBin(new NodoArbol(6,NULL,NULL)));
    a-&gt;set_der(new ArbolBin(new NodoArbol(12,NULL,NULL)));
    cout&lt;&lt; &quot;altura&quot; &lt;&lt; a-&gt;altura() &lt;&lt;endl;
    ArbolBin *i,*d;
    i=a-&gt;hi();
    i-&gt;set_izq(new ArbolBin(new NodoArbol(3,NULL,NULL)));
    d=a-&gt;hd();
    d-&gt;set_izq(new ArbolBin(new NodoArbol(10,NULL,NULL)));
    i=d-&gt;hi();
    i-&gt;set_izq(new ArbolBin(new NodoArbol(9,NULL,NULL)));
    i=i-&gt;hi();
    i-&gt;set_izq(new ArbolBin(new NodoArbol(8,NULL,NULL)));
    
    cout&lt;&lt; &quot;altura&quot; &lt;&lt; a-&gt;altura() &lt;&lt;endl;
    cout&lt;&lt; a-&gt;inorden(new Lista())-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    cout&lt;&lt; a-&gt;preorden(new Lista())-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    cout&lt;&lt; a-&gt;posorden(new Lista())-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    delete a;    

//    system(&quot;PAUSE&quot;);
 
}

</p></pre>