// Metodo de Ordenamiento por Intercambio Directo (Burbuja)
// Wirth pag. 71
#include <stdio.h>
#include <stdlib.h>
#define MAX 5000

void impre(int *v);

int main()
{int i,j,pos,aux,b,m=0,c=0;
 int a[MAX];//={50,40,30,20,10}; //
 for(i=0;i<MAX;i++){
                    a[i]=int(rand());
 }
 impre(a);
 puts("\n---------------------------------");
 i=0; b=1;
 //for(i=0;i<MAX;i++){
 while(b==1){ //sin while hace todas las pasadas, ya estando acomodado
    b=0;          
    for(j=0;j<MAX-i;j++){//for de cada uno de las pasdas
        c++;   //contador de comparaciones            
        if(a[j]>a[j+1]){
            aux=a[j]; a[j]=a[j+1]; a[j+1]=aux; m=m+3;//contador de movimientos m
            b=1;//se descativa junto con el while
        }                   
    }
    i++;//se descativa junto con el while
 }
  impre(a);
// ---------       Mmin= 0				//cantidad de movimiento minimo del metodo (arreglo ordenado)
// C= 1/2(n**2-n)  Mmed= 3/4(n**2-n) //cantidad de movimiento medio del metodo
// --------------  Mmax= 3/2(n**2-n) //cantidad de movimiento maximo del metodo
   
  printf("\n cantidad de comparaciones= %d  movimientos= %d",c,m);
  printf("\n\n");
  system("PAUSE");	
  return 0;
}
void impre(int *v)
{ int i;
  printf("\n");
  for(i=0;i<MAX;i++)
     printf("\n %3d   %3d",i,v[i]);
}
