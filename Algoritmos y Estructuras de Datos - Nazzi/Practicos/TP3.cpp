#include <iostream>
#include <stdio.h>
#include <stdlib.h>
void impre(int []);
int rango_optimo(int);

using namespace std;

int main(){
      int i, j, k, di,m=0, c=0, n=100, a[100]={46, 62, 49, 95, 65, 22, 79, 13, 29, 98,
                                               63, 3, 99, 33, 57, 61, 30, 8, 24, 65, 
                                               86, 89, 82, 62, 72, 92, 13, 50, 5, 56, 
                                               56, 0, 2, 72, 40, 41, 72, 11, 18, 56, 
                                               81, 32, 91, 87, 91, 42, 21, 80, 12, 84, 
                                               74, 68, 85, 68, 50, 51, 95, 21, 26, 0, 
                                               71, 89, 81, 34, 72, 56, 18, 99, 22, 62, 
                                               0, 36, 18, 91, 21, 9, 32, 53, 78, 91, 
                                               32, 45, 33, 91, 68, 66, 57, 32, 66, 30, 
                                               38, 8, 26, 19, 44, 75, 65, 85, 58, 37};
      k = rango_optimo(n);
      printf("\n\n k = %4d ", k);
      while(k>0){
            for(i=k;i<100;i++){             
                   j=i-k; di=a[i];                       
                   while(di<a[j] && j>=0){       
                               a[j+k]=a[j];      
                               j=j-k;
                               m++;
                   }
                   a[j+k]=di; m++; c++;
            }
            k=(k-1)/3;     
      }
    
    impre(a);

    printf("\n cantidad de comparaciones= %d  movimientos= %d",c,m);
    printf("\n\n");
       
    system("pause");
    return 0;
}

void impre(int *v){
     int i;
     printf("\n");
     for(i=0;i<100;i++)
                     printf("\n %3d   %3d",i,v[i]);
}

int rango_optimo(int n){
    int h=0;
    while(h*3<100)
                h=h*3+1;
    return h;    
}
