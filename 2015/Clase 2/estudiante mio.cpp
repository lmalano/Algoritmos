#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct
{
 char nombre[100];
 long int dni;
 int anoingreso;
 int edad;//LE PUSE NOMBRE
 } Estudiante;
 
void cargestud(Estudiante *b,int max){
	
     for(int i=0;i<max;i++){
     	
      cout<<"ingrese el nombre del alumno"<<endl;            
      strcpy((b+i)->nombre," ");//CONVIERTE LA CADENA CHAR A STRING
      cin>>((b+i)->nombre);// para ingresar EL NOMBRE, SIN ESPACIOS 
      cout<<"ingrese su dni"<<endl;
      cin>>(b+i)->dni;
      cout<<"ingrese su anio de ingreso"<<endl;
      cin>>(b+i)->anoingreso;  
	  cout<<"ingrese su edad"<<endl;
      cin>>(b+i)->edad;   }      

}


void imprestud(Estudiante *a,int max){ 
		for(int i=0;i<max;i++){
			cout<<"alumno:"<<(a+i)->nombre<<"  DNI:"<<(a+i)->dni<<"  anio ingreso:"<<(a+i)->anoingreso<<" edad:"<<(a+i)->edad<<endl;}
		//printf("alumno:%s dni:%d - anoingreso:%d\n",(a+i)->nombre,(a+i)->dni,(a+i)->anoingreso);} NO SE USA EL PRINTF SI USAS STRING
		
}
 
 
void imprestudacom(Estudiante *a,int max){ //NO FUNCIONAAAAAAAAAAA
		for(int i=0;i<max;i++){
			{ int min=a->dni;
		  int temp; 
		 for(int j=i+1;j<max;j++)
			 {if((a+j)->dni<min)
				 {temp=a->dni;
				 a->dni=(a+j)->dni;
				 (a+j)->dni=temp;
				 cout<<"alumno: "<<(a+i)->nombre<<"  DNI: "<<(a+i)->dni<<"  anio ingreso: "<<(a+i)->anoingreso<<endl;}	
				 }
				 
			}		}
			
		
} 
 

void acomoda(Estudiante*d ,int max){ //no anda metodo de insercion directa para acomodar, acomoda si le pones dos alumnos
	
for(int i=0;i<max;i++)
 		{ int min=d->dni;
		  int temp; 
		 for(int j=i+1;j<max;j++)
			 {if((d+j)->dni<min)
				 {temp=d->dni;
				 d->dni=(d+j)->dni;
				 (d+j)->dni=temp;}
			}		}		 			   
}




 main(){
 	
 	Estudiante *est;
 	int maxest;
 	
 	cout<<"ingrese la cantidad de estudiantes"<<endl;
 	cin>>maxest;
 	
 	est=(Estudiante*)malloc(sizeof(Estudiante)*maxest);
 	cargestud(est,maxest);
 	imprestud(est,maxest);
 	
 cout<<"ahora los estudiantes se ordenaran por numero de dni"<<endl; //no anda
 imprestudacom(est,maxest);
 	
 	
 //	Estudiante *temp;
 //	temp=(Estudiante*)malloc(sizeof(Estudiante)*maxest);
 //	temp->dni;
 //	temp->anoingreso;
 	
 system("PAUSE");

     return 0;
}	
 
