#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string> 
#include <fstream>
#include <cmath>
#include "Paquete.cpp"
#include <string>
#include "Nodo.cpp"

#ifndef Cola_cpp
#define Cola_cpp





using namespace std;

template <typename tipoT>

class Cola{
    private: 
               Nodo<tipoT>* czo;
               int cantidad_de_datos;
    public:
           Nodo<tipoT>* getNodoCabeza(){return czo;};//IMPORTANTE
           tipoT getCabeza(){return czo->getDato();};//IMPORTANTE
           void removeCabeza()//IMPORTANTE                       
           {
                if(esvacia()==false)
                {
                    Nodo<tipoT>* nodo1=czo->getNext();
                    czo=nodo1;
                    cantidad_de_datos--;
                }
            };
            
            
            void borrarCabeza(void)
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
                     cout<<"la pila/Cola ya esta vacia"<<endl<<endl;
                 }
            }
           
           
           void imprimirCola2();
            void set(int index, tipoT dato);
            tipoT get(int);
            Nodo<tipoT>* getNodo(int);
            int getCantidadDeDatos();
            Cola() {czo=new Nodo<tipoT>();cantidad_de_datos=0;};
            Cola(Nodo<tipoT> *n) {czo=n;};
            Nodo<tipoT>* getCzo(){return czo;}
            //~Cola(void);
            //tipoT Cola::ultimo(tipoT x);
            void del(void);
            void add(tipoT d);
            void buscarUltimo();
            bool esvacia(void);
            tipoT cabeza(void);//devuelve el ultimo dato ingresado (el q esta en la cabeza)
            Cola *resto(void);
            string toPrint(string p);   
            void imprimirCola();
            tipoT getDatoPorIndex(int index);
            
            bool esVacio()
            {
                 if(this->getCantidadDeDatos()==0)
                     return true;
                 else
                     return false;
             }
            
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
void Cola<tipoT>::imprimirCola2()
{
     for(int i=getCantidadDeDatos()-1;i>=0;i--)
     cout<<get(i)->getDato()<<" ";
             
 }
 
 
template <typename tipoT>
void Cola<tipoT>::set(int index, tipoT dato)
{
     Nodo<tipoT>* nodito=get(index);
     nodito->set_dato(dato);
     
     
 }
 
template <typename tipoT>
Nodo<tipoT>* Cola<tipoT>::getNodo(int index)
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
 
template <typename tipoT>
tipoT Cola<tipoT>:: get(int index)
{
     Nodo<tipoT>* elNodo=getCzo();
     
     if(index>=this->getCantidadDeDatos())
     {
       cout<<endl<<"NO EXISTE ESE ELEMENTO"<<endl;
        return NULL;
     }
     
     else if(index==0)
     {
                 return getCzo()->getDato();
     }
     else
     {
         for(int i=0; i<index; i++)
         {
                 elNodo=elNodo->getNext();
         }
         return elNodo->getDato();
     }
     
 }
 
 
 //OJO Q NO ESTA TESTEADO PERO SE QUE NO ANDA CORRECTAMENTE
template <typename tipoT>
tipoT Cola<tipoT>:: getDatoPorIndex(int index)
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
int Cola<tipoT>::getCantidadDeDatos()
{
    return cantidad_de_datos;
}



template <typename tipoT>
void Cola<tipoT>::del(void)
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
         cout<<"la pila/Cola ya esta vacia"<<endl<<endl;
     }
}






template <typename tipoT>
bool Cola<tipoT>::esvacia(void)
{   
    return czo->es_vacio();
}



template <typename tipoT>
tipoT Cola<tipoT>::cabeza(void)
{ 
  if(esvacia()){
                cout<<" Error, Cabeza de Cola vacia";
                return " "; 
  }
  return czo->getDato();
}


template <typename tipoT>
Cola<tipoT> *Cola<tipoT>::resto(void)
{ 
      Cola<tipoT> *l=new Cola(czo->getNext());

      return (l);
}


template <typename tipoT>
string Cola<tipoT>::toPrint(string p)
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
void Cola<tipoT>::imprimirCola()
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
         cout<<"La Cola esta vacia"<<endl;
     }
 }
 
template <typename tipoT>
void Cola<tipoT>::add(tipoT d)
{  
     Nodo<tipoT> *nuevo=new Nodo<tipoT>(d);
     //cout<<"la cant de datos es: "<<getCantidadDeDatos()<<endl;
     if(getCantidadDeDatos()==0)
     {
         nuevo->set_next(czo);//ahora el Nodo nuevo va a apuntar su variable next... hacia czo
         //ya que se va a convertir czo en un elemento i-1
         czo=nuevo;
         //cout<<"nuevo!!!!:   "<<nuevo->getDato()<<endl;
        
         
     }
     
     else
     {
         //cout<<"nuevo!!!!:   "<<nuevo->getDato()<<endl;
         
         Nodo<tipoT> *ultimo=czo;
         for(int i=0; i<getCantidadDeDatos()-1; i++)
         {
                 ultimo=ultimo->getNext();
         }
         
         if(ultimo==NULL)
         {cout<<"NULL SALAMEEE"<<endl;}
         //ultimo.... agarra el objeto q se encuentra en esa direccion de memoria y opera sobre el mismo... oseaaa sobre el objeto
         //entonces ultimo agarra el ultimo elemento de la cola.... bien.. el nuevo debe apuntar hacia donde apuntaba el ultimo o anterior
         //y el anterior o ultimo (como quieran llamarle) apuntara ahora a al nuevo todo esto del apuntar me refiero al set_next
         nuevo->set_next(ultimo->getNext());
         ultimo->set_next(nuevo);
         nuevo=ultimo;
         
     }
     
     cantidad_de_datos++;
}


//hacer el metodo borrar cabeza 
 ;
 
 


/*
int main()
{
    cout<<"ANDA"<<endl;
    
    Cola<int>* cola;
    cola=new Cola<int>();
    
    
    cola->add(1);
    cola->add(2);
    cola->add(3);
    cola->add(4);
    cola->add(9);
    int a=cola->getNodo(3)->getDato();
    cout<<"EASSEAE:      "<<a<<endl;
    cola->imprimirCola();
    cout<<endl<<endl;
    
    cola->remove(9);
    cola->removeCabeza();
    cola->removeCabeza();
    cola->removeCabeza();
    cola->removeCabeza();
    cola->removeCabeza();
    cola->removeCabeza();
    cola->removeCabeza();
    
    cola->add(92313);
    
    
    cola->imprimirCola();

    cout<<"numero de datosss..."<<cola->getCantidadDeDatos()<<endl;

    cout<<"La cabeza da.....   "<<cola->getNodoCabeza()->getDato()<<endl;
    
    
    system("PAUSE");
}
*/

#endif 
