#include <cstdlib>
#include <iostream>

using namespace std;

#include "Matrizrala.h"

int rango(FILE*);
void cargarNodoralos(FILE*);

int main ()
{
    int r;
    FILE *fp;
    fp = fopen ("Archivo.txt","r");
    

   
    r = rango(fp);
    Matrizrala B (r);
    B.recivirDatos(fp);
    B.imprimirMatriz();

    
    
    
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
