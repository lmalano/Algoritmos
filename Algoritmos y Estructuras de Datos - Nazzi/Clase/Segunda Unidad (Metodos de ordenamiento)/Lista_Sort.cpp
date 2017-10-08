<pre><p>#include &lt;iostream&gt;
#include &lt;sstream&gt;

using namespace std;
class Nodo{
    private: 
        int dato;
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        Nodo(int a) {dato=a; next=NULL;};
        void set_dato(int a) {dato=a; };
        void set_next(Nodo *n) {next=n; };
        int get_dato() {return dato; };
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    private: Nodo *czo;
        Lista *copy2(Lista *l, Nodo *last);
        void take2(Nodo *last);
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            ~Lista(void);
            void add(int d);
            bool esvacia(void);
            int cabeza(void);
            Lista *resto(void);
            Lista *copy();
            Nodo *get_czo() {return czo; };
            void borrar(void); //borra la cabeza
            void drop(int n);
            void take(int n);
            void concat(Lista *l1);
            string toPrint(string p);   
            int suma(int i);
            void swapl(Lista *j,Lista *k);
            Lista *burbuja(Lista *l,Lista *lt,int n);
            int size();
            Lista *insercion(Lista *l,Lista *act,Lista *pos);
};
void Lista::add(int d)
{  
     Nodo *nuevo=new Nodo(d);
     nuevo-&gt;set_next(czo);
     czo=nuevo;
}
bool Lista::esvacia(void)
{   
    return czo-&gt;es_vacio();
}

int Lista::cabeza(void)
{ 
  if(esvacia()){
                cout&lt;&lt;&quot; Error, Cabeza de lista vacia&quot;;
                return -1; 
  }
  return czo-&gt;get_dato();
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo-&gt;get_next());
      return (l);
}

Lista *Lista::copy2(Lista *l, Nodo *last)
{ 
   if (this-&gt;esvacia()){
      return l;
   } else {
      last-&gt;set_dato(this-&gt;cabeza());
      Nodo *nuevo=new Nodo();
      last-&gt;set_next(nuevo);
      return (this-&gt;resto())-&gt;copy2(l,nuevo);
   }
}

Lista *Lista::copy(void)
{ 
      Lista *l=new Lista();
      return this-&gt;copy2(l,l-&gt;get_czo());
}

void Lista::borrar(void)
{ 
  if(esvacia()){
  } else {
         Nodo *tmp=czo;
         czo=czo-&gt;get_next();
         delete tmp;
  }
}

Lista::~Lista(void){
   while (!esvacia()){
         this-&gt;borrar();
   }
}

void Lista::drop(int n){
   if (!(this-&gt;esvacia()) &amp;&amp; (n&gt;0)) {
       this-&gt;borrar();
       this-&gt;drop(n-1);
   }
}

void Lista::take2(Nodo *last){
     if (!(last-&gt;es_vacio())){
        this-&gt;take2(last-&gt;get_next());
     }
     delete last;

}

void Lista::take(int n)
{ 
   if(!(this-&gt;esvacia())) {
      if (n&gt;0){
         this-&gt;resto()-&gt;take(n-1);
      } else {
         this-&gt;take2((this-&gt;get_czo())-&gt;get_next());
         (this-&gt;get_czo())-&gt;set_next(NULL);
         
      }
   }
}
 
void Lista::concat(Lista *l1)
{
   if (!(l1-&gt;esvacia())){
      this-&gt;concat(l1-&gt;resto());
      this-&gt;add(l1-&gt;cabeza());
   }
}

string Lista::toPrint(string p)
{ 
     if (this-&gt;esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm &lt;&lt; this-&gt;cabeza()&lt;&lt;&quot;-&quot;&lt;&lt; this-&gt;resto()-&gt;toPrint(p) ;
       return stm.str();
     }
}
int Lista::suma(int i)
{ 
     if (this-&gt;esvacia()) {
        return i;
     } else {
        return this-&gt;resto()-&gt;suma(i+this-&gt;cabeza());
     }
}
int Lista::size()
{ 
     if (this-&gt;esvacia()) {
        return 0;
     } else {
        return 1+this-&gt;resto()-&gt;size();
     }
}

void Lista::swapl(Lista *j,Lista *k){
     cout&lt;&lt;endl&lt;&lt;&quot;SWAP cabeza j &quot;&lt;&lt;j-&gt;cabeza()&lt;&lt;&quot; k &quot;&lt;&lt;k-&gt;cabeza();
     int temp=j-&gt;czo-&gt;get_dato();
     j-&gt;czo-&gt;set_dato(k-&gt;czo-&gt;get_dato());
     k-&gt;czo-&gt;set_dato(temp);
}

Lista * Lista::burbuja(Lista *l,Lista *lt,int n){
   
   if (n==0) {
      return l;
   } else {
          if (lt-&gt;resto()-&gt;esvacia()) {
             cout&lt;&lt;endl&lt;&lt;&quot;------------- fin pasada &quot;&lt;&lt;n&lt;&lt;endl;
             return burbuja(l, l, n-1);
          } else {
             if (lt-&gt;cabeza() &gt; lt-&gt;resto()-&gt;cabeza()) {
                 swapl(lt,lt-&gt;resto());
             }
             return burbuja(l,lt-&gt;resto(),n);
          }
   }
  return l;
}
Lista * Lista::insercion(Lista *l,Lista *act,Lista *pos){
      if (!pos-&gt;esvacia() &amp;&amp; !pos-&gt;resto()-&gt;esvacia() &amp;&amp; 
          (pos-&gt;cabeza() &gt; pos-&gt;resto()-&gt;cabeza())  ){
               swapl(pos,pos-&gt;resto());
               return insercion(l,act,pos-&gt;resto());
      } 
      else {
         if (l-&gt;esvacia()) {
               return act;
         }
         else {
               act-&gt;add(l-&gt;cabeza());
               return insercion(l-&gt;resto(),act,act);
         }
      }
}

int main()
{
    Lista *l=new Lista();
    l-&gt;add(220);
    l-&gt;add(6);
    l-&gt;add(44);
    l-&gt;add(2);
    //l-&gt;add(12);
    //l-&gt;add(15);
    //l-&gt;add(11);
    //l-&gt;add(2);
    //l-&gt;add(7);
    cout&lt;&lt; &quot;l:  &quot;&lt;&lt; l-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    cout&lt;&lt;&quot;Cantidad elementos en lista:  &quot;&lt;&lt;l-&gt;size()&lt;&lt;endl;
    
    //l=l-&gt;burbuja(l,l,l-&gt;size());
    //cout&lt;&lt;endl&lt;&lt;&quot;despues burbuja l:  &quot;&lt;&lt; l-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    
    l=l-&gt;insercion(l,new Lista(),new Lista());
    cout&lt;&lt;endl&lt;&lt; &quot;despues insercion l:  &quot;&lt;&lt; l-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    
/*    cout&lt;&lt; &quot;suma:&quot;&lt;&lt;l-&gt;suma(0)&lt;&lt;endl;
    Lista *l2=l-&gt;copy();
    Lista *l3=l-&gt;copy();
    l-&gt;borrar();
    cout&lt;&lt; &quot;suma:&quot;&lt;&lt;l-&gt;suma(0)&lt;&lt;endl;

    cout&lt;&lt;&quot;l2:&quot;&lt;&lt; l2-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    l2-&gt;add(15);
    cout&lt;&lt;&quot;l2 ++ 15:&quot;&lt;&lt; l2-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    l2-&gt;borrar();
    cout&lt;&lt;&quot;l2 --15:&quot;&lt;&lt; l2-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    l2-&gt;take(2);
    cout&lt;&lt;&quot;l2 :&quot;&lt;&lt; l2-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    l3-&gt;drop(2);
    cout&lt;&lt;&quot;l3 :&quot;&lt;&lt; l3-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;

    Lista *l4=l3-&gt;copy();
    l4-&gt;concat(l2);
    cout&lt;&lt;&quot;l4 :&quot;&lt;&lt; l4-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    cout&lt;&lt;&quot;l orig:&quot;&lt;&lt; l-&gt;toPrint(&quot;&quot;) &lt;&lt;endl;
    delete l;
    delete l2;
    delete l3;
    delete l4;
    */
    cout&lt;&lt;endl&lt;&lt;endl;
    system(&quot;PAUSE&quot;);
    
}
</p></pre>