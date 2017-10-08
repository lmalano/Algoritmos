#include <iostream>
#include "Lista.cpp"

//#include "NodoGrafo.cpp"
#include "RutaD.cpp"
#include <iomanip>
//no se xq no me deja desde el archivo
#include "Cola.cpp"
#ifndef Grafo_cpp
#define Grafo_cpp
#include "NodoGrafoPC.cpp"

//#include "Cola.cpp"


using namespace std;

//no pongo el #include hashmap xq como lo contiene NodoGrafo te permite usarlo.... 
//tengo que preguntarle esto al profe xq no entiendo un acrajo


class Grafo
{
      
    private: 
             //Lista<NodoGrafo*> nodos;
             int cantDeNodosVisitados;
             int matrizAdyacencia[256][256];
             int matrizAdyacenciaPCS[256] [256];
             int NMAX;
             int cantNodos;
             int cantPCS;
             HashMap<int,NodoGrafo*>* nodos;//si le llego a sacar el puntero me anda todo como el ojete no entiendo xq
             //otro problema si a nodoGrafo tampoco le pongo puntero kgue fuego... q carajos?
             //MORALEJA!!! todo lo q sea objetos laburalo con punteros
             //el key es el nombre del nodo o numero del mismo, el value es la direccion de memoria al otro nodo
             HashMap<int,NodoGrafoPC*>* PCS;
             
               
               
    public:
               
               int getCantidadDeNodos(){return cantNodos;}
             public: Grafo(int cantNodos, int pcss)
             {
                       cantPCS=pcss;
                       cantDeNodosVisitados=0;
                       NMAX=256;
                       this->cantNodos=cantNodos;
                       nodos=new HashMap<int,NodoGrafo*>();
                       PCS=new HashMap<int,NodoGrafoPC*>();
                       //cout<<"asdasd dat:   "<<nodos->getCantDeDatos()<<endl<<endl;
                       //nodos=& new HashMap<int,NodoGrafo>();
             }
             
             public: void imprimirGrafoPC()
             {
                  cout<<endl<<endl;
                  cout<<PCS->getCantDeDatos()<<endl;
                  cout<<"asdadas"<<endl<<endl<<"PROBANDOO::   ";
                  cout<<nodos->get(0)->getCantidadDeAristas();
                  cout<<endl;
                  for (int i=0; i<PCS->getCantDeDatos();i++)
                  {
                      cout<<"NODO: "<<i<<endl;
                      PCS->get(i)->toPrint();
                      
                  }
                  
              }
             
             public: int getCantidadDePCS(){return cantPCS;}
             
             public: void setNodos(HashMap<int,NodoGrafo*>* nd){nodos=nd;}
             public: HashMap<int,NodoGrafo*>* getNodos(){return nodos;};
             
             public: void setMA(int a[256][256])
             {
                  for(int i=0; i<NMAX;i++)
                        for(int j=0;j<NMAX;j++)
                                matrizAdyacencia[i][j]=a[i][j];
             }
             
             public: void setMPCS(int a[256][256])
             {
                  for(int i=0; i<NMAX;i++)
                        for(int j=0;j<NMAX;j++)
                                matrizAdyacenciaPCS[i][j]=a[i][j];
             }
             
             
             
             public: HashMap<int, NodoGrafoPC*>* getNodosPCS(){return PCS;}
             
             public: void crearGrafo(){crearNodos();}
             
             public: void crearPCS()
             {
                  
                  for(int i=0;i<getCantidadDePCS();i++)
                  {
                          NodoGrafoPC* n;//si no trabajas con putero te tira cualqueir verdura en el numero de aristas... la verdadq  no entiendo q meirda pasa -..-
                          n=new NodoGrafoPC(NULL,i);
                          getNodosPCS()->add(i, n);
                          //cout<<"cree una pc"<<endl;
                  }
                  crearAristasYEnlazarPCS();
              }
             
             public: void crearAristasYEnlazarPCS()
             {
                  for (int i=0; i<getCantidadDeNodos();i++)
                  {
                      for(int j=0; j<getCantidadDePCS();j++)
                      {
                              if(matrizAdyacenciaPCS[i][j]!=0)
                              {
                                                              
                                   PCS->get(j)->setRouter(getNodos()->get(i));
                                   getNodos()->get(i)->getAristasPCS()->add(PCS->get(j),PCS->get(j)->getPesoDeArista());
                                   
                                    
                              }
                      }
                      getNodos()->get(i)->inicializarColaDePaquetesDePaginas();
                  }
              }
             
             public: void crearNodos()
             {
                  for(int i=0;i<cantNodos;i++)
                  {
                          NodoGrafo* n;//si no trabajas con putero te tira cualqueir verdura en el numero de aristas... la verdadq  no entiendo q meirda pasa -..-
                          n=new NodoGrafo(i);
                          getNodos()->add(i, n);
                  }
                  crearAristasYEnlazar();
             }
             
             private: void crearAristasYEnlazar()
             {
                  for (int i=0; i<cantNodos;i++)
                      for(int j=0; j<cantNodos;j++)
                      {
                              if(matrizAdyacencia[j][i]!=0)
                              {
                                    nodos->get(i)->addArista(nodos->get(j),matrizAdyacencia[j][i]);
                                    Cola<Paquete*>* col=new Cola<Paquete*>();
                                    nodos->get(i)->addCola(nodos->get(j),col);//fiajte aca en la creacion de las colas de los nodos grafo tipo router
                                    
                              }
                      }
              }
             
             //void  getMA(){return matrizAdyacencia;}
             public: void imprimirMatriz()
            {
                  int num= cantNodos;
                 for(int i=0;i<num;i++)
                 {
                         for(int j=0;j<num;j++)
                         {
                                 cout<<matrizAdyacencia[i][j]<<" ";
                         }
                         cout<<endl;
                 }
             }
             
             public: void imprimirMatrizPC()
            {
                  int num= cantNodos;
                 for(int i=0;i<num;i++)
                 {
                         for(int j=0;j<PCS->getCantDeDatos();j++)
                         {
                                 cout<<matrizAdyacenciaPCS[i][j]<<" ";
                         }
                         cout<<endl;
                 }
             }
             
             public: void imprimirGrafo()
             {
                  cout<<endl<<endl;
                  cout<<nodos->getCantDeDatos()<<endl;
                  cout<<"asdadas"<<endl<<endl<<"PROBANDOO::   ";
                  cout<<nodos->get(0)->getCantidadDeAristas();
                  cout<<endl;
                  for (int i=0; i<nodos->getCantDeDatos();i++)
                  {
                      cout<<"NODO: "<<i<<endl;
                      nodos->get(i)->toPrint();
                      
                  }
                  
              }
             
//---------------DIJKSTRA----------------
//le pasas el nodo desde el cual partis y hasta el cual queres llegar
              public: Lista <RutaD*>* dijkstra(int numeroDeNodo,int numeroDeNodoFinal)//NodoGrafo* desde, NodoGrafo* hasta)
              {
                    int origen=numeroDeNodo;
                   //cout<<endl<<"-------------"<<endl;
                   //cout<<"COMIENZA DIJKSTRA"<<endl;
                   float base=0.0;
                   //se eejcuta en un while q se ejecutara hasta q todos los nodos hallan sido visitados
                   NodoGrafo* desde=getNodos()->get(numeroDeNodo);//obtengo el nodo desde del hashmap q contiene todos los nodos de este grafo
                   
                   RutaD* rutaMasChica=NULL;
                   
                   Lista <RutaD*>* rutas=new Lista <RutaD*>();//son todas las rutas calculadas por Dijkstra
                   
                   RutaD* ruta= new RutaD(desde,desde,0);//son las rutas que calculadas por dijkstra... 
                   //esta es mi 1er ruta siempre..
                   //(las que tienen las distancias acumuladas)
                   //rutas->add(ruta);
                   
                   NodoGrafo* actual=desde;//nodo en el que estoy parado, al principio estoy parado en el nodo desde
                   
                   rutas->add(ruta);
                 
                   //cout<<"DESDE DIJKasdakljwd: "<<actual->getCantidadDeAristas()<<endl;
                   
                   //este es el 1er paso
                   //recorres las aristas a partir del nodo....
                   
                   
                   //siguientes pasos o pasos intermedios
                   //buscas las mas chicas de las rustas con costo total
                   
                   while(cantDeNodosVisitados!=nodos->getCantDeDatos()-1)
                   {
                                                                       
                       //cout<<endl<<endl<<"-----iteracion numero: "<<cantDeNodosVisitados<<endl<<endl;
                          
                       calcularRutasD(actual, rutas,base);
                       eliminarRepetidos(rutas);
                       rutaMasChica=getRutaMasChica(rutas);
                       actual=rutaMasChica->getHasta();
                       base=rutaMasChica->getCostoTotal();
                       
                       //cout<<endl<<"Ahora me paro en...:   "<<actual->getNumeroDeNodo()<<endl;
                       //2da iteracion a mano
                       //cout<<endl<<"Cantidad de rutas final: "<<rutas->getCantidadDeDatos()<<endl;
                       
                       cantDeNodosVisitados++;
                       //system("PAUSE");
                   }
                   
                   
                   
                   //dijkstra debe devolver una lista con todas las rutas 
                   
                   Lista <RutaD*>* rutasFinal=new Lista <RutaD*>();
                   
                   int numGuia=numeroDeNodoFinal;
                   bool encontrado=false;
                   //cout<<endl;
                   //system("PAUSE");
                   //aca esta el problema y no se xq
                   
                   //aca generas la rutaDeDijkstra que va a frenar hasta que encuentre el nodo desde el cual partí
                   //ya que se va esde adelante hacia atrás
                   while(encontrado!=true)
                   {   
                       //cout<<"whileee"<<endl;
                       for(int i=0;i<rutas->getCantidadDeDatos();i++)
                       {
                               //cout<<rutas->getCantidadDeDatos()<<endl;
                               //cout<<"siguiendo: "<<rutas->get(i)->getDato()->getHasta()->getNumeroDeNodo()<<endl;
                               if(rutas->get(i)->getDato()->getHasta()->getNumeroDeNodo()==numGuia)
                               {
                                   if(rutas->get(i)->getDato()->getHasta()->getNumeroDeNodo()==origen)//aca habia un 0 en vez de origen, fijate q paso
                                   {
                                       encontrado=true;
                                   }
                                   else
                                   {
                                       //cout<<"entro al else"<<endl;
                                       rutasFinal->add(rutas->get(i)->getDato());
                                       numGuia=rutas->get(i)->getDato()->getDesde()->getNumeroDeNodo();
                                       //cout<<"encontre "<<endl;
                                       //cout<<"fijate: "<<rutas->get(i)->getDato()->getHasta()->getNumeroDeNodo()<<endl;
                                   }
                                   
                                   //system("PAUSE");
                               }
                               //cout<<endl;
                       }
                                 
                       //encontrado=true; 
                   }
                   
                   //cout<<endl<<"La ruta es:"<<endl;
                   
                   //esto imprime las rutas de dijkstra en cada iteracion
                   /*for(int i=0;i<rutasFinal->getCantidadDeDatos();i++)
                   {rutasFinal->get(i)->getDato()->toPrint();}*/
                   
                   
                   //cout<<endl;
                   
                   resetearNodos();//si o si hay q resetear los nodos
                   
                   return rutasFinal;
                   
                   
                   
                   /*calcularRutasD(actual, rutas,base);
                   eliminarRepetidos(rutas);
                   rutaMasChica=getRutaMasChica(rutas);
                   actual=rutaMasChica->getHasta();
                   base=rutaMasChica->getCostoTotal();
                   
                   cout<<endl<<"cant de datos de la ruta: FINAL:   "<<rutas->getCantidadDeDatos()<<endl;*/
                   
                   
                       
                   //rutas->imprimirLista();
                 //}
                   
                   
                   
              }
              
              //testeado anda genial
              //NOTA IMPORTANTISIMA
              //para ahorrarte un if vos ahces todos los calculos siempre pero....  
              //aca estan los cout q te interesan y los toprint para testear paso a paso dijkstra
              
              //base es el costo total de recorrer un determinado camino creo...
              private: void calcularRutasD(NodoGrafo* actual, Lista <RutaD*>* rutas,float base)
              {
                   HashMap<NodoGrafo*, int> aristas;//almacenas las aristas del nodo en el que estas parado
                   
                   
                   //arsitas... tenes: <nodo al cual apunta, peso>
                   aristas=actual->getAristas();//agarro en el nodo el cual estoy parado, me paro.. y veo a que nodos puedo acceder
                   
                   for(int i=0; i<actual->getCantidadDeAristas();i++)
                   {                          //ACA ESTA EL PROBLEMA (PRIMER SUMANDO)
                   
                         if(aristas.getKeyPorIndex(i)->getFuevisitado()==false)
                         {
                         //ACA FIJATE EL AJDKASJDSAJKDa
                         //(actual->getColas()->getValuePorIndex(i)->getCantidadDeDatos()+1)
                             float costoTOTAL= 0.0;
                             float larguito=actual->getColas()->getValuePorIndex(i)->getCantidadDeDatos();
                             costoTOTAL=((1.0+larguito) /aristas.getValuePorIndex(i)) + base ;//el +1.0 es por si no tengo datos en la cola de paquetes hacia el nodo que esta apuntando
                             
                             //costoTOTAL=base+aristas.getValuePorIndex(i);//-----------------*****######//////_------------------
                             
                             //el renglon de arriba es para ahcer unDijkstra normal
                             
                             //cout<<"EN EL FOR RUTA D costo total: "<<setprecision(5)<<costoTOTAL<<endl;
                             
                             //deste, hasta, costo total de dijkstra
                             RutaD* rutaA= new RutaD(actual,aristas.getKeyPorIndex(i),costoTOTAL);
                             rutas->add(rutaA);
                             //rutaA->toPrint();
                             //cout<<"cant de datos de la ruta: "<<rutas->getCantidadDeDatos()<<endl;
                             costoTOTAL=0;
                         }
                   }
                   actual->setFueVisitado(true);
                   
               }
           
              //anda perfecto
              //elemina los repetidos de la columna hasta y se queda solo con el de menor distancia
              private: void eliminarRepetidos(Lista <RutaD*>* rutas)
              {
                   RutaD* a=NULL;
                   RutaD* b=NULL;
                   for (int i=0; i<rutas->getCantidadDeDatos();i++)
                   {
                       a=rutas->get(i)->getDato();
                       
                       for(int j=0; j<rutas->getCantidadDeDatos();j++)
                       {
                               if(j!=i)
                               {
                                    b=rutas->get(j)->getDato();
                               
                                   //te fijas cual es la distancia mas chica de los HASTA....
                                   if(a->getHasta()==b->getHasta())
                                   {
                                       if(a->getCostoTotal()>b->getCostoTotal())
                                       {
                                            rutas->remove(a);
                                            //cout<<endl<<"removi la ruta con:  i:"<<i<<"  j: "<<j;
                                            //a->toPrint();i--;
                                            i--;j--;
                                       }
                                       else if(a->getCostoTotal()==b->getCostoTotal())
                                       {
                                            rutas->remove(b);
                                            //cout<<endl<<"removi la ruta con:  i:"<<i<<"  j: "<<j;
                                            //b->toPrint();
                                            i--;j--;
                                       }
                                       else if(a->getCostoTotal()<b->getCostoTotal())
                                       {
                                            rutas->remove(b);
                                            //cout<<endl<<"removi la ruta con:  i:"<<i<<"  j: "<<j;
                                            //b->toPrint();
                                            i--;j--;
                                       }
                                            //MODIFICASTEEEE ESTOOOA SDKASDJASK DJASKD LCDSMTMSTMMKFASDM
                                       /*else if(a->getCostoTotal()==b->getCostoTotal())
                                            rutas->remove(b);
                                       else if(a->getCostoTotal()>b->getCostoTotal())
                                            rutas->remove(b);*/
                                       
                                       //j--;
                                   }
                               }
                               
                       }
                   }
              }
              
              //se fija cual es la ruta mas chica de Dijkstra del nodo que no esta visitado....
              private: RutaD* getRutaMasChica(Lista <RutaD*>* rutas)
              {
                   RutaD* rutaMin=NULL;
                   
                   
                   //rutaMin puede ser igual al 1er elemento que no halla sido visitado, que encontres en la lista de rutas
                   for (int i=0;i<rutas->getCantidadDeDatos();i++)
                   {
                       if(rutas->get(i)->getDato()->getHasta()->getFuevisitado()==false)
                       {
                             rutaMin=rutas->get(i)->getDato();
                             break;
                       }
                       
                   }
                   
                   float costoMin=rutaMin->getCostoTotal();
                   //int costoMin=0;
                   
                   for (int i=0;i<rutas->getCantidadDeDatos();i++)
                   {
                       //este toprint te imprime la tabla con las rutas calculadas.
                       //rutas->get(i)->getDato()->toPrint();
                         if(rutas->get(i)->getDato()->getHasta()->getFuevisitado()==false &&
                            rutas->get(i)->getDato()->getCostoTotal() < costoMin )
                         {
                               rutaMin=rutas->get(i)->getDato();
                               costoMin=rutaMin->getCostoTotal();
                         }
                   }
                   //ACA VAN LSO TESTEOS DE UNA RUTA MINIMA EN PANTALLA
                   //cout<<"la mas pequea cuesta: "<<rutaMin->getCostoTotal()<<endl;
                   //rutaMin->toPrint();
                   return rutaMin;
              }
              
              
              void resetearNodos()
              {
                   for(int i=0;i<getCantidadDeNodos();i++)
                   {
                           getNodos()->get(i)->setFueVisitado(false);
                           
                   }
                   cantDeNodosVisitados=0;
               }
               
               
              

             
             
             
            
            
};

#endif
/*

int main()
{
    cout<<"GRAFOOO   "<<endl;
    
    Grafo g(7);
    NodoGrafo ng(2);
    g.getNodos().add(&ng);
    
    
    system("PAUSE");
}
*/

