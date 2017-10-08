#include <cstdlib>
#include <iostream>

using namespace std;

void impre(int v[],int n);

int suma(int v[], int n);

int mayor(int v[], int n);

int factorial(int n){
	if(n<2)
	return 1;
	else
	return n*factorial(n-1);
	
};

int fib(int n){
	if(n<=2)
	return 1;
	else
	return fib(n-1)+fib(n-2);
	};
	
int fib2(int n){
int c = 1;
int t = 1;
int i = 2;
while(!(i<n)){
int aux = c;
c = c + t;
t = aux;
i = i + 1;}
return c;
}

int main(int argc, char *argv[])
{   int v[6]={17,15,-8,30,5,-2};
    char nom[]={"Juan Perez"};
    
    cout<<"impre vector"<<endl; impre(v,5);    
   
    cout<<"La suma es: "<< suma(v,5) <<endl;
    
    cout<<"Mayor es: "<< mayor(v,5) << endl;
    
    cout<<"El factorial de 5 es: " << factorial(5) << endl;
    
    cout<<"Fibonacci de 5: " << fib(5) << endl;
    
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

    
int suma(int v[],int n)
{ 
if(n==0) return v[n];
    else{ 
          return v[n] + suma(v,n-1);        
    } 
}

int mayor(int v[],int n)
{ 
if(n==0) return v[n];
    else{ 
          if(v[n]>mayor(v,n-1))
		  return v[n];
		  else
		  return mayor(v, n-1);
		  ;        
    } 
}



