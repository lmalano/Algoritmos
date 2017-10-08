#ifndef NodoGrafoPC_cpp
#define NodoGrafoPC_cpp

#include <cstdlib>
#include <iostream>

#include "NodoGrafoPadre.cpp"
#include "Pagina.cpp"
#include "Cola.cpp"
#include "Lista.cpp"

using namespace std;





class NodoGrafoPC :public NodoGrafoPadre
{
    private: 
             int cantidadDePaginasGeneradas;
             NodoGrafoPadre* router;
             Pagina* pagina;
             int pesoArista;
             int numeroDePC;
             Cola<Pagina*>* paginasRecibidas;
             
    public:
             NodoGrafoPC(int numDePC)
             {
                 router=NULL;
                 this->pesoArista=1000000;
                 numeroDePC=numDePC;
                 paginasRecibidas=new Cola<Pagina*>;
                 cantidadDePaginasGeneradas=0;
                 pagina=NULL;
                 cout<<"se creo el nodo grafo pc"<<endl;
 
             }
             
             NodoGrafoPC(NodoGrafoPadre* router, int numDePC)
             {
                 this->router=router;
                 this->pesoArista=1000000;
                 numeroDePC=numDePC;
                 paginasRecibidas=new Cola<Pagina*>;
                 cantidadDePaginasGeneradas=0;
                 pagina=NULL;
                 cout<<"se creo el nodo grafo pc"<<endl;
 
             }
             
             //testeado
             void crearPagina(int peso,NodoGrafoPC* NGPCDestino)
             {
                  //cout<<"se crea la pagina"<<endl;
                  int routerOrigen=this->getRouter()->getNumeroDeNodo();
                  int routerDestino=NGPCDestino->getRouter()->getNumeroDeNodo();
                  int pcOrigen=this->getNumeroDePC();
                  int pcDestino=NGPCDestino->getNumeroDePC();
                  
                  Cola<char>* mensaje=new Cola<char>();
                  
                  if(peso<5){peso=5;}else if(peso>50){peso=50;}
                  
                  for (int i=0;i<peso;i++)
                  {
                      char letra;//preguntar como hago si tengo que letra sea un puntero a un tipo char
                      int ascii=i+64;//https://stackoverflow.com/questions/11268289/c-convert-char-into-char
                      letra= ascii;
                      mensaje->add(letra);
                      //cout<<"el valorcitoooo: "<<letra<<endl;
                  }
                  cantidadDePaginasGeneradas++;
                  
                  this->pagina= new Pagina(peso,routerOrigen,routerDestino ,pcOrigen,pcDestino,getCantidadDePaginasGeneradas(),mensaje);
                  
                  
             }
             
             int getCantidadDePaginasGeneradas(){return cantidadDePaginasGeneradas;}
             
             Cola<Pagina*>* getPaginasRecibidas(){return paginasRecibidas;}
             
             int getNumeroDePC(){return numeroDePC;}
             
             
             //testeado
             void enviarPagina()
             {
                  router->getPaginasRecibidas()->add(this->getPaginaGenerada());
                  this->pagina=NULL;
              }
              
              Pagina* getPaginaGenerada(){return this->pagina;}
              
              NodoGrafoPadre* getRouter(){return router;}
              void setRouter(NodoGrafoPadre* nod){router=nod;}
              
              
              void imprimirPaginas()
              {
                   for(int i=0;i<getPaginasRecibidas()->getCantidadDeDatos();i++)
                   {
                        Pagina* paginaTemporal= getPaginasRecibidas()->get(i);
                        paginaTemporal->imprimirPagina();
                        cout<<endl;
                        
                   }
                   cout<<endl<<"Termino la impresion"<<endl<<"-----------------------------------"<<endl;
                   
               }
              
              //testeado
                void imprimirPaginaGenerada()
               {
                     if(getPaginaGenerada()!=NULL)
                    getPaginaGenerada()->imprimirPagina();
                    else
                    cout<<"En la PC: "<<getNumeroDePC()<<" no se ha generado ninguna pagina o no tiene ya una"<<endl;
                }
                
                
                //testeado
              void toPrint()
              {
                  cout<<"Desde el nodo "<<getNumeroDePC()<<endl;
                  cout<<"LAS ARISTAS APUNTAN A:"<<endl<<endl;
                  cout<<"NODO------PESO"<<endl;
                  cout<<"Router: "<<getRouter()->getNumeroDeNodo()<<"  peso de: "<<pesoArista;
                  cout<<endl;
                  
             }
             int getPesoDeArista(){return pesoArista;}
             
             
             
             
             
};

/*
int main()
{
    
    
    system("PAUSE");
}
*/
#endif
