#include<string> 
#include<iostream> 
#include<conio.h> 
#include<ctype.h> 
#include<stdio.h> 
#include<math.h> 
#include<stdlib.h> 
#include<Windows.h>

//-----pilas 
#define MAXPILA 100 
#define MAXCAD 100 

using namespace std;

struct numpila {float item[MAXPILA]; int cima;}; 
struct charpila {char item[MAXPILA]; int cima;}; 


//------prototipos 
void ide(); 
void menu(char *op); 
char *postnumero(char cadinf[100]); 
void validar(char cadinf[MAXCAD], int *err); 
void crear(charpila *pila); 
void push(charpila *pila,char valor,int *exito); 
char cima(charpila pila); 
int llena(charpila pila); 
int vacia(charpila pila); 
int llenala(numpila pila); 
int vaciala(numpila pila); 
char quitar(charpila *pila, int *exito); 
float quita(numpila *pila, int *exito); 
void ponla(numpila *pila,float valor,int *exito); 
void inicia(numpila *pila); 
float evaluar(char cadinf[MAXCAD]); 
void gotoxy(int x,int y);
//-------main 
int main() 
{ 
char cadinf[MAXCAD] = ""; 
char cadpost[MAXCAD] = ""; 
float res; 
int err=0; 
char op; 
do{ 
ide(); 
menu(&op); 
switch(op) 
{ 
case 'A': 
ide(); 
gotoxy(31,5); 
cout<<"Ingrese Operacion"; 
gotoxy(25,6); 
gets(cadinf); 
validar(cadinf, &err); 
if(err>0) 
{ 
strcpy(cadinf, " ") ;
} 
err=0; 
getch(); 
break; 

case 'B': 
ide(); 
strcpy(cadpost, postnumero(cadinf)); 
gotoxy(25,6); 
cout<<cadpost; 
getch(); 
break; 

case 'C': 
ide(); 
if (strlen(cadinf) == 0) 
{ 
gotoxy(26,6); 
cout<<"Ingrese Una operacion Valida"; 
getch(); 
} 
else 
{ 
res=evaluar(cadinf); 
gotoxy(26,5); 
cout<<cadinf<<" = "; 
gotoxy(25,6); 
cout<<res; 
getch(); 
} 
break; 

} 
}while(op != 'D'); 

} 

//----Subrutinas 

void ide() 
{ 

//construccion de marco 
int i; 
for(i=21; i<60; i++) 
{ 
gotoxy(i,3); 
cout<<"="; 
} 
for(i=21; i<60; i++) 
{ 
gotoxy(i,13); 
cout<<"="; 
} 
gotoxy(20,3); 
cout<<"*"; 
gotoxy(60,3); 
cout<<"*"; 
gotoxy(20,13); 
cout<<"*"; 
gotoxy(60,13); 
cout<<"*"; 
for(i=4; i<13; i++) 
{ 
gotoxy(20,i); 
cout<<"%"; 
} 
for(i=4; i<13; i++) 
{ 
gotoxy(60,i); 
cout<<"%"; 
} 
//construccion de pantalla 
//pantalla usable (25,6) 
gotoxy(25,5); 
cout<<"/"; 
gotoxy(24,6); 
cout<<"/"; 
gotoxy(23,7); 
cout<<"/"; 
gotoxy(54,5); 
cout<<"/" ; 
gotoxy(55,6); 
cout<<"/"; 
gotoxy(56,7); 
cout<<"/"; 
for(i=26; i<54; i++) 
{ 
gotoxy(i,4); 
cout<<"_"; 
} 
for(i=24; i<56; i++) 
{ 
gotoxy(i,7); 
cout<<"_"; 
} 

} 

void menu(char *op) 
{ 
gotoxy(23,9); 
cout<<"A.- Ingresar operacion"; 
gotoxy(23,10); 
cout<<"B.- Ver en Postfijo"; 
gotoxy(23,11); 
cout<<"C.- Operar"; 
gotoxy(23,12); 
cout<<"D.- Salir"; 
gotoxy(26,6); 
cout<<"Ingrese Opcion>>"; 
cin>>*op; 
*op=toupper(*op); 
} 

void validar(char cadinf[MAXCAD], int *err) 
{ 
char lg; 
int par=0; 
lg=strlen(cadinf); 
for(int i=0;i<lg;i++) 
{ 
//verificacion que no queden abiertos parentesis 
if(cadinf == '(') 
{ 
par++; 
} 
if (cadinf == ')') 
{ 
par--; 
} 
if((cadinf=='+'|| cadinf=='-' || cadinf=='*' || cadinf=='/' || cadinf=='^') && (cadinf[i+1]=='+'|| cadinf[i+1]=='-' || cadinf[i+1]=='*' || cadinf[i+1]=='/' || cadinf[i+1]=='^')) 
{ 

ide(); 
gotoxy(25,6); cout<<"Error"; //dos operadores juntos 
*err= *err+1; 
} 

if((cadinf=='+'|| cadinf=='-' || cadinf=='*' || cadinf=='/' || cadinf=='^') && (cadinf[i+1]==')')) 
{ 
clrscr(); 
ide(); 
gotoxy(25,6); cout<<"Error"; //operador antes de cierre de parentesis 
*err= *err+1; 
} 

if((cadinf=='(') && (cadinf[i+1]=='+'|| cadinf[i+1]=='-' || cadinf[i+1]=='*' || cadinf[i+1]=='/' || cadinf[i+1]=='^') ) 
{ 
clrscr(); 
ide(); 
gotoxy(25,6); cout<<"Error"; //operador al comenzar parentesis 
*err= *err+1; 
} 

if(cadinf=='(' && cadinf[i+1]==')') 
{ 
clrscr(); 
ide(); 
gotoxy(25,6); cout<<"Error"; //parentesis vacio 
*err= *err+1; 
} 

} 
if(cadinf[0]=='+'|| cadinf[0]=='-' || cadinf[0]=='*' || cadinf[0]=='/' || cadinf[0]=='^') 
{ 
clrscr(); 
ide(); 
gotoxy(25,6); cout<<"Error"; //empezando con operador 
*err= *err+1; 
} 
if (cadinf[lg-1]=='+'|| cadinf[lg-1]=='-' || cadinf[lg-1]=='*' || cadinf[lg-1]=='/' || cadinf[lg-1]=='^') 
{ 
clrscr(); 
ide(); 
gotoxy(25,6); cout<<"Error"; //terminando con operador 
*err= *err+1; 
} 
if (par != 0) 
{ 
clrscr(); 
ide(); 
gotoxy(25,6); cout<<"Error"; //no se cerraron parentesis 
*err= *err+1; 
} 
} 

//------------------Convertir a Postfijo 
char *postnumero(char cadinf[100]) 
{ 
charpila pila; 
crear(&pila); 
char elemento, valor; 
int exito,j=0; 
int tam = strlen(cadinf); 
char cadpost[MAXCAD]; 
int i; 
if (tam == 0) 
{ 
strcpy(cadpost, "Ingrese una Operacion Valida"; 
return cadpost; 
} 
else 
{ 
for (i=0; i<=tam-1; i++) 
{ 
if(isdigit(cadinf)) 
{ 
cadpost[j] = cadinf; 
j++; 
if(!isdigit(cadinf[i+1]) ) 
{ 
cadpost[j] = ' '; 
j++; 
} 
} 
else 
if(cadinf=='(') 
push(&pila,'(',&exito); 
else 
if(cadinf=='^') 
push(&pila,cadinf,&exito); 
else 
if(cadinf=='*'|| cadinf=='/') 
if(vacia(pila)) 
push(&pila,cadinf,&exito); 
else 
{elemento=cima(pila); 
if(elemento=='+'|| elemento=='-'||elemento=='(') 
push(&pila,cadinf,&exito); 
else 
{do{ 
valor=quitar(&pila,&exito); 
cadpost[j++]=valor; 
}while(valor!='*'&& valor!='/'&& valor!='^'&& !vacia(pila)); 
push(&pila,cadinf,&exito); 
} 
} 
else 
if(cadinf=='+'||cadinf=='-') 
if(vacia(pila)) 
push(&pila,cadinf,&exito); 
else 
{elemento=cima(pila); 
if(elemento=='(') 
push(&pila, cadinf,&exito); 
else 
{do{valor=quitar(&pila,&exito); 
cadpost[j++]=valor; 
}while(valor!='+'&&valor!='-'&&!vacia(pila)); 
push(&pila,cadinf,&exito); 
} 
} 
else 
if(cadinf==')') 
do{valor=quitar(&pila,&exito); 
if(valor!='(') 
cadpost[j++]=valor; 
}while(valor!='('); 

} 
while(!vacia(pila)) 
{valor=quitar(&pila,&exito); 
cadpost[j++]=valor; 
} 
cadpost[j]=" ";
return cadpost; 
} 


} 



//--------------Operaciones para CHARPILA 

void crear(charpila *pila) 
{ 
pila->cima=-1; 
}//fin crear 

//-- 
void push(charpila *pila,char valor,int *exito) 
{ 
if(!llena(*pila)) //si no esta llena 
{pila->cima+=1; 
pila->item[pila->cima]=valor; 
*exito=1; 
} 
else *exito=0; 
} 

//-- 
char quitar(charpila *pila, int *exito) 
{ 
char valor; 
if(!vacia(*pila)) 
{ valor = pila->item[pila->cima]; 
pila->cima--; 
*exito=1; 
} 
else 
*exito=0; 
return valor; 
} 

//-- 
int vacia(charpila pila) 
{ 
if(pila.cima==-1) 
return 1; 
else return 0; 
} 

//-- 
int llena(charpila pila) 
{ 
if(pila.cima==MAXPILA - 1) 
return 1; 
else 
return 0; 
} 

//-- 
char cima(charpila pila) 
{char valor; 
if(!vacia(pila)) 
{valor=pila.item[pila.cima]; 
} 
return valor; 
} 

//------------Operar en postfijo 

float evaluar(char cadinf[MAXCAD]) 
{ 
char cadpost[MAXCAD]; 
strcpy(cadpost, postnumero(cadinf)); 
numpila pila; 
inicia(&pila); 
int xd=strlen(cadpost); 
char temp[6]; 
int j=0; 
int exito; 
float a,b; 
for(int i=0; i<=xd-1; i++) 
{ 
if(isdigit(cadpost)) 
{ 
while(cadpost != ' ') 
{ 
temp[j]=cadpost; 
j++; 
i++; 
} 
temp[j] =" "; 
j=0; 
ponla(&pila,atof(temp), &exito); 
} 
else 
{ 
switch(cadpost) 
{ 
case '+': 
b = quita(&pila, &exito); 
a = quita(&pila, &exito); 
ponla(&pila, a+b, &exito); 
break; 

case '-': 
b = quita(&pila, &exito); 
a = quita(&pila, &exito); 
ponla(&pila, a-b, &exito); 
break; 

case '*': 
b = quita(&pila, &exito); 
a = quita(&pila, &exito); 
ponla(&pila, a*b, &exito); 
break; 

case '/': 
b = quita(&pila, &exito); 
a = quita(&pila, &exito); 
ponla(&pila, a/b, &exito); 
break; 

case '^': 
b = quita(&pila, &exito); 
a = quita(&pila, &exito); 
ponla(&pila, pow(a,b), &exito); 
break; 
} 

} 
} 
float res = quita(&pila, &exito); 
return res; 
} 

//----------Operaciones para NUMPILA 

void inicia(numpila *pila) 
{ 
pila->cima=-1; 
}//fin crear 

//-- 
void ponla(numpila *pila,float valor,int *exito) 
{ 
if(!llenala(*pila)) //si no esta llena 
{pila->cima+=1; 
pila->item[pila->cima]=valor; 
*exito=1; 
} 
else *exito=0; 
} 

//-- 
float quita(numpila *pila, int *exito) 
{ 
float valor; 
if(!vaciala(*pila)) 
{ valor = pila->item[pila->cima]; 
pila->cima--; 
*exito=1; 
} 
else 
*exito=0; 
return valor; 
} 

//-- 
int vaciala(numpila pila) 
{ 
if(pila.cima==-1) 
return 1; 
else return 0; 
} 
//-- 
int llenala(numpila pila) 
{ 
if(pila.cima==MAXPILA - 1) 
return 1; 
else 
return 0; 
}

void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
