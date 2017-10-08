/* Metodo de ordenacion
      Shell sort     */
#include <stdio.h>
#include <malloc.h>
#include <iostream>
int rango_optimo(int, int);

using namespace std;

int a[100], m=0;

void printarr(int * arr){
    for (int i=0;i<100;i++)
       cout<<*(arr+i)<<endl;
    cout<<"fin array"<<endl;
}

void swap(int *x,int*y){
     int tmp=*x;
     *x=*y;
     *y=tmp;
     m++;
}

int * pasoins(int *a,int ip, int k){
    if (ip<k){
       return a;
    } else {
       if (*(a+ip)<*(a+(ip-k))){
          //printf("cambio %4d con %4d \n", *(a+ip), *(a+(ip-k)));
          swap(a+ip,a+(ip-k));}
       return pasoins(a,ip-k, k);
    } 
}

int * sortins(int *a,int ip,int count, int rango){
     if (count>ip){
                   count = rango_optimo(rango, 0);
                   if(count==0)
                         return a;
                   else 
                        return sortins(pasoins(a,count,count),ip,count+1,count); 
     } 
     else  return sortins(pasoins(a,count,rango),ip,count+1,rango);
}

int rango_optimo(int n, int h){
    if(h*3+1<n) 
            return rango_optimo(n, (h*3+1));
    else {
         cout<<"\nEl salto es de "<<h<<endl;
         return h;
    }
}

int main(int argc, char *argv[]){
    int n=100, k, a[100]={46, 62, 49, 95, 65, 22, 79, 13, 29, 98,
                          63, 3, 99, 33, 57, 61, 30, 8, 24, 65, 
                          86, 89, 82, 62, 72, 92, 13, 50, 5, 56, 
                          56, 0, 2, 72, 40, 41, 72, 11, 18, 56, 
                          81, 32, 91, 87, 91, 42, 21, 80, 12, 84, 
                          74, 68, 85, 68, 50, 51, 95, 21, 26, 0, 
                          71, 89, 81, 34, 72, 56, 18, 99, 22, 62, 
                          0, 36, 18, 91, 21, 9, 32, 53, 78, 91, 
                          32, 45, 33, 91, 68, 66, 57, 32, 66, 30, 
                          38, 8, 26, 19, 44, 75, 65, 85, 58, 37};
    
    k=rango_optimo(n,0); 
    int *d=sortins(a,99,k, k);
    printarr(d);
    
    cout<<"\nLa cantidad de movimientos realizados fue "<<m<<endl;
    system("PAUSE");
    return 0;
}
