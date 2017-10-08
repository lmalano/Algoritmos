// Metodo de Ordenamiento por Insercion Directa
// Wirth pag. 65
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

void impre(int *v);

int main(int argc, char *argv[])
{int i,j,k,di,m=0,c=0;
 int a[7]={50,40,30,20,10}; // peor caso ordenado al reves
 impre(a);

 for(i=1;i&lt;5;i++){
   j=i-1; di=a[i];m++; c++;
   while(di&lt;a[j] &amp;&amp; j&gt;=0){
      a[j+1]=a[j]; m++ ;c++;
      j--;
   }
   a[j+1]=di;     m++ ;
 }
  impre(a);
// Cmin= n-1  Mmin= 2(n-1)
// Cmed= 1/4(n**2+n-2)  Mmed= 1/4(n**2+9n-10)
// Cmax= 1/2(n**2+n)-1  Mmax= 1/2(n**2+3n-4)
 
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
