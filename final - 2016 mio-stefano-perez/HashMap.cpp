#include <iostream>


#include "NodoHash.cpp"
using namespace std;




//----------HashMap----------//
template <typename keyT, typename datoT>

class HashMap
{
      private:
              NodoHash<keyT,datoT>* cabeza;
              int cantidad_de_datos;
              keyT key;//q seria el datod el nodo o key, generalmente es un string
              datoT dato;//se organiza asi... [KEY][VALOR] asis e organiza un hashmap
              
              
              
      public: 
              HashMap(){cabeza=NULL;cantidad_de_datos=0;}
              
              void clear() {cabeza=NULL;cantidad_de_datos=0;} 
              int getCantDeDatos(){return cantidad_de_datos;}
              
              bool esVacia()
              {
                   if(cantidad_de_datos==0)
                     return true;
                   else
                     return false;
              };
              
              //devuelve la key del hash por indice...
              keyT getKeyPorIndex(int index)
              {
                   
                   NodoHash<keyT,datoT>* actual=cabeza;
                   if(index>=0 && this->esVacia()==false && index<cantidad_de_datos)
                   {
                       
                       for(int i=0; i<index;i++)
                       {
                             actual=actual->getNext();
                       }
                       
                       return actual->getKey();
                       
                   }
              }
              
              
              //devuelve el value del hash por indice...
              datoT getValuePorIndex(int index)
              {
                   if(getCantDeDatos()!=0)
                   {
                       NodoHash<keyT,datoT>* actual=cabeza;
                       if(index>=0 && this->esVacia()==false && index<cantidad_de_datos)
                       {
                           
                           for(int i=0; i<index;i++)
                           {
                                 actual=actual->getNext();
                           }
                           
                           return actual->getValue();
                           
                       }
                   }
                   else
                   {
                       cout<<"No existe dicho elemento"<<endl;
                   }
              }
              
              /*datoT getDatoPorIndex()
              {
                    
              }*/
              
              datoT get(keyT keyBuscada)
              {
                    NodoHash<keyT,datoT>* actual=cabeza;
                    for(int i=0; i<cantidad_de_datos;i++)
                    {
                         if(actual->getKey()==keyBuscada)
                         {
                               return actual->getValue();
                         }
                         else
                             actual=actual->getNext();
                    }
                   //cout<<endl<<"DEL GET No se encuentra la key buscada para obtener un value correspondiente"<<endl;
                   
                   //return NULL; si pongo esto y es un entero justo lo q hay en la key no va a haber problemas el problema esta en
                   //si es otro tipo de objeto
              }
              
              NodoHash<keyT,datoT>* getNodoPorKey(keyT keyBuscada)
              {
                   NodoHash<keyT,datoT>* actual=cabeza;
                    for(int i=0; i<cantidad_de_datos;i++)
                    {
                         if(actual->getKey()==keyBuscada)
                         {
                               return actual;
                         }
                         else
                             actual=actual->getNext();
                    }
              }
              
              
              
              void set(keyT keyBuscada, datoT datoAPisar)
              {
                   if(this->containsKey(keyBuscada))
                   {
                        NodoHash<keyT,datoT>* actual=cabeza;
                        for(int i=0; i<cantidad_de_datos;i++)
                        {
                             if(actual->getKey()==keyBuscada)
                             {
                                    actual->setDato(datoAPisar);
                             }
                             else
                                 actual=actual->getNext();
                        }
                   }
                   
                   else 
                        {cout<<endl<<"DEL SET No se encuentra la key buscada para obtener un value correspondiente"<<endl;}
                   //return NULL; si pongo esto y es un entero justo lo q hay en la key no va a haber problemas el problema esta en
                   //si es otro tipo de objeto
              }
              
              
              //podes hacer q cabeza apunte a nuevo y nuevo a null
              //o que nuevo apunte a cabeza y zabeza a nuevo
              void add(keyT key, datoT value)
              {
                   //funciona como una estructura de pila en este caso
                        NodoHash<keyT,datoT>* nuevo=new NodoHash<keyT,datoT>(key,value);
                        nuevo->setNext(cabeza);//ahora el Nodo nuevo va a apuntar su variable next... hacia czo
                        //ya que se va a convertir czo en un elemento i-1
                        cabeza=nuevo;
                        cantidad_de_datos+=1;
              
              };
              
              
              void imprimirCabeza(){cabeza->imprimir();};
              
              void imprimirHash()
              {
                   if(cantidad_de_datos>0)
                   {
                         NodoHash<keyT,datoT>* seguidor=cabeza;
                         for(int i=0;i<cantidad_de_datos;i++)
                         {
                                 seguidor->imprimir();
                                 seguidor=seguidor->getNext();
                         }
                   }
              };
              
              
              bool containsKey(keyT keyBuscada)
              {
                    
                    NodoHash<keyT,datoT>* actual=cabeza;
                    if(cantidad_de_datos!=0)
                    {
                        for(int i=0; i<cantidad_de_datos;i++)
                        {
                             if(actual->getKey()==keyBuscada)
                             {
                                   return true;
                             }
                             else
                                 actual=actual->getNext();
                        }
                    }
                    
                    return false;
              };
              
              bool containsValue(datoT valueBuscado)
              {
                   NodoHash<keyT,datoT>* actual=cabeza;
                    
                    for(int i=0; i<cantidad_de_datos;i++)
                    {
                         if(actual->getValue()==valueBuscado)
                         {
                               return true;
                         }
                         else
                             actual=actual->getNext();
                    }
                   
                   return false;
               };
               
               void remove (keyT keyBuscada)
               {
                    if(this->containsKey(keyBuscada))
                    {
                          NodoHash<keyT,datoT>* anterior=cabeza;
                          NodoHash<keyT,datoT>* actual=cabeza;
                          NodoHash<keyT,datoT>* siguiente=actual->getNext();
                          
                          
                          for(int i=0; i<cantidad_de_datos;i++)
                          {
                               
                               if(actual->getKey()==keyBuscada)
                               {
                                    if(i==0 )
                                    {
                                          cabeza=siguiente;
                                          free(actual);
                                          cantidad_de_datos-=1;
                                          break;
                                     }
                                     else
                                     {
                                           anterior->setNext(siguiente);
                                           free(actual);//OJO CON ESTO POR SI TE TRAE PROBLEMAS!!!
                                           cantidad_de_datos-=1;
                                           break;
                                     }
                               }
                               
                               anterior=actual;
                               actual=actual->getNext();
                               siguiente=actual->getNext();
                         }                  
                    }
                    
                };
};





//testeo del HashMap.... ascar los comentarios para probar...
/*
int main ()
{
    HashMap<int,int> hash;
    hash.add(1,10);
    hash.add(2,34);
    hash.add(3,45);
    hash.add(4,34);
    
    //cout<<"ESTARA?:  "<<hash.containsValue(45)<<endl;
    //hash.imprimirCabeza();
    hash.remove(4);
    hash.remove(1);
    hash.remove(2);
    hash.remove(3);
    
    hash.add(1,10);
    hash.add(4,34);
    
    
    
    hash.imprimirHash();
    cout<<"LPM2"<<endl<<endl;
    
    
    HashMap<string,int> hash2;
    hash2.add("hola",10);
    hash2.remove("hola");
    hash2.imprimirHash();
    
    system("PAUSE");
}
*/
