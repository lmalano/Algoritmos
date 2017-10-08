#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

int a[9];//={2,8,21,4,10,6,7,9,1};

void initarr(){
     a[0]=2;
     a[1]=21;
     a[2]=4;
     a[3]=10;
     a[4]=6;
     a[5]=8;
     a[6]=9;
     a[7]=1;
     a[8]=12;
}

void printarr(int * arr){
    for (int i=0;i<9;i++)
       cout<<*(arr+i)<<endl;
    cout<<"fin array"<<endl;
    
}
void swap(int *x,int*y){
     int tmp=*x;
     *x=*y;
     *y=tmp;
}

int * pasoins(int *a,int ip){
    if (ip==0){
       return a;
    } else {
       if (*(a+ip)<*(a+(ip-1)))
          swap(a+ip,a+(ip-1));
       return pasoins(a,ip-1);
    } 
}

int * sortins(int *a,int ip,int count){
     if (count>ip){
         return a;
     } else {
         return sortins(pasoins(a,count),ip,count+1);
     }
}

int main(int argc, char *argv[]){
    initarr();
    int *d=sortins(a,8,1);
    cout<<"sort insercion"<<endl;
    printarr(d);
    system("PAUSE");
    return 0;
}
