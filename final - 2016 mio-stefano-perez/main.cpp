#include <iostream>
#include <iostream>
#include <string>
#include "Grafo.cpp"
#include "Paquete.cpp"
#include <iomanip>
#include <time.h> 
#include <dos.h>
#include "NodoGrafoPadre.cpp"
#include "NodoGrafoPC.cpp"



using namespace std;

void imprimirTablaDeRutasDelRouter(Grafo g,int num);


void GenerarMatrizPCS(int alto);
void recomputarRutasDeLosRouters(Grafo g);
int leerArchivo1();
void leerArchivo2(int num);
int leerArchivo3();
void leerArchivo4(int num);
void GenerarMatriz();

int MA[256][256];
int MPC[256] [256];

void imprimirMatriz(int num);
void imprimirPC(int num,int num2);

int main ()
{
    
    
    int cantidadDeNodos=0;
    int cantidadDePCS=0;
    cout<<"LPM2"<<endl<<endl;
    
    //GenerarMatriz();
    cantidadDeNodos=leerArchivo1();
    //GenerarMatrizPCS(cantidadDeNodos);
    cantidadDePCS=leerArchivo3();
    cout<<"cantidad de nodos= "<<cantidadDeNodos<<endl;
    cout<<"La cantidad de pcs es de:= "<<cantidadDePCS<<endl;
    system("PAUSE");
    
    leerArchivo2(cantidadDeNodos);
    leerArchivo4(cantidadDePCS);
    cout<<"DAME LA CANT DE PCS: "<<cantidadDePCS<<endl;
    Grafo g(cantidadDeNodos, cantidadDePCS);
    g.setMA(MA);
    g.setMPCS(MPC);
    //imprimirMatriz(cantidadDeNodos);
    g.imprimirMatriz();
    g.crearGrafo();
    g.crearPCS();
    
    
    
    cout<<endl<<endl;
    
    g.getNodosPCS()->get(7)->toPrint();
    cout<<"asd---"<<endl;
    system("PAUSE");
    
    
    g.dijkstra(2,5);
    
    
    
    cout<<endl<<"aca esta el 1er testeo de Dijkstra"<<endl<<endl;
    system("PAUSE");
    
    //testeo de los metodos de los routers
    
    
    
    
    /*cout<<"Creamos las paginas"<<endl;
    //hay q calcular todos los caminos posibles de cada Router a Cada PC::::
    for (int i=0;i<g.getCantidadDePCS();i++)
    {
        int index2=g.getCantidadDePCS()-1-i;
        g.getNodosPCS()->get(i)->crearPagina(i+5,g.getNodosPCS()->get(index2));
        //g.getNodosPCS()->get(i)->imprimirPaginaGenerada();
        g.getNodosPCS()->get(i)->enviarPagina();
        //g.getNodosPCS()->get(i)->imprimirPaginaGenerada();
    }*/
    cout<<"Ahora recomputamos las rutas"<<endl;
    system("PAUSE");
    recomputarRutasDeLosRouters(g);
    
    //testeo de paginas Lo q hace es crear una pagina y enviarlo a otra pc q esta conectado
    //al mismo router de origen....
    g.getNodosPCS()->get(0)->crearPagina(5+5,g.getNodosPCS()->get(7));
    g.getNodosPCS()->get(0)->imprimirPaginaGenerada();
    g.getNodosPCS()->get(0)->enviarPagina();
    g.getNodosPCS()->get(0)->imprimirPaginaGenerada();
    g.getNodosPCS()->get(0)->getRouter()->getPaginasRecibidas()->get(0)->imprimirPagina();
    //g.getNodosPCS()->get(0)->getRouter()->generarPaquetes();
    g.getNodos()->get(0)->generarPaquetes();
    g.getNodosPCS()->get(0)->getRouter()->getPaginasRecibidas()->get(0)->imprimirPagina();
    
    cout<<"tenemos aca la impresion de los paquetesd entro de la cola"<<endl<<endl;
    system("PAUSE");
    for (int i=0;i<g.getNodos()->get(0)->getColaDeEspera()->getCantidadDeDatos();i++)
    {
        //el problema esta en la cola de espera
        g.getNodos()->get(0)->getColaDeEspera()->get(i)->imprimirPaquete();
    }
    
    g.getNodos()->get(0)->recibirPaquetes();
    
    HashMap<NodoGrafoPadre*,HashMap<string,Cola<Paquete*>*>*>* colaDePaquetesDePaginas=g.getNodos()->get(0)->getColaDePaquetesDePaginas();
    HashMap<string,Cola<Paquete*>*>* HM=colaDePaquetesDePaginas->getValuePorIndex(1);
    cout<<"el tamanitouu es de: "<<HM->getCantDeDatos()<<endl;
    cout<<"tenemos x paquetes= "<<HM->getValuePorIndex(0)->getCantidadDeDatos()<<endl;
    g.getNodos()->get(0)->enviarPaquetes();//este hay q testearlo en caso de q halla muchos dentro
    
    
    g.getNodos()->get(0)->enviarPaginasALasPCS();
    
    cout<<endl<<"los paquetes han sido enviados ahora tenemos......."<<endl;
    cout<<"el tamanitouu es de: "<<HM->getCantDeDatos()<<endl;
    //cout<<"tenemos x paquetes= "<<HM->getValuePorIndex(0)->getCantidadDeDatos()<<endl;
    
    
    //-------------------------------------
    //encviamos una pagina de la pc 0 a la pc 6 como esta lejos aproximadamente en 4 iteraciones tiene q llegar si.. en 6 como max calculo yo
    g.getNodosPCS()->get(0)->crearPagina(5+10,g.getNodosPCS()->get(6));
    
    g.getNodosPCS()->get(0)->enviarPagina();
    g.getNodosPCS()->get(0)->crearPagina(5+5,g.getNodosPCS()->get(6));
    g.getNodosPCS()->get(0)->enviarPagina();
    
    for(int i=0;i<40;i++)
    {
        
        
        for(int j=0;j<g.getCantidadDeNodos();j++)
        {
            g.getNodos()->get(j)->generarPaquetes();
            
        }
        
        for(int c=0;c<g.getCantidadDeNodos();c++)
        {
             cout<<endl<<"############La cantidad de paquetes en la cola de espera del nodo: "<<c<<" es de: "<<g.getNodos()->get(c)->getColaDeEspera()->getCantidadDeDatos()<<endl;
        }
        cout<<"-------------------------------------------------------------------------------------------------------------------";
        for(int j=0;j<g.getCantidadDeNodos();j++)
        {
            g.getNodos()->get(j)->recibirPaquetes();
        }
        
        if(i%2==0){recomputarRutasDeLosRouters(g);}
        
        for(int j=0;j<g.getCantidadDeNodos();j++)
        {
            g.getNodos()->get(j)->enviarPaquetes();
        }
        
        for(int j=0;j<g.getCantidadDeNodos();j++)
        {
            g.getNodos()->get(j)->enviarPaginasALasPCS();
        }
        
        
        
    }
        
    //g.getNodosPCS()->get(6)->getPaginasRecibidas()->get(1)->imprimirPagina();
    g.getNodosPCS()->get(6)->imprimirPaginas();
    
    //g.getNodosPCS()->get(6)->getPaginasRecibidas()->get(0)->ordenarPagina();
    //g.getNodosPCS()->get(6)->getPaginasRecibidas()->get(1)->ordenarPagina();
    
    cout<<endl<<"asdasd"<<endl;
    
    g.getNodosPCS()->get(6)->imprimirPaginas();
    
    
    
    cout<<endl<<"TERMINAMOSS TODO EL CICLO"<<endl;
    //g.getNodos()->get(0)->enviarPaginasALasPCS();
    
    system("PAUSE");
    
    
    //g.getNodos()->get(0)->enviarPaquetes();
   
    cout<<endl<<"ILOLAIII"<<endl<<endl;
    g.getNodosPCS()->get(7)->getPaginasRecibidas()->get(0)->imprimirPagina();
    
    cout<<"ahora arranca el ultimo testeo completo"<<endl<<endl;//---------------------------------------------------
    system("PAUSE");
    
    
    
    
    
    
    
    
    system("PAUSE");
}

 
 
 
 
 //---------------------------------
 

void imprimirTablaDeRutasDelRouter(Grafo g,int num)
{
    int nodoQueQuieroImprimirElHash=num;
    cout<<"IMPRIMIMOS EL HAS DEL NODO "<<nodoQueQuieroImprimirElHash<<endl;
    for(int z=0; z<g.getNodos()->get(nodoQueQuieroImprimirElHash)->getRutasRecomputadas()->getCantDeDatos(); z++)
    {
         cout<<"  "<<g.getNodos()->get(nodoQueQuieroImprimirElHash)->getRutasRecomputadas()->getKeyPorIndex(z);
         cout<<"   "<<g.getNodos()->get(nodoQueQuieroImprimirElHash)->getRutasRecomputadas()->getValuePorIndex(z)->getNumeroDeNodo()<<endl;
    }
     
 } 
 
void recomputarRutasDeLosRouters(Grafo g)
{
     HashMap<int, NodoGrafo* >* rutasRecomputadas;
    
    rutasRecomputadas= new HashMap<int, NodoGrafo* >();
    
    //aca se recomputan los caminos
    //el i representa el desde (router) i el j representa el hasta (router)
    for (int i=0; i<g.getCantidadDeNodos();i++)
    {
        for (int j=0; j<g.getCantidadDeNodos();j++)
        {
            if(i!=j)
            {
                //cuando este en i, estoy en el router i.... por ende busco el camino mas corto o mejor dicho con menor trafico
                //para ir desde i hacia j... como nunk vamos a tener el problema de q iremos desde un router x hacia ém mismo oseaaaa hacia x
                //nuevamente u otra vez... lo q haremos es.... 
                //una vez q dijkstra nos devuelva la lista de las rutas.... buscaremos en cada elemento de la lista que se encuentre en el nodo
                //desde el nodo i, una vez encontrado... obtenemos el nodo Hasta y lo ponemos por ende...
                //para llegar a j desde i metemos en el router i, esta lista de routas recomputadas
                //q nos indican desde ese router hacia q router tiene q ir para llegar al destino deseado...
                //si tenemos 256 routers vamos a tener 255 rutas recomputadas...
                //cout<<"sale DIJKSTRASDasjkdajsdl con:   i:"<<i<<"  j:"<<j<<endl;
                Lista<RutaD*>* listaRutasDijkstra= g.dijkstra(i,j);
                rutasRecomputadas->add (j, listaRutasDijkstra->get(0)->getDato()->getHasta() );
                
            }
        }   
        
        g.getNodos()->get(i)->setRutasRecomputadas(rutasRecomputadas);
        
        
        
        rutasRecomputadas->clear();
    }
     
     
     
} 
 
 
 
 
 
 
int leerArchivo1()
{
       char letra;
       bool salto=false;
       int contador=0;//es un contador de datos
       ifstream archivo_entrada("archivo_entrada.txt"); 
       
       if(!archivo_entrada.fail())
       {
            while(!archivo_entrada.eof())
            {
                 archivo_entrada.get(letra);
                 if(salto==false && letra==' ')
                       contador++;
                 else if(letra=='\n')
                       {salto=true;break;}
                 //cout<<"asd"<<endl;//va a tirar como 13 asd xq son 7 datos  y 5 epacios antesd e q encuentre el salto de linea o lane XD
            }
            contador++;
       }
       else
       {
           cout<<"Archivo no encontrado"<<endl;
       }
       
       cout<<"Cantidad de nodos es de: "<<contador<<endl;
       return contador;

       
}


int leerArchivo3()
{
       char letra;
       bool salto=false;
       int contador=0;//es un contador de datos
       ifstream archivo_entrada("pcs_entrada.txt"); 
       
       if(!archivo_entrada.fail())
       {
            while(!archivo_entrada.eof())
            {
                 archivo_entrada.get(letra);
                 if(salto==false && letra==' ')
                       contador++;
                 else if(letra=='\n')
                       {salto=true;break;}
                 //cout<<"asd"<<endl;//va a tirar como 13 asd xq son 7 datos  y 5 epacios antesd e q encuentre el salto de linea o lane XD
            }
            contador++;
       }
       else
       {
           cout<<"Archivo no encontrado"<<endl;
       }
       
       cout<<"Cantidad de nodos es de: "<<contador<<endl;
       return contador;

       
}

void leerArchivo2(int num)
{
       int i=0; int j=0;
       char letra;
       int numero;
       string cadena="";
       bool salto=false;
       int contador=0;//es un contador de datos
       ifstream archivo_entrada("archivo_entrada.txt"); 
       
       if(!archivo_entrada.fail())
       {
            while(!archivo_entrada.eof())
            {
                 archivo_entrada.get(letra);
                 
                 if(letra!='\n'&& letra!=' ')
                       cadena+=letra;
                 else
                 {   
                     numero=atoi(cadena.c_str());
                     //cout<<numero<<endl;
                     MA[j][i]=numero;
                     i++;
                     if(i==num)
                     {i=0;j++;}
                     
                     cadena="";
                 }
                                  
            }
            contador++;
       }
       else
       {
           cout<<"Archivo no encontrado"<<endl;
       }
       

       
}


void leerArchivo4(int num)
{
       int i=0; int j=0;
       char letra;
       int numero;
       string cadena="";
       bool salto=false;
       int contador=0;//es un contador de datos
       ifstream archivo_entrada("PCS_entrada.txt"); 
       
       if(!archivo_entrada.fail())
       {
            while(!archivo_entrada.eof())
            {
                 archivo_entrada.get(letra);
                 
                 if(letra!='\n'&& letra!=' ')
                       cadena+=letra;
                 else
                 {   
                     numero=atoi(cadena.c_str());
                     //cout<<numero<<endl;
                     MPC[j][i]=numero;
                     i++;
                     if(i==num)
                     {i=0;j++;}
                     
                     cadena="";
                 }
                                  
            }
            contador++;
       }
       else
       {
           cout<<"Archivo no encontrado"<<endl;
       }
       

       
}

void imprimirMatriz(int num)
{
     for(int i=0;i<num;i++)
     {
             for(int j=0;j<num;j++)
             {
                     cout<<MA[i][j]<<" ";
             }
             cout<<endl;
     }
 }
 
 void imprimirPC(int num, int num2)
{
     for(int i=0;i<num;i++)
     {
             for(int j=0;j<num2;j++)
             {
                     cout<<MPC[i][j]<<" ";
             }
             cout<<endl;
     }
 }



void GenerarMatriz()
{
           	 	int valor,dimension=7+rand()%(256-1),i,j,aux,MAT[dimension][dimension];

           	    for(i=0;i<dimension;i++)
                {
           	 	   for(j=0;j<dimension;j++)
                   {
           	 		   if(i>=j)
                       {
                           if(j==i)
                           {
                               MAT[i][i]=0;
                           }
           	 		       else
                           {
                               valor= 5+rand()%(201-1);
                   	 		   MAT[i][j]=valor;
                   	 		 
                                 
                                   aux=valor;
                   	 		   MAT[j][i]=aux;
                           }
                        }
                  }
           	    }



           	    cout<<"\n" <<  "Dimension"
           	 		   ": " << dimension<<endl;

           	    ofstream ficheroSalida;
           	    ficheroSalida.open ("archivo_entrada_2.txt");
           	    for(i=0; i<dimension; i++)
                {
                     for(j=0; j<dimension; j++)
           	              {
                               if(j!=0)
                                   ficheroSalida << " ";
                               ficheroSalida << MAT[i][j];
                          }
                     if(i!=dimension-1)
           	         ficheroSalida<< "\n";

                }

           	    ficheroSalida.close();

}

void GenerarMatrizPCS(int alto)
{
     
     
 }
