#include <cstdlib>
#include <iostream>

using namespace std;

int resto(int , int );
bool esdiv(int , int );
bool esprimo(int , int *);
int *cienp(int * , int , int );
int *agreg_primo(int * , int , int );



int main()
{
    int lista[100];
    int *listaptr;
    listaptr=lista;
    int pos=1,x=0,i=0;
    
    x=2;
    
    
    for(i=0;i<100;i++)
    
    { *(listaptr+i)=0;}    
    
    
    cienp(listaptr,pos,x);              
    
    
                  
    
    for(i=0;i<100;i++)
    
    { cout<<*(listaptr+i)<<endl;}
                      
    
 
 
    system("PAUSE");
    return EXIT_SUCCESS;
 
}







int resto(int x, int y)
{
    if(x<y)
    {return x;}
    
    else
    {return(x-y,y);}

}





bool esdiv(int x, int y)
{
     if(resto(x,y)==0)
     {return true;}
     
     else
     {return false;}

}



bool esprimo(int x,int *listaptr)
{
     if(*listaptr==0)
     {return true;}
     
     
     if(*listaptr!=0 && esdiv(x,*listaptr))
     {return false;}
     
     
     if(*listaptr!=0 && !esdiv(x,*listaptr))
     {esprimo(x,(listaptr++));}     
     
}


int *cienp(int *listaptr, int pos, int x)

{
     int *direccion_0=listaptr;
     
     if(pos>100)
     {return listaptr;}
     
     if(pos<=100 && !esprimo(x,listaptr))
     {           listaptr=direccion_0;
                 cienp(listaptr,pos,x+1);}
     
     if(pos<=100 && esprimo(x,listaptr))
     {
                 listaptr=direccion_0;
                 cienp(agreg_primo(listaptr,pos,x),pos+1,x+1);}
     
     
     }
     
     
     
     

int *agreg_primo(int *listaptr, int p, int x)
{
                       *(listaptr+p)=x;
                       return listaptr;
             
}
     
     
     





































