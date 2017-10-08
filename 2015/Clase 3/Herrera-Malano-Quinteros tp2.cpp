#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int resto (int, int);
bool esdiv (int, int);
bool primo (int, int*);
int* cienp (int*, int, int);
int cabeza (int*);
int* sgte (int*);
int* poner (int*, int, int);

int main(int argc, char *argv[])
{
	int lp[100];
	for(int i=0;i<100;i++)
    {
		lp[i]=0;
	}
    
    cienp(lp,0,1);
    
    cout << "Los primeros 100 numeros primos son: " <<endl;
    
    for(int i=0;i<100;i++)
    {
    	cout<< setw(3)<< lp[i]<<" ";
    }
    
	getch();
    return 0;
}


int resto (int x, int y)
{
	if (x>=y)
	{
		return resto (x-y, y);
	}
	else
	{
		return x;	
	}
}

bool esdiv (int x, int y)
{
	return (resto(x,y)==0);
}

bool primo (int x, int* lp)
{
	if (*lp == 0)
	{
		return true;
	}
	else if (*lp != 0 && esdiv(x, cabeza(lp)))
	{
		return false;
	}
	else if (*lp != 0 && !esdiv(x, cabeza(lp)))
	{
		return primo (x, sgte(lp));
	}
}

int* cienp (int* lp, int pos, int x)
{
	if (pos>100)
	{
		return lp;
	}
	else if (pos <= 100 && !primo(x,lp))
	{
		cienp(lp, pos, x+1);
	}
	else if (pos <= 100 && primo(x,lp))
	{
		cienp(poner(lp, pos, x), pos+1, x+1);
	}
}

int cabeza (int* a)
{
	return a[0];
}

int* sgte (int* a)
{
	return a+1;	
}	
	
int* poner (int* lp, int pos, int x)
{
	*(lp+pos-1)=x;
	return lp;
}
