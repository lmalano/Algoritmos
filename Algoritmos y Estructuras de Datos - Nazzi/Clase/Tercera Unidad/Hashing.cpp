//<pre><p>// <a class="resource autolink" title="Hashing" href="http://lev.efn.uncor.edu/mod/resource/view.php?r=15016" >hashing</a>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
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
  arch=fopen("datth.dat","w+b");
  if (arch!=NULL){
      dato.n=-11; strcpy(dato.d,"xyz"); dato.r=-11; dato.next=0;
      for(i=0;i<MAX;i++) fwrite(&dato,sizeof(struct archivo),1,arch);
      cout<<"\n Tamanio del archivo= "<<sizeArchivo(arch)<<endl;
      ch='G';
      do{ if(ch=='G'){
             printf("\n\n ingrese un entero : "); scanf("%d&",&dato.n);
             printf("ingrese una cadena: "); fflush(stdin);gets(dato.d);
             printf(" ingrese un real   : "); scanf("%f",&dato.r);
             dato.next=0;
             pos=hash(dato.d);
             fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
             fread(&dl,sizeof(struct archivo),1,arch);
             while(dl.n!=-11){
                 pos=(pos+1) % MAX;
                 fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
                 fread(&dl,sizeof(struct archivo),1,arch);
             }//fin mientras
             fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
             fwrite(&dato,sizeof(struct archivo),1,arch);
          }//fin Graba
          else {
             printf("\n ingrese una cadena: ");fflush(stdin);gets(dato.d);
             pos=hash(dato.d);
             fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
             fread(&dl,sizeof(struct archivo),1,arch);i=0;
             cout<<"\n dato leido = "<<dl.d;
             while((strcmp(dl.d,dato.d)!=0)&&(i<MAX)){
                 pos=(pos+1) % MAX; i++;
                 fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
                 fread(&dl,sizeof(struct archivo),1,arch);
                 cout<<"\n dato leido = "<<dl.d;
             }//fin mientras
             if(i==MAX) printf("\n el dato NO esta ");
             else{
                 fseek(arch,pos*sizeof(struct archivo),SEEK_SET);
                 fread(&dato,sizeof(struct archivo),1,arch);
                 printf("\n DATO LEIDO= %5d %20s %8.2f",dato.n,dato.d,dato.r);
             }//fin encontro
          }//fin Lee
          ImpreArchivo(arch);
          printf("\n\n desea Leer, Grabar o Salir: ");ch=toupper(getche());
      }while(ch!='S');
      fclose(arch);
  }//fin arch!= NULL....
  return 0;
}//fin Main

int hash(char *n)
{ int i,j,l;
    l=strlen(n); j=0;
    for(i=0;i<l;i++) j=j ^ n[i];
    cout<<"\n pos= "<<j%MAX;
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
cout<<endl<<"Datos en el archivo"<<endl;
      fseek(arch,0,SEEK_SET);
      for(int i=0;i<MAX;i++){
                         fread(&dato,sizeof(struct archivo),1,arch);
                         printf("\n DATO LEIDO= %5d %20s %8.2f",dato.n,dato.d,dato.r);
      }
}
//</p></pre>
