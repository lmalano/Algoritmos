#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string> 
#include <fstream>
#include <cmath>

#include "Nodo.cpp"

#ifndef Lista_cpp
#define Lista_cpp

using namespace std;

template <typename tipoT>

class Lista{
    private: 
               Nodo<tipoT>* czo;
               int cantidad_de_datos;
    public:
           void imprimirLista2();
            void set(int index, tipoT dato);
            Nodo<tipoT>* get(int);
            int getCantidadDeDatos();
            Lista() {czo=new Nodo<tipoT>();cantidad_de_datos=0;};
            Lista(Nodo<tipoT> *n) {czo=n;};
            Nodo<tipoT>* getCzo(){return czo;}
            //~Lista(void);
            //tipoT Lista::ultimo(tipoT x);
            void del(void);
            void add(tipoT d);
            bool esvacia(void);
            tipoT cabeza(void);//devuelve el ultimo dato ingresado (el q esta en la cabeza)
            Lista *resto(void);
            string toPrint(string p);   
            void imprimirLista();
            tipoT getDatoPorIndex(int index);
            
            void remove (tipoT keyBuscada)
               {
                    //if(this->containsKey(keyBuscada))
                    //{
                          Nodo<tipoT>* anterior=czo;
                          Nodo<tipoT>* actual=czo;
                          Nodo<tipoT>* siguiente=actual->getNext();
                          
                          
                          for(int i=0; i<cantidad_de_datos;i++)
                          {
                               
                               if(actual->getDato()==keyBuscada)
                               {
                                    if(i==0 )
                                    {
                                          czo=siguiente;
                                          free(actual);
                                          cantidad_de_datos-=1;
                                          break;
                                     }
                                     else
                                     {
                                           anterior->set_next(siguiente);
                                           free(actual);//OJO CON ESTO POR SI TE TRAE PROBLEMAS!!!
                                           cantidad_de_datos-=1;
                                           break;
                                     }
                               }
                               
                               anterior=actual;
                               actual=actual->getNext();
                               siguiente=actual->getNext();
                         }                  
                    //}
                    
                };
            
};

template <typename tipoT>
void Lista<tipoT>::imprimirLista2()
{
     for(int i=getCantidadDeDatos()-1;i>=0;i--)
     cout<<get(i)->getDato()<<" ";
             
 }
 
 
template <typename tipoT>
void Lista<tipoT>::set(int index, tipoT dato)
{
     Nodo<tipoT>* nodito=get(index);
     nodito->set_dato(dato);
     
     
 }
 
 
 
template <typename tipoT>
Nodo<tipoT>* Lista<tipoT>:: get(int index)
{
     Nodo<tipoT>* elNodo=getCzo();
     
     if(index>=this->getCantidadDeDatos())
     {
       cout<<endl<<"NO EXISTE ESE ELEMENTO"<<endl;
        return NULL;
     }
     
     else if(index==0)
     {
                 return getCzo();
     }
     else
     {
         for(int i=0; i<index; i++)
         {
                 elNodo=elNodo->getNext();
         }
         return elNodo;
     }
     
 }
 
 
 //OJO Q NO ESTA TESTEADO PERO SE QUE NO ANDA CORRECTAMENTE
template <typename tipoT>
tipoT Lista<tipoT>:: getDatoPorIndex(int index)
{
     Nodo<tipoT>* elNodo=getCzo();
     
     if(index>=this->getCantidadDeDatos())
     {
       cout<<endl<<"NO EXISTE ESE ELEMENTO"<<endl;
        return NULL;
     }
     
     else if(index==0)
     {
                 return (getCzo()->getDato());
     }
     else
     {
         for(int i=0; i<index; i++)
         {
                 elNodo=elNodo->getNext();
         }
         return (elNodo->getDato());
     }
     
 }
 
 
 
 
template <typename tipoT>
int Lista<tipoT>::getCantidadDeDatos()
{
    return cantidad_de_datos;
}



template <typename tipoT>
void Lista<tipoT>::del(void)
{    if(!esvacia())
     {
         //Nodo* aux;//creas una variable auxiliar
         //aux=czo;//aux va a apuntar a comienzo
         czo=czo->getNext();//obtengo el siguiente elemento de czo
         //delete aux;//borro aux... que era el elemento q le llamabamos czo antes... 
         cantidad_de_datos-=1;
     }
     else
     {
         cout<<"la pila/lista ya esta vacia"<<endl<<endl;
     }
}



template <typename tipoT>
void Lista<tipoT>::add(tipoT d)
{  
     Nodo<tipoT> *nuevo=new Nodo<tipoT>(d);
     nuevo->set_next(czo);//ahora el Nodo nuevo va a apuntar su variable next... hacia czo
     //ya que se va a convertir czo en un elemento i-1
     czo=nuevo;
     cantidad_de_datos+=1;
}


template <typename tipoT>
bool Lista<tipoT>::esvacia(void)
{   
    return czo->es_vacio();
}



template <typename tipoT>
tipoT Lista<tipoT>::cabeza(void)
{ 
  if(esvacia()){
                cout<<" Error, Cabeza de lista vacia";
                return " "; 
  }
  return czo->getDato();
}


template <typename tipoT>
Lista<tipoT> *Lista<tipoT>::resto(void)
{ 
      Lista<tipoT> *l=new Lista(czo->getNext());

      return (l);
}


template <typename tipoT>
string Lista<tipoT>::toPrint(string p)
{ 
     if (this->esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm << this->cabeza()<<"-"<< this->resto()->toPrint(p) << endl;
       return stm.str();
     }
}

template <typename tipoT>
void Lista<tipoT>::imprimirLista()
{
     if(!esvacia())
     {
         Nodo<tipoT>* siguienteNodo;
         siguienteNodo=czo;
         while(!siguienteNodo->es_vacio())
         {
             cout<<siguienteNodo->getDato()<<" ";    
             siguienteNodo=siguienteNodo->getNext();
         }
         cout<<endl;
     }
     else
     {
         cout<<"La lista esta vacia"<<endl;
     }
 }
 ;
#endif 
