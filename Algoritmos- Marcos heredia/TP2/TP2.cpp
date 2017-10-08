#include<iostream>
#include<cstdlib>

using namespace std;

int resto (int x, int y){
	if (x<y) return x;
	else resto (x-y,y);
}

bool esdiv(int x, int y){
	return resto(x,y)==0;
}

bool findatos(int d){
	return d==NULL;
}

int *sig(int *lp){
	return (lp+1);
}

int cabeza(int *lp){
	return *lp;
}

bool primo (int x, int *lp[100]){
	if (findatos(*lp))return true;
	else if (!findatos(*lp) && esdiv(x,cabeza(lp))) return false;
	else primo(x,sig(lp));
}

int *poner(int *lp[100], int pos, int x){
	*(lp+pos)=x;
	return lp;
}


void cienp(int *lp[100],int pos,int x){
	if(pos==100){
	}
	else if (pos<100 && primo(x,lp) ){  cienp(poner(lp,pos,x),pos+1,x+1);
	} 
	else cienp(lp, pos, x+1);
}



/*

*/





int main()
{
    int *lista[100];
    for (int i=0;i<100;i++)lista[i]=NULL;
	cienp(1,0,2);
	cout<<"Los primeros 100 numeros primos son: "<<endl;
	for (int i=0;i<100;i++)cout<<lista[i]<<endl;//una vez terminado poner *lista[i]
    system("PAUSE");
    return 0;
}
