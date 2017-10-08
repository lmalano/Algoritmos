<pre><p>// Metodo de Ordenamiento por Intercambio Directo (Burbuja)
// Wirth pag. 71
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

void impre(int *v);

int main(int argc, char *argv[])
{int i,j,pos,aux,m=0,c=0;
 int a[5]={50,40,30,20,10}; //
 impre(a);
 puts(&quot;\n---------------------------------&quot;);
 
 for(i=0;i&lt;4;i++){
    for(j=0;j&lt;4-i;j++){
        c++;               
        if(a[j]&gt;a[j+1]){
            aux=a[j]; a[j]=a[j+1]; a[j+1]=aux; m=m+3;
        }                   
    }
 }
  impre(a);
// ---------       Mmin= 0
// C= 1/2(n**2-n)  Mmed= 3/4(n**2-n)
// --------------  Mmax= 3/2(n**2-n)
   
  printf(&quot;\n cantidad de comparaciones= %d  movimientos= %d&quot;,c,m);
  printf(&quot;\n\n&quot;);
  system(&quot;PAUSE&quot;);	
  return 0;
}
void impre(int *v)
{ int i;
  printf(&quot;\n&quot;);
  for(i=0;i&lt;5;i++)
     printf(&quot;\n %3d   %3d&quot;,i,v[i]);
}
</p></pre>