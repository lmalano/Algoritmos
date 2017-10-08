#include <cstdlib>
#include <iostream>
#define INFI  9000
#define MAXNODOS  8
#define MIEMBRO   1
#define NO_MIEMBRO 0

using namespace std;
int greedy(int peso[][MAXNODOS],int ini, int precede[])
{
 int perm[MAXNODOS];
 int actual, i, j;
 int costo=0; j=1;
 for(i=0;i<MAXNODOS;i++){
    perm[i]=NO_MIEMBRO;  precede[i]= -1;
 }
 perm[ini]=MIEMBRO; actual=ini;
 precede[0]=ini;
 while(j<MAXNODOS){
 	int menordist=INFI;
 	int sig=-1;
 	for (i=0;i<MAXNODOS;i++){
 		if(perm[i]==NO_MIEMBRO && peso[actual][i]<=menordist){
 			sig=i; menordist= peso[actual][i];
		}	
 	}
 	costo+=peso[actual][sig];
 	precede[j]=sig;
 	perm[sig]=MIEMBRO;
 	actual=sig;
 	j++;
}
precede[j]=ini;
costo+=peso[actual][ini];
return costo;
}

int main(){
	int peso[MAXNODOS][MAXNODOS]={INFI,	150,	250,	210,	340,	295,	300,	450,
                                  120, 	INFI,	220,	200,	350,	275,	280,	420,
                                  250,	210,	INFI,	350,	440,	315,	150,	210,
                                  195,	200,	370,	INFI,	95,		100,	INFI,	200,
                                  240,	270,	320,	95,		INFI,	150,	240,	330,
                                  185,	190,	335,	90,		140,	INFI,	200,	160,
                                  300,	290,	145,	INFI,	240,	200,	INFI,	120,
                                  450,	415,	200,	195,	330,	160,	110,	INFI  
                                 };
    int precede[MAXNODOS+1];
    int i,j;
    
    cout<<endl<<"DESDE MADRID"<<endl;
	cout<<"COSTO: "<< greedy(peso,0,precede)<<endl;
	cout<<"CAMINO: ";
	for (i=0;i<MAXNODOS+1;i++){	cout<<precede[i]<<"   ";	}
	cout<<endl<<endl<<"DESDE ROMA"<<endl;
	cout<<"COSTO: "<< greedy(peso,2,precede)<<endl;
	cout<<"CAMINO: ";
	for (i=0;i<MAXNODOS+1;i++){	cout<<precede[i]<<"   ";	}
	cout<<endl<<endl<<"DESDE PARIS"<<endl;
	cout<<"COSTO: "<< greedy(peso,3,precede)<<endl;
	cout<<"CAMINO: ";
	for (i=0;i<MAXNODOS+1;i++){	cout<<precede[i]<<"   ";	}
	cout<<endl<<endl<<"DESDE LONDRES"<<endl;
	cout<<"COSTO: "<< greedy(peso,4,precede)<<endl;
	cout<<"CAMINO: ";
	for (i=0;i<MAXNODOS+1;i++){	cout<<precede[i]<<"   ";	}
	cout<<endl;
	
    system("PAUSE");
    return EXIT_SUCCESS;
}
