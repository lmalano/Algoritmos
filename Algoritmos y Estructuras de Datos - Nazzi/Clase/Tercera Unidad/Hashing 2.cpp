<pre><p>// <a class="resource autolink" title="Hashing" href="http://lev.efn.uncor.edu/mod/resource/view.php?r=15016" >hashing</a>
#include&lt;stdio.h&gt;
#include &lt;iostream&gt;
#include &lt;conio.h&gt;
#include &lt;string.h&gt;
#define MAX 10

struct archivo{
   int   n;   char  d[20];   float  r; int next;
};

int hash(char *n);
int sizeArchivo(FILE *arch);
void ImpreArchivo(FILE *arch);

using namespace std;

int main (int argc, char *argv[])
{ struct archivo  dato, dl;
  float f;  FILE *arch;  char ch;  int i,pos;
  arch=fopen(&quot;datth.dat&quot;,&quot;w+b&quot;);
  if (arch!=NULL){
      dato.n=-11; strcpy(dato.d,&quot;xyz&quot;); dato.r=-11; dato.next=0;
      for(i=0;i&lt;MAX;i++) fwrite(&amp;dato,sizeof(struct archivo),1,arch);
      cout&lt;&lt;&quot;\n Tamanio del archivo= &quot;&lt;&lt;sizeArchivo(arch)&lt;&lt;endl;
      ch='G';
      do{ if(ch=='G'){
             cout&lt;&lt;&quot;\n Tamanio del archivo= &quot;&lt;&lt;sizeArchivo(arch)&lt;&lt;endl;
             printf(&quot;\n\n ingrese un entero : &quot;); scanf(&quot;%d&quot;,&amp;dato.n);
             printf(&quot; ingrese una cadena: &quot;); fflush(stdin);gets(dato.d);
             printf(&quot; ingrese un real   : &quot;); scanf(&quot;%f&quot;,&amp;dato.r);
             dato.next=0;
             pos=hash(dato.d);
             fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
             fread(&amp;dl,sizeof(struct archivo),1,arch);
             if(dl.n==-11){
                  fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
                  fwrite(&amp;dato,sizeof(struct archivo),1,arch);
             }
             else{
                  while(dl.next!=0){
                        pos=dl.next;
                        cout&lt;&lt;&quot;estoy en el while pos= &quot;&lt;&lt;pos&lt;&lt;endl;
                        fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
                        fread(&amp;dl,sizeof(struct archivo),1,arch);
                  }//fin mientras
                  //encadeno con el final
                  dl.next=sizeArchivo(arch);
                  fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
                  fwrite(&amp;dl,sizeof(struct archivo),1,arch);
                  //grabo al final el nuevo dato
                  fseek(arch,0,SEEK_END);
                  fwrite(&amp;dato,sizeof(struct archivo),1,arch);
                  
             }
          }//fin Graba
          else {
             printf(&quot;\n ingrese una cadena: &quot;);fflush(stdin);gets(dato.d);
             pos=hash(dato.d);
             fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
             fread(&amp;dl,sizeof(struct archivo),1,arch);i=0;
             cout&lt;&lt;&quot;\n dato leido = &quot;&lt;&lt;dl.d;
             while((strcmp(dl.d,dato.d)!=0)&amp;&amp;(dl.next!=0)){
                 pos=dl.next;
                 fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
                 fread(&amp;dl,sizeof(struct archivo),1,arch);
                 cout&lt;&lt;&quot;\n dato leido = &quot;&lt;&lt;dl.d;
             }//fin mientras
             if (strcmp(dl.d,dato.d)!=0) printf(&quot;\n el dato NO esta &quot;);
             else{
                 fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
                 fread(&amp;dato,sizeof(struct archivo),1,arch);
                 printf(&quot;\n DATO LEIDO= %5d %20s %8.2f&quot;,dato.n,dato.d,dato.r);
             }//fin encontro
          }//fin Lee
          ImpreArchivo(arch);
          printf(&quot;\n\n desea Leer, Grabar o Salir: &quot;);ch=toupper(getche());
      }while(ch!='S');
      fclose(arch);
  }//fin arch!= NULL....
  return 0;
}//fin Main

int hash(char *n)
{ int i,j,l;
    l=strlen<img alt="no" width="15" height="15" src="http://lev.efn.uncor.edu/pix/s/no.gif" />; j=0;
    for(i=0;i&lt;l;i++) j=j ^ n[i];
    cout&lt;&lt;&quot;\n pos= &quot;&lt;&lt;j%MAX;
    return j % MAX;
}
int sizeArchivo(FILE *arch)
{   int t;
    fseek(arch,0,SEEK_END);
    t=ftell(arch)/sizeof(struct archivo);
    return t;
}
void ImpreArchivo(FILE *arch){
struct archivo  dato; 
int n;
n=sizeArchivo(arch);    
cout&lt;&lt;endl&lt;&lt;&quot;Datos en el archivo&quot;&lt;&lt;endl;
      fseek(arch,0,SEEK_SET);
      for(int i=0;i&lt;n;i++){
                         fread(&amp;dato,sizeof(struct archivo),1,arch);
                         printf(&quot;\n%3d DATO LEIDO= %5d %20s %8.2f %3d&quot;,i,dato.n,dato.d,dato.r,dato.next);
      }
}
</p></pre>