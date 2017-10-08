// Metodo de Ordenamiento por Insercion Directa
// Wirth pag. 65
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
void impre(int *v);
using namespace std;
int main(int argc, char *argv[]){
    int i,j,k,di,m=0,c=0;
    int a[7]={50,40,30,20,10}; // peor caso ordenado al reves
    impre(a);
    cout<<"\n\n";
    for(i=1;i<5;i++){
             j=i-1; di=a[i];m++; c++;
             while(di<a[j] && j>=0){
                      a[j+1]=a[j]; m++ ;c++;
                      j--;cout<<"j vale "<<j<<endl;
             }
             a[j+1]=di;     m++ ;
    }
    impre(a);
// Cmin= n-1  Mmin= 2(n-1)
// Cmed= 1/4(n**2+n-2)  Mmed= 1/4(n**2+9n-10)
// Cmax= 1/2(n**2+n)-1  Mmax= 1/2(n**2+3n-4)
 
    printf("\n cantidad de comparaciones= %d  movimientos= %d",c,m);
    printf("\n\n");
  
    system("PAUSE");	
    return 0;
}

void impre(int *v){
     int i;
     printf("\n");
     for(i=0;i<5;i++)
                     printf("\n %3d   %3d",i,v[i]);
}
