#include <iostream>
#include <cstdlib>

using namespace std;

int fib (int);
int fib2 (int);
int fib3 (int,int,int,int);
void division (int,int,int*,int*);


int main(int argc, char *argv[])
{
	int num,a,b;
	int cociente=0;
	int resto=0;
		
	cout << "Ingrese numero de elementos de la serie: ";
	cin >> num;
	
	cout << "Fibonacci de " << num << " con recursion doble es: " << fib(num) << endl;
	cout << "Fibonacci de " << num << " con recursion simple es: " << fib2(num) << endl;

	cout <<"\nIngrese el dividendo: ";
	cin >> a;
	cout <<"\nIngrese el divisor: ";
	cin >> b;
	division (a,b,&cociente,&resto);
	cout << "\nEl cociente de la division es " << cociente <<" y el resto es " << resto << endl;
	
    system("PAUSE");
    return EXIT_SUCCESS;	
}

int fib (int x)
{
	if (x<=2)
	{
		return 1;	
	}	
	else
	{
		return (fib(x-1)+fib(x-2));
	}
}

int fib2(int x)
{
	if(x<=2)
	{
		return 1;
	}
	else
	{
		return fib3 (x,3,1,1);
	}
}

int fib3 (int x, int c, int p, int s)
{
	if (x==c)
	{
		return p+s;
	}
	else
	{
		return fib3 (x,c+1,p+s,p);
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
