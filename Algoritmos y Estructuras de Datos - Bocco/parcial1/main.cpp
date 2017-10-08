#include <cstdlib>
#include <iostream>

using namespace std;

#include "Matrizrala.h"

int rango(FILE*);
void cargarNodoralos(FILE*);
Matrizrala* sumarMatriz (Matrizrala*, Matrizrala*); 
Matrizrala* multiplicarMatriz (Matrizrala* , Matrizrala* );

int main ()
{
    int r;
    int r2;
    FILE *fp;
    FILE *fp2;
    fp = fopen ("Archivo.txt","r");
    fp2 = fopen ("Archivo2.txt","r");    


    r = rango(fp);
    r2 = rango(fp2);
    Matrizrala* B=new Matrizrala(r);
    Matrizrala* C=new Matrizrala(r2);
    
    B->recibirDatos(fp);
    C->recibirDatos(fp2);
    
    Matrizrala* suma = sumarMatriz(B,C)
    Matrizrala* multi = multiplicarMatriz(B,C);

    suma->imprimirMatriz()
    multi->imprimirMatriz();
    
      
    
    system("pause");
}

int rango(FILE *fp)
{
    int r;
    fp = fopen ("Archivo.txt","r");
    r= fgetc(fp)-'0';
    fclose(fp);
    return r;
}

Matrizrala* sumarMatriz (Matrizrala* b, Matrizrala* c)   
{
           int r;
           r = b->getRango();
           Matrizrala* resultado=new Matrizrala(r);
           
          
           for(int i =1 ; i <= r ; i++ )
               {
                      
                   for (int j = 1; j <= r; j++)
                   {
                       int re = b->buscarNodoralo(i,j) + c->buscarNodoralo(i,j);
                       if(re != 0 )
                       {
                       resultado->add_Nodoralo(re, i, j);
                       }

                    }
               }
              return resultado;
} 
  


Matrizrala* multiplicarMatriz (Matrizrala *b, Matrizrala *c)
{
           int r;
           int res;
           r = b->getRango();
           Matrizrala* resultado = new Matrizrala(r);
           
           for(int i=1;i<=r;i++){
                   for(int j=1;j<=r;j++){
                           res=0;
                           for(int k=1;k<=r;k++){
                           res=(res + (b->buscarNodoralo(i,k)*c->buscarNodoralo(k,j)));
                           }
                           if (res != 0)
                           {
                           resultado->add_Nodoralo(res,i,j );
                           }
                           }}
                   
           return resultado;
           
           
}
