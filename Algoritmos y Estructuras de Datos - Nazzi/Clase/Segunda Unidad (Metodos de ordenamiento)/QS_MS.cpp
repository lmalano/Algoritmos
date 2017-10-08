<pre><p>// metodo de ordenamiento Quick Sort y Merge Sort
#include &lt;cstdlib&gt;
#include &lt;iostream&gt;

using namespace std;

void ordenaQS(int v[], int primero, int ultimo);
int ordenaMS(int a[], int low, int high);
int merge(int a[], int low, int high, int mid);
void impre(int v[], int n);

int main(int argc, char *argv[])
{   int A[10]={30,45,130,70,100,150,30,140,18,110};
    //ordenaQS(A,0,9);
    ordenaMS(A,0,9);
    impre(A,10);
    cout&lt;&lt;endl;
    system(&quot;PAUSE&quot;);
    return EXIT_SUCCESS;
}

void ordenaQS(int v[], int primero, int ultimo)
{ int i,j,k,pivot,aux;
      if(ultimo&gt;primero){
             pivot=v[ultimo];
             printf(&quot;\n -&gt; %d  %d &lt;-%4i&quot;,primero,ultimo,pivot);
             i=primero-1; j=ultimo;      
             for(;;){
                     while(v[++i]&lt;pivot);
                     while(v[ --j ] &gt;pivot);
                     if(i&gt;=j)break;
                     aux=v[i];v[i]=v[j];v[j]=aux;      
             }// fin for
             aux=v[i];v[i]=v[ultimo];v[ultimo]=aux;
             for(k=0;k&lt;10;k++)printf(&quot;\n a[%d]=%d&quot;,k,v[k]);
             printf(&quot;\n ------------------------------------&quot;);
             ordenaQS(v,primero,i-1);
             ordenaQS(v,i+1,ultimo);
             printf(&quot;\nRETORNO -&gt; %d  %d &lt;-&quot;,primero,ultimo);
      } //fin if 
}// fin ordena

int ordenaMS(int a[], int low, int high)
{   int mid;
    if(low&lt;high){
                 mid=(low+high)/2;
                 cout&lt;&lt;&quot;\n llamo a ordenaMS(1) con low= &quot;&lt;&lt;low&lt;&lt;&quot; mid= &quot;&lt;&lt;mid&lt;&lt;endl;
                 ordenaMS(a,low,mid);
                 cout&lt;&lt;&quot;\n llamo a ordenaMS(2) con mid+1= &quot;&lt;&lt;mid+1&lt;&lt;&quot; high= &quot;&lt;&lt;high&lt;&lt;endl;
                 ordenaMS(a,mid+1,high);
                 merge(a,low,high,mid);
    }
    return(0);
}

int merge(int a[], int low, int high, int mid)
{   int i, j, k, c[20];
    cout&lt;&lt;&quot;\n Estoy en merge() con low= &quot;&lt;&lt;low&lt;&lt;&quot; high= &quot;&lt;&lt;high&lt;&lt;&quot; mid= &quot;&lt;&lt;mid&lt;&lt;endl;
    system(&quot;PAUSE&quot;);
    i=low; j=mid+1; k=low;
    
    while((i&lt;=mid)&amp;&amp;(j&lt;=high)){
         if(a[i]&lt;a[j]){
                c[k]=a[i];
                k++; i++;
         }
         else{
                c[k]=a[j];
                k++; j++;
         }
    }
    while(i&lt;=mid){ c[k]=a[i]; k++; i++; }
    while(j&lt;=high){c[k]=a[j]; k++; j++; }
    for(i=low;i&lt;k;i++) a[i]=c[i];
} 

void impre(int v[], int n)
{  
     for(int i=0;i&lt;n;i++) cout&lt;&lt;endl&lt;&lt;v[i];
}
</p></pre>