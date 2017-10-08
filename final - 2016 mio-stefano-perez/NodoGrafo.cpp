
#ifndef NodoGrafo_cpp
#define NodoGrafo_cpp

#include <stdio.h>
#include <string.h>

#include <cstdlib>
#include <iostream>
#include <string>
//#include "Cola.cpp"
#include "HashMap.cpp"
#include "Paquete.cpp"
#include "Cola.cpp"
#include "Nodo.cpp"
#include "Pagina.cpp"
#include "NodoGrafoPadre.cpp"
//#include "NodoGrafoPC.cpp"


using namespace std;



class NodoGrafo : public NodoGrafoPadre
{
    private: 
             
             Cola<Paquete*>* colaDeEspera;
             int tipoNodo;//si es 0 es router, si es 1 es pc
             //Lista<int> lista;
             /*NodoGrafo* PC;
             int pesoPC;*/
             HashMap<int, NodoGrafo* >* rutasRecomputadas;
             
             string prefijo;
             int numeroDeNodo;
             
             HashMap<NodoGrafoPadre*,int>* aristasPCS;
             
             HashMap<NodoGrafo*,int> aristas;//son los routers o vamos a ver si lo mezclamo sa todo y chau
             HashMap<NodoGrafo*,Cola<Paquete*>*>* colas;
             HashMap<NodoGrafoPadre*,HashMap<string,Cola<Paquete*>*>*>* colaDePaquetesDePaginas;
             Cola<Pagina*>* paginasRecibidas;
             
             int cantidadDeAristas;
             bool visitado;
    public:
             NodoGrafo(int numeroDeNodo):NodoGrafoPadre()
             {
                           
                           //PC=NULL;
                           aristasPCS=new HashMap<NodoGrafoPadre*,int>();
                           paginasRecibidas=new Cola<Pagina*>();
                           rutasRecomputadas=new HashMap<int, NodoGrafo*>();
                           tipoNodo=0;
                           visitado=false;
                           cantidadDeAristas=0;
                           aristas;prefijo="Nodo_Router_";
                           this->numeroDeNodo=numeroDeNodo;
                           
                           colaDeEspera=new Cola<Paquete*>();
                           colas=new HashMap<NodoGrafo*,Cola<Paquete*>*>();
                           colaDePaquetesDePaginas=new HashMap<NodoGrafoPadre*,HashMap<string,Cola<Paquete*>*>*>();
                           inicializarColaDePaquetesDePaginas();
                           
             
             }
             NodoGrafo(int numeroDeNodo, int tipoNod):NodoGrafoPadre()
             {
                           aristasPCS=new HashMap<NodoGrafoPadre*,int>();
                           paginasRecibidas=new Cola<Pagina*>();
                           rutasRecomputadas=new HashMap<int, NodoGrafo*>();
                           tipoNodo=tipoNod;
                           visitado=false;
                           cantidadDeAristas=0;
                           if(tipoNod==0)
                           {prefijo="Nodo_Router_";}
                           else
                           {prefijo="Nodo_PC_";}
                           aristas;
                           this->numeroDeNodo=numeroDeNodo;
                           
                           colaDeEspera=new Cola<Paquete*>();
                           colas=new HashMap<NodoGrafo*,Cola<Paquete*>*>();
                           colaDePaquetesDePaginas=new HashMap<NodoGrafoPadre*,HashMap<string,Cola<Paquete*>*>*>();
                           inicializarColaDePaquetesDePaginas();
                           
             
             }
             
             NodoGrafo(int numeroDeNodo, HashMap<NodoGrafo*,int> aristas):NodoGrafoPadre()
             {
                   aristasPCS=new HashMap<NodoGrafoPadre*,int>();
                   paginasRecibidas=new Cola<Pagina*>();
                   rutasRecomputadas=new HashMap<int, NodoGrafo*>();
                   tipoNodo=0;
                   visitado=false;
                   this->aristas=aristas;
                   cantidadDeAristas=0;
                   aristas;prefijo="Nodo_Router_";
                   this->numeroDeNodo=numeroDeNodo;
                   
                   colaDeEspera=new Cola<Paquete*>();
                   colas=new HashMap<NodoGrafo*,Cola<Paquete*>*>();
                   colaDePaquetesDePaginas=new HashMap<NodoGrafoPadre*,HashMap<string,Cola<Paquete*>*>*>();
                   inicializarColaDePaquetesDePaginas();
             }
             
             void inicializarColaDePaquetesDePaginas()
             {
                  for (int i=0;i<getAristasPCS()->getCantDeDatos();i++)
                  {
                      //agregas un nodo grafo pc
                      NodoGrafoPadre* NGPC=getAristasPCS()->getKeyPorIndex(i);
                      HashMap<string,Cola<Paquete*>*>* HM= new HashMap<string,Cola<Paquete*>*>();
                      colaDePaquetesDePaginas->add(NGPC,HM);
                  }
             }
           
           
           
             HashMap<int, NodoGrafo* >* getRutasRecomputadas(){return rutasRecomputadas;}
             
             Cola<Pagina*>* getPaginasRecibidas(){return paginasRecibidas;}
             //TESTEADO
             void setRutasRecomputadas(HashMap<int, NodoGrafo* >* routRecomps)
             {
                  for (int i=0;i<routRecomps->getCantDeDatos();i++)
                  {
                      //rutasRecomputadas.add(routRecomps->getKeyPorIndex(i),routRecomps->get(i));
                      getRutasRecomputadas()->add(routRecomps->getKeyPorIndex(i),routRecomps->getValuePorIndex(i));
                  }
             }
             
             HashMap<NodoGrafoPadre*,int>* getAristasPCS(){return aristasPCS;}
             
             void addCola(NodoGrafo* n, Cola<Paquete*>* col){colas->add(n,col);}
             Cola<Paquete*>* getColaDeEspera(){return colaDeEspera;}
             
             //ABAJO FIJATE
              HashMap<NodoGrafo*,Cola<Paquete*>*>* getColas(){return colas;}
             
             //
             void enviarPaquetes()//NodoGrafo* origen, NodoGrafo* destino, Paquete* paqueteAEnviar)
             {
                  //envia un poquete a cada nodo por vez
                  for (int i=0; i<colas->getCantDeDatos();i++)
                  {
                      //aca en teoria te paras en el 1er nodo del HM y envias hasta agotar la cant de paquetes q podes enviar en el ancho de banda eso es todo
                      
                      if(colas->getValuePorIndex(i)->esVacio()==false)
                      {
                          Paquete* paqueteAAgregar=colas->getValuePorIndex(i)->getNodoCabeza()->getDato();//obtengo el paquete q esta en la cabeza de la cola del HM bah del value del HM
                          colas->getKeyPorIndex(i)->getColaDeEspera()->add(paqueteAAgregar);//agrego el paquete en la cola de espera de el nodo alcual lo queiro enviar
                          colas->getValuePorIndex(i)->removeCabeza();//elimino el dato de el HM
                          i--;
                      }
                  }
                      
              }
              
             //NOTA!!! no hace falta intercalar los paquetes. lo q tenes q hacer es mandarlo todo a la tabla de envios directamente creo...
             //q para cada nodo hay una cola de paquetes
              
             void recibirPaquetes()
             {
                  HashMap<NodoGrafo*,int>* contadorDePaquetesRecibidos=new HashMap<NodoGrafo*,int>();
                  for(int i=0;i<getAristas().getCantDeDatos();i++)
                  {
                          contadorDePaquetesRecibidos->add(getAristas().getKeyPorIndex(i),0);
                  }
                  
                  //vas a pasar todos los paquetes a donde corresponde siempre y cuando no supere a la cantidad que tolera el anchod e badna para enviar
                  //ej si el peso es de 5 paquetes yo no voy a enviar mas de 5 paquetes a esa cola asi cuando hace el instant send 
                  //no manda paquetes de mas
                  
                  for(int i=0;i<getColaDeEspera()->getCantidadDeDatos();i++)
                  {
                          int numeroDeRouterDestino=getColaDeEspera()->getDatoPorIndex(i)->getRouterDestino();
                          NodoGrafo* NG=getRutasRecomputadas()->get(numeroDeRouterDestino);
                          
                          int cantPaqDelNG=contadorDePaquetesRecibidos->get(NG);
                          int pesoAComparar=getAristas().get(NG);
                          if(numeroDeRouterDestino==this->getNumeroDeNodo())
                          {
                               //enrealidad obtenes el paquete y lo pasa como parametro no olvidarte de eso
                               Paquete* elPaq=getColaDeEspera()->getNodo(i)->getDato();
                               
                               reacomodarPaquetesParaLasPCS(elPaq);
                               
                               getColaDeEspera()->remove(elPaq);
                               i--;
                          }
                          else if(numeroDeRouterDestino!=this->getNumeroDeNodo() && cantPaqDelNG<pesoAComparar)
                          {
                               Paquete* elPaq=getColaDeEspera()->getNodo(i)->getDato();
                               
                               NodoGrafo* nodoParaOrdenarLaCola= getRutasRecomputadas()->get(numeroDeRouterDestino);                            
                               getColas()->get(nodoParaOrdenarLaCola)->add(elPaq);
                               
                               getColaDeEspera()->remove(elPaq);
                               int cont=contadorDePaquetesRecibidos->get(NG);
                               cont++;
                               
                               contadorDePaquetesRecibidos->getNodoPorKey(NG)->setValue(cont);
                               
                               
                               i--;
                               
                          }
                          
                          //cout<<"El nodo / router: "<<getNumeroDeNodo()<<"  recibio todos los paquetes"<<endl;
                          
                  }
                  
              }
              
              //hay q modificarlo xq lo hace con el nodo cabeza..... hay q pasarle directamente el paquete....
             void reacomodarPaquetesParaLasPCS(Paquete* paquetito)
             {
                  //cout<<"REACOMODANDOOO!!"<<endl;
                  //en realidad va getColasDePaquetesdePaginas()->getCantidadDeDatos(); peeeero... si esta todo correcto no tiene q haber problemas es lo mismo
                  for (int i=0; i<getColaDePaquetesDePaginas()->getCantDeDatos();i++)
                  {
                      //esto esta mal o comparas numeros de pc o numeros de routers... fijate
                      //int numAComparar1= getColaDePaquetesDePaginas()->getKeyPorIndex(i)->getRouter()->getNumeroDeNodo();
                       int numAComparar1=getColaDePaquetesDePaginas()->getKeyPorIndex(i)->getNumeroDePC();
                       int numAComparar2=getColaDeEspera()->getNodoCabeza()->getDato()->getPcDestino();
                       if(numAComparar1==numAComparar2)
                       {
                            HashMap<string,Cola<Paquete*>*>* HM = getColaDePaquetesDePaginas()->getValuePorIndex(i);
                            string prefijoDelPaquete=paquetito->getPrefijo();
                            Paquete* paqueteAAgregar=paquetito;
                            if(HM->containsKey(prefijoDelPaquete))
                            {
                                 HM->get(prefijoDelPaquete)->add(paqueteAAgregar);
                            }
                            else
                            {
                                HM->add(prefijoDelPaquete,new Cola<Paquete*>());
                                HM->get(prefijoDelPaquete)->add(paqueteAAgregar);
                            }
                       }
                  }
             }
             
             
              
             HashMap<NodoGrafoPadre*,HashMap<string,Cola<Paquete*>*>*>* getColaDePaquetesDePaginas(){return colaDePaquetesDePaginas;}
               
              
             bool esUnNodoPC() {if(tipoNodo==1){return true;}else {return false;}}
             bool esUnNodoRouter() {if(tipoNodo==0){return true;}else {return false;}}
              
              ///ARRIBA
             
             
             
             
             void setFueVisitado(bool visit)
             {
                  visitado=visit;
              }
              
              bool getFuevisitado()
              {
                   return visitado;
               }
             
             int getCantidadDeAristas(){return cantidadDeAristas;}
             HashMap<NodoGrafo*,int> getAristas(){return aristas;}

             void addArista(NodoGrafo* key, int value)
             {
                  //aristas.containsKey(key);
                  aristas.add(key,value);
                  
                  cantidadDeAristas++;
             }
             void imprimirAristas(){aristas.imprimirHash();}
             
             /*void toPrint()
             {
                  if(cantidadDeAristas>0)
                  {
                        jk
                        
                  }
             }*/
             
             int getNumeroDeNodo(){return numeroDeNodo;}
             
             void toPrint()
             {
                  cout<<"Desde el nodo "<<getNumeroDeNodo()<<endl;
                  cout<<"LAS ARISTAS APUNTAN A:"<<endl<<endl;
                  cout<<"NODO------PESO"<<endl;
                  for(int i=0; i<getAristas().getCantDeDatos();i++)
                  {
                       cout<<"  "<<getAristas().getKeyPorIndex(i)->getNumeroDeNodo();
                       cout<<"        "<<getAristas().getValuePorIndex(i)<<endl;
                  }
                  cout<<endl;
                  
             }
             
             
             //TESTEADO!!!!
             void generarPaquetes()
             {
                  for(int j=0;j<getPaginasRecibidas()->getCantidadDeDatos();j++)
                  {
                      Pagina* paginaRecibidaDePC=getPaginasRecibidas()->getNodoCabeza()->getDato();
                      for(int i=0;i<paginaRecibidaDePC->getPeso();i++)
                      {
                              //cout<<"-------el peso de:------------- "<<paginaRecibidaDePC->getPeso()<<endl;
                              char dato=paginaRecibidaDePC->getMensaje()->getNodo(i)->getDato();
                              int routerOrigen=paginaRecibidaDePC->getRouterOrigen();
                              int routerDestino=paginaRecibidaDePC->getRouterDestino();
                              int pcOrigen=paginaRecibidaDePC->getPcOrigen();
                              int pcDestino=paginaRecibidaDePC->getPcDestino();
                              Paquete* paquetito=new Paquete(1,i,routerOrigen,routerDestino,pcOrigen,pcDestino,paginaRecibidaDePC->getPeso(),dato,paginaRecibidaDePC->getNumeroDePagina());
                              getColaDeEspera()->add(paquetito);
                              paquetito->imprimirPaquete();
                      }
                      getPaginasRecibidas()->removeCabeza();
                      j--;
                  }
              }
             
             void enviarPaginasALasPCS()
             {
                  for (int i=0;i<getColaDePaquetesDePaginas()->getCantDeDatos();i++)
                  {
                      //cout<<"aca tenes tu cantidad de datos hmp: "<<getColaDePaquetesDePaginas()->getCantDeDatos()<<endl;
                      HashMap<string,Cola<Paquete*>*>* HM=getColaDePaquetesDePaginas()->getValuePorIndex(i);
                      //cout<<"TENGO UN i= "<<i<<endl;
                      //cout<<"aca tenes tu cantidad de datos hmp: "<<HM->getCantDeDatos()<<endl;
                      //system("PAUSE");
                      
                      for(int j=0;j<HM->getCantDeDatos();j++)
                      {
                              int cantDeDat=HM->getValuePorIndex(j)->getCantidadDeDatos();//cantidad de datos de la cola
                              //int cantDeDatAComparar=HM->getValuePorIndex(j)->getCabeza()->getPeso();
                              int cantDeDatAComparar=HM->getValuePorIndex(j)->getCabeza()->getCantidadDePaquetesTotal();
                              if(cantDeDat==cantDeDatAComparar)
                              {
                                    //ordenarCola(HM->getValuePorIndex(j));
                                    
                                    
                                    Pagina* paginaReconstruida=reconstruirPagina(HM->getValuePorIndex(j));
                                    string texto=HM->getKeyPorIndex(j);
                                    getColaDePaquetesDePaginas()->getKeyPorIndex(i)->getPaginasRecibidas()->add(paginaReconstruida);
                                    //cout<<"PAGINA RECONSTRUIDA CARAJO!!!!"<<endl;
                                    //paginaReconstruida->imprimirPagina();
                                    //system("PAUSE");
                                    
                                    //cout<<"ACA LA TENES PAPA!!!! "<<texto<<endl;
                                    //getColaDePaquetesDePaginas()->getKeyPorIndex(1)->getPaginasRecibidas()->get(0)->imprimirPagina();
                                    //system("PAUSE");
                                    HM->remove(texto);//ACA ESTA EL PROBLEMA
                                    //cout<<"La pagina llego"<<endl;
                                    //paginaReconstruida->imprimirPagina();
                                    //system("PAUSE");
                                    j--;
                                    
                              }
                              
                      }
                  }
             }
             
             //TESTEADOOO!!!!
             //HABRIA Q REORDENAR LOS PAQUETES 1ro PERO YA VAMOSA VER ESO!!!!!
             Pagina* reconstruirPagina(Cola<Paquete*>* colaDePaquetes)
             {
                  Paquete* paquetito=colaDePaquetes->getCzo()->getDato();
                  
                  int peso= paquetito->getPeso();
                  int routerOrigen=paquetito->getRouterOrigen();
                  int routerDestino=paquetito->getRouterDestino();
                  int pcOrigen=paquetito->getPcOrigen();
                  int pcDestino=paquetito->getPcDestino();
                  int numeroDePagina=paquetito->getNumeroDePagina();
                  Cola<char>* mensaje=new Cola<char>();
                  
                  Pagina* nuevaPag=new Pagina(peso, routerOrigen,routerDestino,pcOrigen,pcDestino,numeroDePagina,mensaje);
                  for(int i=0;i<colaDePaquetes->getCantidadDeDatos();i++)
                  {
                       char letrita=colaDePaquetes->get(i)->getLetra();
                       nuevaPag->getMensaje()->add(letrita);
                       
                  }
                  return nuevaPag;
             }
             
             /*void ordenarCola(Cola<Paquete*>* cola)
            {
                 int iMax=0;
                 for(int i=0;i<cola->getCantidadDeDatos()-1;i++)
                 {
                         iMax=0;
                 
                         for (int j=i+1;j<cola->getCantidadDeDatos();j++)
                         {
                             if(cola->getNodo(j)->getDato()->getNombre()>cola->getNodo(i)->getDato()->getNombre())
                             {
                                 iMax=j;
                                 Paquete* a=cola->getNodo(i)->getDato();  //M[i];
                                 Paquete* b=cola->getNodo(iMax)->getDato();//  M[iMax];
                                 cola->getNodo(i)->set_dato(b);
                                 cola->getNodo(iMax)->set_dato(a);
                             }
                             
                         }
                 }
                         
                         
            }*/
            
            
};

#endif
//testeo...

/*
int main()
{
    cout<<"NODO GRAFO"<<endl<<endl;
    NodoGrafo* nodo1=new NodoGrafo(1);
    NodoGrafo* nodo2=new NodoGrafo(2);
    NodoGrafo* nodo3=new NodoGrafo(3);
    
    nodo1->addArista(nodo2,20);
    nodo1->addArista(nodo3,10);
    nodo1->toPrint();
    
    cout<<"El nodo apunta a tantos datos: "<<nodo1->getAristas().getCantDeDatos()<<endl<<endl;
    
    //cout<<endl<<"la cantidad es de: "<<nodo1.getCantidadDeAristas()<<endl;
    system("PAUSE");
}
*/
