<pre><p>// Metodo de Ordenamiento por Seleccion Directa
// Wirth pag. 68
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

void impre(int *v);

int main(int argc, char *argv[])
{int i,j,pos,aux,m=0,c=0;
 int a[5]={50,40,30,20,10}; //
 impre(a);
 puts(&quot;\n---------------------------------&quot;);
 for(i=0;i&lt;4;i++){
   aux=a[i]; pos=i; m++;
   for(j=i+1;j&lt;5;j++){
     c++;
     if(a[j]&lt;aux){
       aux=a[j]; m++;
       pos=j;
     }
   }
   a[pos]=a[i]; m++; a[i]=aux; m++ ;
   //impre(a);getch();
 }
  impre(a);
// ---------       Mmin= 3(n-1)
// C= 1/2(n**2-n)  Mmed= ??
// --------------  Mmax= (n**2/4)+3(n-1)
 
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