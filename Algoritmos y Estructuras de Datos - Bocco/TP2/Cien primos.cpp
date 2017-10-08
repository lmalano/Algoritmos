#include<iostream>
#include <iomanip> 
#include<conio.h> //para usar getch()
using namespace std;

//Prototipos

int resto(int,int);
bool esdiv(int,int);
bool primo(int,int*);
int* cienp(int*,int,int);
int* poner(int*,int,int);
int cabeza(int*);
int* cola(int*);


int main()
{
    int lp[100];//Crea un arreglo con 100 espacios
    
    for(int i=0;i<100;i++)
    {lp[i]=NULL;} //Inicializo el arreglo con "NULL"
    
    cienp(lp,0,1); //Llamo a la funcion cienp()
    
    cout<<"             :::: TABLA DE LOS 100 PRIMEROS NUMEROS PRIMOS ::::"<<endl<<endl;
    
    for(int i=0;i<100;i++) //Me muestra el arreglo luego de haber utilizado "cienp"
    {
            cout<< setw(3)<< lp[i]<<" ";
    }
    
    
    getch(); //En este caso, se usa para esperar a que se presione una tecla, es analogo a system("PAUSE")
    return 0;
}

/* La funci�n resto(int x, int y) calcula el resto de dividir x por y
utilizando recursi�n
Ejemplo: resto(5,3)
5<3? NO
5>=3? SI -> resto(2,3)
2<3? SI -> devuelve 2 */
int resto(int x, int y) 
{
    if(x<y){return x;}
    
    if(x>=y){return resto(x-y,y);}
}

/* La funci�n esdiv(int x, int y) simplemente verifica si x es divisible por y, analizando
si el resto entre esos numeros es 0, y en funci�n de ello devuelve
true o false */
bool esdiv(int x, int y)
{
    if(resto(x,y) == 0){return true;}
    
    else{return false;}
}

/* La funci�n primo(int x, int *lp) verifica si un numero es o no primo, comparandolo con
un arreglo de numeros primos.
Ejemplo: suponemos un arreglo de 3 elementos lp[3]={2,3,NULL}

primo(4,lp) (la funci�n toma los valores por referencia)
El puntero est� apuntando al espacio de memoria donde est� "2", por ende, la primera condicion no se cumple
Verifiquemos la segunda condicion: 4 es divisible por 2? SI, entonces 4 NO ES PRIMO.

primo(5,lp)
La primera condici�n no se cumple y la segunda tampoco (5 no es divisible por 2)
Se cumple la tercera condici�n, entonces: primo(5,{3,NULL})
La primera condicion no se cumple y la segunda rampoco (5 no es divisible por 3)
Se cumple la tercera condici�n,entonces: primo(5,{NULL})
Se cumple la primer condici�n, entonces: 5 ES PRIMO */
bool primo(int x, int *lp)
{

     if(*lp == NULL){return true;}

     if(*lp != NULL && esdiv(x,cabeza(lp))){return false;}

     if(*lp != NULL && !esdiv(x,cabeza(lp))){return primo(x,cola(lp));}
}

/* La funci�n cienp(int *lp,int pos,int x) va guardando los numeros que son primos en el arreglo
previamente creado e inicializado en la funci�n main(). El puntero "lp" apunta a la direcci�n de memoria
del primer elemento del arreglo del main(). "pos" se utiliza para saber en que posicion del arreglo debo guardar mi
valor. "x" es el contador que va aumentando a razon de 1 cada vez que vuelve a entrar a la funci�n cienp
 y se va verificando si es o no es primo.
 Si "x" no es primo, simplemente se vuelve a entrar a la funci�n con x+1
 Si "x" es primo se vuelve a entrar a la funci�n con x+1 y pos+1, pero ahora el
 arreglo incluye a "x" en la posici�n correspondiente. */
int* cienp(int *lp,int pos,int x)
{
    if(pos>100){return lp;}
    
    if(pos<=100 && primo(x,lp)){return cienp(poner(lp,pos,x),pos+1,x+1);}
    
    if(pos<=100 && !primo(x,lp)){return cienp(lp,pos,x+1);}
    
}

/* La funci�n poner(int *lp,int pos,int x) pone el valor "x" en la posici�n "pos-1" del arreglo "lp", el cual
paso sus valores por referencia, y lo manejamos dentro de la funci�n con el puntero "*lp" */
int* poner(int *lp,int pos,int x)
{
     *(lp+pos-1)=x;
     return lp;
}

/* La funci�n cabeza(int *cab) me devuelve el primer elemento de un arreglo. Se hizo pasaje de valores
por referencia. */
int cabeza(int *cab)
{
    return cab[0];
}

/* La funci�n cola(int *col) recibe un arreglo y me devuelve el mismo arreglo pero decapitado O_O */
int* cola(int *col)
{
    return col+1;
}
