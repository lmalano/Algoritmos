<pre><p>#include &lt;cstdlib&gt;
#include &lt;iostream&gt;

using namespace std;

class Cola{
//esta implementacion de un tipo de datos COLA es solo a los fines didacticos
//resta implementar como cola circular
      private:
              int *data;
              int size;
              int begin;
              int end;
      public:
      Cola(void);
      Cola(int tam);
      ~Cola(void) {free(data);};
      int tope() {
           if (colavacia()&gt;0){
              cout&lt;&lt;&quot;Error: Cola vacia&quot;&lt;&lt;endl;
              return -1;
           } else
              return *(data+begin-1);
      };
      int colavacia() { return (begin-1)==end;};
      void encolar(int a) ;
      void desencolar();
};

Cola::Cola() {
   size=100;
   data= (int *) malloc(sizeof(int)*size);
   if (data==NULL) {
      cout&lt;&lt;&quot;Error de solicitud de memoria&quot;&lt;&lt;endl;
      exit;
   }
   begin=1;
   end  =0;
}

Cola::Cola(int tam) {
   size=tam;
   data= (int *) malloc(sizeof(int)*size);
   if (data==NULL) {
      cout&lt;&lt;&quot;Error de solicitud de memoria&quot;&lt;&lt;endl;
      exit;
   }
   begin=1;
   end  =0;
}

void Cola::encolar(int a) {
     if ((end+1)&gt;size) {
        cout&lt;&lt;&quot;Error:cola llena&quot;&lt;&lt;endl;
        exit;
     }
     *(data+end)=a;
     end++;
}

void Cola::desencolar() {
     if (!colavacia()){
        begin++; 
     }
}

int main(){
    Cola *c=new Cola(5000000);
/*
    c-&gt;encolar(1);

    c-&gt;encolar(2);
    c-&gt;encolar(3);

    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;

    c-&gt;desencolar();
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
    c-&gt;desencolar();
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
    c-&gt;desencolar();
    c-&gt;encolar(4);
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
    c-&gt;desencolar();
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
*/    
    cout&lt;&lt;&quot;inicia el llenado&quot;&lt;&lt;endl;
    for(int i=1;i&lt;=5000000;i++){
       c-&gt;encolar(i);
    }
    cout&lt;&lt;&quot;fin del llenado&quot;&lt;&lt;endl;
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
    cout&lt;&lt;&quot;inicia el desencolar&quot;&lt;&lt;endl;
    c-&gt;desencolar();
    cout&lt;&lt;&quot;fin del desencolar&quot;&lt;&lt;endl;
    cout&lt;&lt;&quot;en cola:&quot;&lt;&lt;c-&gt;tope()&lt;&lt;endl;
    
//    system(&quot;PAUSE&quot;);
    return EXIT_SUCCESS;
    
}

</p></pre>