#include <cstdlib>
#include <iostream> 
#include <sstream>

using namespace std;

#include "Matrizrala.h"


Matrizrala::Matrizrala (int num) 
{
                       acces_fila = new Lista();
                       acces_colum = new Lista();
                       rango = num;
                       acces_fila->add(num);
                       acces_colum->add(num);
}


void Matrizrala::recibirDatos (FILE *fp)
{
     fgetc(fp);
     fgetc(fp);
     int fil, col, dat;
     while (feof(fp) == 0)
     {            
       fil = fgetc(fp)-'0';
       
       col = fgetc(fp)-'0';
       
       dat = fgetc(fp)-'0';
       
       
       add_Nodoralo(dat, fil, col);
       
       fgetc(fp);
     }
}

void Matrizrala::add_Nodoralo(int v, int i, int j)
{
    Nodoralo *nodra = new Nodoralo(v,i,j);
	apuntar(acces_fila, nodra, i);
	apuntar(acces_colum , nodra, j);
}



Nodo* Matrizrala::buscarNodo(Lista *fil, int ubi)
{
          Lista *l = fil;
          for(int i = 0; i < ubi -1; i++)
          {
                  l = l->resto();
          }
          return l->cabeza();
          
}

void Matrizrala::apuntar(Lista *list, Nodoralo *nod ,int ubi)
{
     Nodo *nodito = buscarNodo(list, ubi);
     Nodoralo *aux = nodito->get_nodo(); 

     if(aux == NULL)
     {
            nodito->set_nodo(nod);
           
     }
     else
     {
         
         if(nod->get_fil() == aux->get_fil())
         {
                            while((aux->get_der())!= NULL)
                            {
                                                   aux = aux->get_der();
                            }
                            aux->set_der(nod);
         }
         else 
         {
             
                        while(aux->get_inf()!= NULL)
                            {
                                                   aux = aux->get_inf();
                            }
                            aux->set_inf(nod);
         } 
     }
                     
}

int Matrizrala::buscarNodoralo(int i, int j)
{
    Nodo *nod = buscarNodo(acces_fila, i);
    Nodoralo *aux = nod->get_nodo();
    
    if (aux == NULL)
    {
            
             
                          return 0;
    }
     else
	 {
     	
   		 while(aux != NULL && aux->get_col() <= j )
    	{
      		if(aux->get_col() == j)
        	{ 
                          return aux->get_dato();
        	}
        
        	aux = aux->get_der();
        	
        	
    	}
    	
    		return 0;
    
	}
}


void Matrizrala::imprimirMatriz()
{
    cout << endl  <<"----------------------------" << endl;
      
          
     cout<< rango <<endl;
     for(int i=1;i<=rango;i++)
     {
    Nodo *nod = buscarNodo(acces_fila, i);
    Nodoralo *aux = nod->get_nodo();
    while(aux!=NULL)
    {
    cout<<aux->get_fil()<<aux->get_col()<<aux->get_dato()<<endl;
    aux=aux->get_der();
    }
    }
    cout << endl <<"----------------------------" << endl;
}

int Matrizrala::getRango()
{
    return rango;
}

