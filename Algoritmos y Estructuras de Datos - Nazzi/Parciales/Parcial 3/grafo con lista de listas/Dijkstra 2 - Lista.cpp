#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>
#include "Lista de adyacencia 2 - lista.cpp"
#include "Conjuntos.cpp"
#define tam 10
using namespace std;

/*
      Hecho ------- Comprobar si el dato inicio existe. Modificar la clase Lista_Adyacencia.
                    Hacer el metodo set_vertices. Es necesario para los vectores y conjuntos
                    Hacer metodo obtener_caminos
                    Completar todos los destructores.
                    Hacer el metodo imprimir caminos.
*/

class Dijkstra:public Lista_de_Adyacencia, public conjunto{
      private:
              conjunto Conocidos, Desconocidos, Diferencia;
              int start, vertices, predecesor[tam];
              double peso[tam];
              
      public:
             Dijkstra ();
             //~Dijkstra ();
             void obtener_caminos(Lista_de_Adyacencia*, int, int);
             void set_start(Lista_de_Adyacencia*, int);
             void imprimir_predecesor_peso();
             int pos_menor_peso();
             void set_conocidos(int i){Conocidos+i;};
             void set_desconocidos(Lista_de_Adyacencia*); 
             void desconocidos_lista_elementos(Lista_Elementos *);
             void diferencia (){Diferencia=Desconocidos - Conocidos;}; 
             void set_predecesor_peso(Lista_de_Adyacencia*, int, int);  
};

Dijkstra::Dijkstra(){
                     int i=0;
                     start=0;
                     for(i=0; i<tam; i++){
                              predecesor[i]=0;
                              peso[i]=numeric_limits<double>::infinity();     
                     }   
                     //imprimir_peso();               
}

void Dijkstra::obtener_caminos(Lista_de_Adyacencia* l, int i, int entrada){
     if(entrada==0){ 
                    this->set_start(l, i);
                    this->set_desconocidos(l);                                //inicializo el conjunto Desconocidos.
                    cout<<"El conjunto Desconocidos esta integrado por \n";
                    Desconocidos.imprimir();
                    this->diferencia();
                    this->set_predecesor_peso(l, i, 0);               
                    cout<<"Peso = \n";imprimir_predecesor_peso();
     }
     else{
          this->set_predecesor_peso(l, i, entrada);
          Conocidos+i;
          cout<<"El conjunto de conocidos es \n";
          Conocidos.imprimir();cout<<endl<<endl;
          this->diferencia();
          cout<<"La diferencia es\n";
          Diferencia.imprimir();                                                   
          imprimir_predecesor_peso();
     }
     
     i=this->pos_menor_peso();cout<<"menor peso "<<i<<endl;                        //cambiar esto
     if(peso[i]==numeric_limits<double>::infinity()){                                                                         
                cout<<"La busqueda de caminos ha terminado"<<endl;
                system("pause");
                exit(1);
     }
     
     cout<<"cardinalidad "<<Diferencia.cardinalidad()<<endl;
     if(Diferencia.cardinalidad()!=0) this->obtener_caminos(l, i, entrada+1);
     
}

void Dijkstra::set_start(Lista_de_Adyacencia* l, int i){
     if(!l->is_dato(i)){
          cout<<"El dato no existe o no puede establecerse como vertice de inicio\n";
          system("pause");
          exit(1);
     }
     else{
          cout<<"El dato existe\n";  
          start=i; 
          Conocidos+i;         
     }
}

int Dijkstra::pos_menor_peso(){
    double menor;
    int pos_menor;
    int flag=0;
    //menor=numeric_limits<double>::infinity();
    //Conocidos.imprimir();
    for(int i=0; i<tam; i++){
            if(flag==0 && !Conocidos.pertenece(i)){
                     menor=peso[i];
                     pos_menor=i;
                     flag=1;
            }
            else if(peso[i]<menor && !Conocidos.pertenece(i)){                 
                                         menor=peso[i];
                                         pos_menor=i;
                 }  

    } 
    return pos_menor;
}

void Dijkstra::imprimir_predecesor_peso(){
     for(int i=0; i<tam; i++){
             cout<<setw(2)<<i<<setw(8)<<peso[i]<<"   "<<predecesor[i]<<endl;
     }     
}

void Dijkstra:: set_desconocidos(Lista_de_Adyacencia* l){
     if(l->get_czo_lista()->get_nextabajo()!=NULL){
                                  if(Conocidos.pertenece(l->get_czo_lista()->get_origen())){
                                        this->desconocidos_lista_elementos(l->get_czo_lista()->get_nextderecha());
                                        this->set_desconocidos(l->lista_resto());                              
                                  }
                                  else{
                                       Desconocidos+l->get_czo_lista()->get_origen();
                                       this->desconocidos_lista_elementos(l->get_czo_lista()->get_nextderecha());                        
                                       this->set_desconocidos(l->lista_resto());    
                                  }
     }
}

void Dijkstra::desconocidos_lista_elementos(Lista_Elementos* l){
      if(l->get_czo()->get_next()!=NULL){
                             if(Conocidos.pertenece(l->get_czo()->get_destino())){
                                         this->desconocidos_lista_elementos(l->resto());
                             }
                             else{
                                  Desconocidos+l->get_czo()->get_destino();
                                  this->desconocidos_lista_elementos(l->resto());
                             }
      }    
}


void Dijkstra::set_predecesor_peso(Lista_de_Adyacencia* l, int posicion, int entrada){
          if(entrada==0){
                         Lista_de_Adyacencia *s=new Lista_de_Adyacencia();              //creo lista de adyacencia auxiliar.
                         s=l;
                         while(s->get_czo_lista()->get_origen()!=posicion){                    //busco el nodo de la lista de adyacencia cuyo origen sea igual a p.
                                       s=s->lista_resto();                                                                      
                         }
                         Lista_Elementos *n=new Lista_Elementos();                       // creo Lista de elementos auxiliar.
                         n=s->get_czo_lista()->get_nextderecha();
                         while(n->get_czo()->get_next()!=NULL){
                                         int a=n->get_czo()->get_destino();
                                         double b=n->get_czo()->get_peso();
                      
                                         peso[a]=b ;
                                         n=n->resto();
                         }
                         for(int i=0; i<tam; i++){
                                 predecesor[i]=posicion;        
                         }              
          }
          else{
               Lista_de_Adyacencia *s=new Lista_de_Adyacencia();
               s=l;
               l->impresionlista();
               if(s->is_dato(posicion)){
               while(s->get_czo_lista()->get_origen()!=posicion){
                          s=s->lista_resto();                                                                      
               }
               Lista_Elementos *n=new Lista_Elementos();
               n=s->get_czo_lista()->get_nextderecha();
               while(n->get_czo()->get_next()!=NULL){
                               int a= n->get_czo()->get_destino();                     
                               int b= n->get_czo()->get_peso();                     
                               if(b+peso[posicion]<peso[a]){
                                                     peso[a]=b+peso[posicion];
                                                     predecesor[a]=posicion;                                                                                              
                               }
               n=n->resto();                                            
               }
               }            
          }
}





















int main(){
    ifstream a;
    int b, c, d, inic;
    Lista_de_Adyacencia *l=new Lista_de_Adyacencia();
    
    a.open("datos3.txt");
    if(a.fail()==1){
                 cout<<"El archivo no se encontro.";
                 system("pause");
                 exit(1);             
    }
    
    l->cargar_lista(a);
    
    cout<<"Establezca punto de inicio, para conocer los caminos mas cortos posibles.\n";
    cin>>inic;
    
    Dijkstra recorridos;
    recorridos.obtener_caminos(l, inic, 0);
   
    system("pause");
    return 0;
}
