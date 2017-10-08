<pre><p>#include &lt;stdio.h&gt;
#include &lt;iostream&gt;
#include &lt;conio.h&gt;

using namespace std;

typedef int tarbol;
struct nodo{
      tarbol info;
      nodo *der,*izq;
};
typedef nodo * pnodo;
class arbol{
    pnodo raiz, q;
    void ArbolBusq(tarbol x, pnodo &amp;nuevo);
    void rid(pnodo aux);
    void ird(pnodo aux);
    void idr(pnodo aux);
    void show(pnodo aux, int n);
    void borrar(pnodo &amp;p, tarbol x);
    void bor(pnodo &amp;d);
public:
    arbol(){raiz=NULL;};
    ~arbol(){};
    void CreaArbolBus(tarbol x);
    void RID(){ rid(raiz); }
    void IRD(){ ird(raiz); }
    void IDR(){ idr(raiz); }
    void VerArbol(){ show(raiz,0); }
    void Borrar(tarbol x){ borrar(raiz,x);}
};
void arbol::borrar(pnodo &amp;p, tarbol x)
{ if(p==NULL) cout&lt;&lt;&quot;\n El dato NO esta\n\n&quot;;
  else if(x&gt;p-&gt;info) borrar(p-&gt;der,x);
  else if(x&lt;p-&gt;info) borrar(p-&gt;izq,x);
  else {// lo encontre en el nodo p
        q=p;
        if (q-&gt;der==NULL) p=q-&gt;izq;
        else if (q-&gt;izq==NULL) p=q-&gt;der;
        else bor(q-&gt;izq);//busca en el sub arbol izq
        delete q;
  }
}
void arbol::bor(pnodo &amp;d)
{ if(d-&gt;der!=NULL) bor(d-&gt;der);//busca el elemento mas a la derecha
  else{ q-&gt;info = d-&gt;info;
        q=d;
        d=d-&gt;izq;
  }
}
void arbol::CreaArbolBus(tarbol x)
{ ArbolBusq(x,raiz);
}
void arbol::ArbolBusq(tarbol x, pnodo &amp;nuevo)
{
  if(nuevo==NULL){
      nuevo= new nodo;
      nuevo-&gt;info=x; nuevo-&gt;der=nuevo-&gt;izq=NULL;
  }
  if(x &gt; nuevo-&gt;info) ArbolBusq(x, nuevo-&gt;der);
  if(x &lt; nuevo-&gt;info) ArbolBusq(x, nuevo-&gt;izq);
}
void arbol::ird(pnodo aux)
{  if(aux!=NULL){
        ird(aux-&gt;izq);
        cout&lt;&lt;&quot;\n&quot;&lt;&lt;aux-&gt;info;
        ird(aux-&gt;der);
   }
}
void arbol::rid(pnodo aux)
{  if(aux!=NULL){
        cout&lt;&lt;&quot;\n&quot;&lt;&lt;aux-&gt;info;
        rid(aux-&gt;izq);
        rid(aux-&gt;der);
   }
}
void arbol::idr(pnodo aux)
{  if(aux!=NULL){
        idr(aux-&gt;izq);
        idr(aux-&gt;der);
        cout&lt;&lt;&quot;\n&quot;&lt;&lt;aux-&gt;info;
   }
}
void arbol::show(pnodo aux, int n)
{ int i;
   if(aux!=NULL){                      //OjO este es un recorrido dri
       show(aux-&gt;der, n+1);
       for(i=1; i&lt;=n; i++) cout&lt;&lt;&quot;     &quot;;
       cout&lt;&lt;aux-&gt;info&lt;&lt;&quot;\n&quot;;
       show(aux-&gt;izq, n+1);
   }
}
//-------------------------------------------------------
int main (int argc, char *argv[])
{  int i; tarbol x;
   arbol T;
   int vec[10]={50,20,80,40,70,60,10,20,5,95};
   for(i=0;i&lt;10;i++) T.CreaArbolBus(vec[i]);                 
   T.VerArbol();
   for(i=1;i&lt;3;i++){
     cout&lt;&lt;&quot;\n -------------------------------- Ing dato a borrar= &quot;; cin&gt;&gt;x;
     T.Borrar(x);
     T.VerArbol();
   }
   system(&quot;PAUSE&quot;);
   return EXIT_SUCCESS;
}
</p></pre>