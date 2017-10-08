#include<iostream>
using namespace std;

main() {int ORDEN=8;
       int dato[ORDEN+1];
       int i=0;
       while(i<ORDEN)
       {dato[i]=2*i;cout<<2*i<<" ";
       i++;}
      cout<<"ingrese dato ";
      int a;
      cin>>a; 
       
   int pos;
   int Li=0,Ls=ORDEN-1;
   while (Li<=Ls)
   { pos=(Ls+Li)/2;
   if (dato[pos]==a)
   {cout<<pos;Li=Ls+1;}
   else
       {if (a<dato[pos])
           {Ls=pos-1;}
       else
           {Li=pos+1;}
                  
                  
                  }




         }
  
   
system("pause");
}

/*int busquedaBinaria(const int arreglo[], int tamano, int clave)
{
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;
  while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (arreglo[Icentro] == clave)
 return Icentro;
      else
 if (clave < arreglo[Icentro])
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}*/
