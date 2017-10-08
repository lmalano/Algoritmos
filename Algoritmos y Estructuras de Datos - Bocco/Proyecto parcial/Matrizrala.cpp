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


void Matrizrala::recivirDatos (FILE *fp)
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
	apuntar (acces_colum , nodra, j);
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
                           if(nod->get_col() < aux->get_col())
                           {
                                             Nodoralo *punt = aux;
                                             nodito->set_nodo(nod);
                                             nod->set_der(aux);
                           }
                           else
                           {
                               aux->set_der(nod);
                           }
         }
         else 
         {
                           if(nod->get_fil() < aux->get_fil())
                           {
                                             Nodoralo *punt = aux;
                                             nodito->set_nodo(nod);
                                             nod->set_inf(aux);
                           }
                           else
                           {
                               aux->set_inf(nod);
                           }
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
     	
   		 while(aux->get_col() <= j)
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
     cout << endl <<"----------------------------" << endl;
     cout <<endl <<  rango << endl;
    for (int i = 1; i <= rango; i++)
    {
        for (int j = 1; j <= rango; j++ )
        {
            int resu = buscarNodoralo(i,j);
            if (resu != 0)
            {
                     cout << i << j << resu << endl ; 
            }
        }
    }
  
}


