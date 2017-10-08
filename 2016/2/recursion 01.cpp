#include <cstdlib>
#include <iostream>

using namespace std;

void impre(int v[],int n);
int sumarec(int v[],int n);
int mayor(int v[],int n);
int fact(int n);
int fibsimple(int n);
int fibrecsimple(int n, int c, int t,int i);
void hanoi(char a, char c, char b ,int n);

int main(int argc, char *argv[])
{   int v[5]={2,4,2,6,1};
    char nom[]={"Juan Perez"};
    
    cout<<"impre vector"<<endl; impre(v,5);    
   
    cout<<endl;
    cout<<sumarec(v,5)<<endl;
    cout<<mayor(v,5)<<endl;
    cout<<fact(5)<<endl;
    cout<<fibsimple(6)<<endl;
    hanoi('a','b','c',3);
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
int sumarec(int v[],int n)
{ 
if(n==0)
	return v[n];
	else
	return v[n]+sumarec(v,n-1);
	 
	}
	
int mayor(int v[],int n)
{ int may;
if(n==0) return v[n];
	else{ 
		 int may=mayor(v,n-1);
		 return (v[n]>may)? v[n]: may;
		 //if(v[n]>may) return v[n]
		 //return may;
	 }
	}

int fact(int n){
	if (n==1) return 1;
	else
	return n*fact(n-1);
	}
	
int fibsimple(int n)
{if (n==1 || n==2)
	return 1;
	else
	fibrecsimple(n,1,1,0);
	
	}

int fibrecsimple(int n, int c, int t,int i)	
{	if (i==n) return c;
	else
		return	fibrecsimple(n,c+t,c,i+1);
	
	
	}	

void hanoi(char a, char c, char b ,int n)
{	if(n>0){

		hanoi(a,b,c,n-1);
			cout<<"mover "<<n<<" de "<<a<<" hasta "<<c<<endl;
				hanoi(b,c,a,n-1);}
				}
	
