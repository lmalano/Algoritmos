#include <iostream>

#include "Cola.cpp"

using namespace std;


void ordenarCola(char M[10]);

void imprimirCola(int val, char M[10]);




int main()
{
    char M[10];
    
    M[0]='F';
    M[1]='J';
    M[2]='B';
    M[3]='H';
    M[4]='J';
    M[5]='B';
    M[6]='B';
    M[7]='@';
    M[8]='B';
    M[9]='A';
    M[10]='Z';
    imprimirCola(10,M);
    
    ordenarCola(M);
    ordenarCola(M);
    ordenarCola(M);
    ordenarCola(M);
    
    
    imprimirCola(10,M);
    system("PAUSE");
    
    
}

void imprimirCola(int val, char M[])
{
     for(int i=0;i<val;i++)
     {
             
             cout<<M[i]<<" ";
      }
      cout<<endl<<endl;
      
      
      for(int i=0;i<val;i++)
     {
             int a=M[i];
             cout<<a<<" ";
      }
      cout<<endl<<endl;
}



void ordenarCola(char M[10])
{
     int iMax=0;
     for(int i=0;i<9;i++)
     {
             iMax=0;
     
             for (int j=i+1;j<10;j++)
             {
                 int aa=M[j];
                 int bb=M[i];
                 if(M[j]<M[i])
                 {
                     iMax=j;
                 }
                 
             }
             if(iMax!=0)
             {
                        
                  char a=M[i];
                  char b=M[iMax];
                  M[i]=b;
                  M[iMax]=a;
             }
             
             
}
     
     
     
}
