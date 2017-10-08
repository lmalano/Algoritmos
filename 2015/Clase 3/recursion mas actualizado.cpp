#include <cstdlib>
#include <iostream>



using namespace std;

void impre(int v[],int n);
int suma(int v[], int n);
int factorial(int n);
int mayor(int v[], int n);
int mult(int a, int b);
void division(int a, int b);
int fibo1(int n);
int fibo2 (int n);
int fiboaux(int n,int a,int b,int c);
void division (int a, int b, int* cociente, int* resto);
int var(int a, int sc,int sl,int n);


int main(int argc, char *argv[])
{   int v[6]={17,15,-8,30,5,-2};
    char nom[]={"Juan Perez"};
   int cociente=0;
	int resto=0;
    int a,b;
    
    cout<<"impre vector"<<endl; impre(v,5);    
   
    cout<<endl; 
    cout<<"suma del vector="<<suma(v,5)<<endl;     // va 5 ya q n=6 y n-1 es 5;
    cout<<"factorial de="<<factorial(5)<<endl;
    cout<<"el mayor elemento es="<<mayor(v,5)<<endl;
    cout<<"la multip de 5*4 es="<<mult(5,4)<<endl;
    //cout<<"la division entera de 7/2 es="<<division(7,2)<<endl;
    cout<<"la sucesion de fibonacci de a es(met 1)="<<fibo1(7)<<endl;
    cout<<"la sucesion de fibonacci de a es(met 2)="<<fibo2(7)<<endl;
    
     cout<<"la sucesion para el numero a es"<<endl;
	for(int i=1;i<7+1;i++)
	{ cout<<fibo1(i)<<" ";
	}
    
    cout <<"\nDIVISION\nIngrese el dividendo: \n";
	cin >> a;
	cout <<"\nIngrese el divisor: ";
	cin >> b;
	division (a,b,&cociente,&resto);
	cout << "\nEl cociente de la division es " << cociente <<" y el resto es " << resto << endl;
   
	system("PAUSE");
    
    return EXIT_SUCCESS;
}



void impre(int v[],int n)
{   if(n==0)cout<<v[n]<<endl;
    else{ 
          //cout<<"estoy yendo";
          //cout<<v[n]<<endl;
          impre(v,n-1);
          //cout<<"estoy retornando"<<endl;
          cout<<v[n]<<endl;
          
          
          
    } 
}

int suma(int v[], int n)
{
	if(n==0) return v[n];
	else{
		return v[n]+suma(v,n-1);
	}	
}

int factorial(int n)
{ if (n==0) return 1;
return n*factorial(n-1);
	
}
int mayor(int v[], int n)
	{	if(n==0) return v[n];
			else
			{int may=mayor(v,n-1);
			return (v[n]>may)? v[n] :may;
			
			//en vez de
			
			//if (v[n]>may) return v[n] return may; ;
			
			}		
}
		
int mult(int a, int b)
{
if(b==0) return 0;
else{
		return a+mult(a,b-1);
}
	
}		
void division (int a, int b, int* cociente, int* resto)
{
	if(a < b)
	{
		*resto = a;
	}
	else
	{
		(*cociente)++;
		division (a-b, b, cociente, resto);
	}
}


			
int fibo1(int n){


if(n<=2) return 1;

else{ 
		return fibo1(n-1)+fibo1(n-2); }	

}			

int fibo2 (int n){	
		if(n<=2) return 1;
		
		else{ 
		return fiboaux(n,3,1,1); }				

}


int fiboaux(int n,int a,int b,int c){

 if(n==a)
  {return b+c;  }
 
  
 else  {return fiboaux(n,a+1,b+c,b) ;}	
	
}	
int var(int a, int sc,int sl,int n)
{
	
	
}
