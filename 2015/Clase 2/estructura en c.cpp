#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
       int dia;
       int mes;
       int anio;
} FECHA;

typedef struct {
       char nombre[20];
       FECHA nac; //toma de la estructura anterior
       long int dni;
} persona;

//defino las estructuras FECHA y persona


void printfecha(FECHA *f){ 
		printf("dia:%d - mes:%d - anio:%d\n",f->dia,f->mes,f->anio);// imprime en pantalla la estructura fecha
}
//hago una funcion que me imprima la fecha mandada por direccion de memoria

void printpersona(persona *p){
	
    printf("nombre %s,dni %ld,nac:",p->nombre,p->dni);// imprime en pantalla la estructura persona
    printfecha(&(p->nac));
}
//hago una funcion que imprima la persona,y llama a la funcion anterior, ya que llama a la direccion de memoria de nac

