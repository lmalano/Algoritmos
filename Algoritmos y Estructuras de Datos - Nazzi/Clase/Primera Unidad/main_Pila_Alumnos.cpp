<pre><p>//#include &lt;cstdlib&gt;
#include &lt;iostream&gt;
#include &lt;sstream&gt;

//comentar que como es una lista de string, tengo que redefinir el nodo
//resaltar que solo se cambia la parte int de la lista anterior por string
using namespace std;

typedef char tipolista;

class Nodo{
    protected: 
        tipolista dato;
        Nodo *next;
    public:
        Nodo() {next=NULL;};
        Nodo(tipolista a) {dato=a; next=NULL;};
        void set_dato(tipolista a) {dato=a; };
        void set_next(Nodo *n) {next=n; };
        tipolista get_dato() {return dato; };
        Nodo *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    protected: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            //~Lista(void);
            //tipolista Lista::ultimo(tipolista x);
            void del(void);
            void add(tipolista d);
            bool esvacia(void);
            tipolista cabeza(void);
            Lista *resto(void);
            tipolista toPrint(tipolista p);   
            string esta(tipolista p,bool t2);
            int dondeesta(tipolista p,int t2,int pos);
            tipolista maslargo(tipolista t2);
};

class Pila:public Lista{
      public:
             Pila(){Lista();};
             void push(tipolista x){add(x);};
             tipolista tope(void){return cabeza();};
             void pop(void){del();};
             bool pilavacia(){return esvacia();};
};                  

void Lista::del(void)
{    Nodo *aux;
     aux=czo;
     czo=czo-&gt;get_next();
     delete aux;
}
void Lista::add(tipolista d)
{  
     Nodo *nuevo=new Nodo(d);
     nuevo-&gt;set_next(czo);
     czo=nuevo;
}
bool Lista::esvacia(void)
{   
    return czo-&gt;es_vacio();
}

tipolista Lista::cabeza(void)
{ 
  if(esvacia()){
                cout&lt;&lt;&quot; Error, Cabeza de lista vacia&quot;;
                return ' '; 
  }
  return czo-&gt;get_dato();
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo-&gt;get_next());
      return (l);
}

/*tipolista Lista::toPrint(tipolista p)
{ 
     if (this-&gt;esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm &lt;&lt; this-&gt;cabeza()&lt;&lt;&quot;-&quot;&lt;&lt; this-&gt;resto()-&gt;toPrint(p) &lt;&lt; endl;
       return stm.str();
     }
}
//mostrar que solo cambia la parte de procesemiento individual en cada funcion
*/
inline string Lista::esta(tipolista p, bool t2)
{ 
     if (this-&gt;esvacia()) {
        if(t2) return &quot; si esta&quot;;
        else return &quot; no esta&quot;;
     } else {
//      esta es la parte que hace el procesamiento
        if (p==this-&gt;cabeza()) {
           t2=true;
        }
//        
        return this-&gt;resto()-&gt;esta(p,t2);
     }
}

int Lista::dondeesta(tipolista p, int t2, int pos)
{ 
     if (this-&gt;esvacia()) {
        return t2;
     } else {
//      esta es la parte que hace el procesamiento
        if (p==this-&gt;cabeza()) {
           t2=pos;
        }
        pos++;
//        
        return this-&gt;resto()-&gt;dondeesta(p,t2,pos);
     }
}
/*tipolista Lista::maslargo(tipolista t2)
{ 
     if (this-&gt;esvacia()) {
        return t2;
     } else {
//      esta es la parte que hace el procesamiento
        if (this-&gt;cabeza().size()&gt;t2.size()){
           t2=this-&gt;cabeza();
        }
//        
        return this-&gt;resto()-&gt;maslargo(t2);
     }
}

*/


int main()
{
    string cadena;
    Pila *p=new Pila();
/*    cout&lt;&lt;endl&lt;&lt;&quot;Apilando ---------------------------------&quot;&lt;&lt;endl;
    p-&gt;push(&quot;primer&quot;);
    p-&gt;push(&quot;segundo&quot;);
    p-&gt;push(&quot;tercer&quot;);
    p-&gt;push(&quot;cuarto&quot;);
    cout&lt;&lt;endl&lt;&lt;&quot;Mostrando ---------------------------------&quot;&lt;&lt;endl;    
    cout&lt;&lt;endl&lt;&lt;p-&gt;tope()&lt;&lt;endl;
    p-&gt;pop();
    cout&lt;&lt;endl&lt;&lt;p-&gt;tope()&lt;&lt;endl;
     p-&gt;pop();
    cout&lt;&lt;endl&lt;&lt;p-&gt;tope()&lt;&lt;endl;
     p-&gt;pop();
    cout&lt;&lt;endl&lt;&lt;p-&gt;tope()&lt;&lt;endl;
     p-&gt;pop();
    cout&lt;&lt;endl&lt;&lt;p-&gt;tope()&lt;&lt;endl;
  */
  cout&lt;&lt;endl&lt;&lt;&quot;Ingrese cadena= &quot;; cin&gt;&gt;cadena;
  int error=0;
  for(int i=0;(i&lt;cadena.length())&amp;&amp;(!error);i++){
          if (cadena.at(i)=='{') p-&gt;push('{');       
          if (cadena.at(i)=='[') p-&gt;push('[');
          if (cadena.at(i)=='(') p-&gt;push('(');
          if (cadena.at(i)=='}'){
                                 if(p-&gt;tope()!='{') error=1;
                                 else p-&gt;pop();                     
          }                               
          if (cadena.at(i)==']'){
                                 if(p-&gt;tope()!='[') error=1;
                                 else p-&gt;pop();                     
          }                               
          if (cadena.at(i)==')'){
                                 if(p-&gt;tope()!='(') error=1;
                                 else p-&gt;pop();                     
          }                               
    }  
    if(!error) cout&lt;&lt;endl&lt;&lt;&quot;TOdo OK&quot;;
    else cout&lt;&lt;endl&lt;&lt;&quot;ERROR&quot;;
     cout&lt;&lt;endl;
     system(&quot;PAUSE&quot;);
     return 0;
}

</p></pre>