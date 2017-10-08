<pre><p>#include &lt;cstdlib&gt;
#include &lt;iostream&gt;
#include &lt;sstream&gt;

using namespace std;

typedef int tipolista;

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
        bool es_vacio() {return next==NULL;};
        
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
            string toPrint(tipolista p);   
            string esta(tipolista p,bool t2);
            int dondeesta(tipolista p,int t2,int pos);
            tipolista maslargo(tipolista t2);
            Nodo *get_czo(void){return czo;}
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
                return -1; 
  }
  return czo-&gt;get_dato();
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo-&gt;get_next());
      return (l);
}

string Lista::toPrint(tipolista p)
{ 
     if (this-&gt;esvacia()) {
        return &quot;&quot;;
     } else {
       std::ostringstream stm;
       stm &lt;&lt; this-&gt;cabeza()&lt;&lt;&quot;-&quot;&lt;&lt; this-&gt;resto()-&gt;toPrint(p) &lt;&lt; endl;
       return stm.str();
     }
}
//mostrar que solo cambia la parte de procesemiento individual en cada funcion

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

//------------------------------------------------------------------------

class Cola{
      private:
              Lista *l;
              Nodo *czoq;
              void update_start(Lista *l,Nodo *p);
              void do_desencolar(Nodo *p,Nodo *s);
      public:
      Cola(void){l=new Lista();update_start(l,NULL);};
      ~Cola(void) {delete(l);};
      int tope();
      int colavacia() { return l-&gt;esvacia();};
      void encolar(int a) ;
      void desencolar();
      void pop_q();
};
int Cola::tope() {
           if (colavacia()&gt;0){
              cout&lt;&lt;&quot;Error: Cola vacia&quot;&lt;&lt;endl;
              return -1;
           } 
           else
              return czoq-&gt;get_dato();
}

void Cola::encolar(int a) {
     l-&gt;add(a);
     if (czoq==NULL) {
        update_start(l,czoq);
     }
}
void Cola::pop_q()
{ Nodo *aux, *ant;
  aux=l-&gt;get_czo();
  while(aux!=czoq){
                   ant=aux;
                   aux=aux-&gt;get_next();
                   }
  delete(czoq-&gt;get_next());
  czoq-&gt;set_next(NULL);
  czoq=ant;
}
void Cola::desencolar() {
           if (colavacia()&gt;0)
              cout&lt;&lt;&quot;Error: Cola vacia&quot;&lt;&lt;endl;
           else {
              do_desencolar(l-&gt;get_czo(),NULL);
              update_start(l,NULL);
           }
}

void Cola::do_desencolar(Nodo *p,Nodo *s){
     if (p-&gt;get_next()==NULL) {
        if (s!=NULL) {
           s-&gt;set_next(NULL);
        }
        delete(p);
     } else {
        this-&gt;do_desencolar(p-&gt;get_next(),p);
     }
}
void Cola::update_start(Lista *l,Nodo *p){
     if (l-&gt;esvacia()) {
        czoq=p;
     } else {
        this-&gt;update_start(l-&gt;resto(),l-&gt;get_czo());
     }
}

int main(){
    Cola *c=new Cola();
    if (c-&gt;colavacia()) cout&lt;&lt;endl&lt;&lt;&quot;La cola esta VACIA&quot;&lt;&lt;endl;
/*
    c-&gt;encolar(1);
    c-&gt;encolar(2);
    c-&gt;encolar(3);

    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
    c-&gt;desencolar();
//    c-&gt;pop_q();
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
    c-&gt;desencolar();
//    c-&gt;pop_q();
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
    c-&gt;desencolar();
//    c-&gt;pop_q();
    c-&gt;encolar(4);
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
    c-&gt;desencolar();
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
*/
    cout&lt;&lt;&quot;inicia el llenado&quot;&lt;&lt;endl;
    for(int i=1;i&lt;5000000;i++){
       c-&gt;encolar(i);
    }
    cout&lt;&lt;&quot;fin del llenado&quot;&lt;&lt;endl;
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
    cout&lt;&lt;&quot;inicia el desencolar&quot;&lt;&lt;endl;
//    c-&gt;desencolar();
    c-&gt;pop_q();
    cout&lt;&lt;&quot;fin del desencolar&quot;&lt;&lt;endl;
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
       
//    system(&quot;PAUSE&quot;);
    return EXIT_SUCCESS;
    
}


</p></pre>