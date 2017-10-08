//Trabajo Práctico Nº 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct
{
 char nombre[20];
 long int dni;
 int anoingreso;
 } Estudiante;
 
int orden;

void cargestud(Estudiante *b,int max)
{
	for(int i=0;i<max;i++)
	{
           
    	char n[20];       
      	cout<<"\nIngrese el nombre del estudiante: ";
      	cin>>n;
      	strcpy((b+i)->nombre,n);
      
      	cout<<"\nIngrese su DNI: ";
      	cin>>(b+i)->dni;
      
      	cout<<"\nIngrese su anio de ingreso: ";
      	cin>>(b+i)->anoingreso; 
      	
 	}
}

void imprestud(Estudiante *a,int max)
{ 
	for(int i=0;i<max;i++)
	{
	printf("\nEstudiante: %s  -  DNI: %ld  -  Anio de ingreso: %d\n",(a+i)->nombre,(a+i)->dni,(a+i)->anoingreso);
	}
}

void ordenar(Estudiante *est, int max)
{
	if (orden == 1)
	{	
    	for(int cuenta=1; cuenta < max; cuenta++)
		{
        	for (int i=0; i < max-1; i++)
			{	
                  	if(strcmp((est+i)->nombre, (est+(i+1))->nombre) > 0)
					{
                  		Estudiante aux = *(est+i);
                    	*(est+i) = *(est+(i+1));
                    	*(est+(i+1)) = aux;
					}
            }
        }   
    }
     
     else if (orden == 2)
	 {
    	for(int cuenta=1; cuenta < max; cuenta++)
		{
        	for (int i=0; i < max-1; i++)
			{
            	if ((est+i)->dni > (est+(i+1))->dni)
                      {
                          Estudiante aux = *(est+i);
                          *(est+i) = *(est+(i+1));
                          *(est+(i+1)) = aux;
                      }
            }
        }
     }
     
     else if (orden == 3)
	 {
    	for(int cuenta=1; cuenta < max; cuenta++)
		{
        	for (int i=0; i < max-1; i++)
			{
            	if ((est+i)->anoingreso > (est+(i+1))->anoingreso)
                {
                	Estudiante aux = *(est+i);
                    *(est+i) = *(est+(i+1));
                    *(est+(i+1)) = aux;
                }
            }
        }
     }
               
 }
 
int main(int argc, char *argv[]){
 	
 	Estudiante *est;
 	int maxest;
 	
 	cout<<"Ingrese la cantidad de estudiantes: ";
 	cin>>maxest;
 	
 	est=(Estudiante*)malloc(sizeof(Estudiante)*maxest);
 	cargestud(est,maxest);
 	
 	cout << "\nIntroduzca 1 para ordenar estudiantes por nombre,\n" 
         << "2 para ordenar estudiantes por DNI,\n"
         << "3 para ordenar estudiantes por fecha de ingreso: ";
    cin >> orden;
    
    cout << "\nEstudiantes ingresados en el orden original: \n";
 	imprestud(est,maxest);
 	
 	ordenar (est, maxest);
 	
 	cout << "\nEstudiantes despues de ordenarlos: \n";
 	
 	imprestud(est,maxest);
 	free (est);
 	
 system("PAUSE");

     return 0;
}	
