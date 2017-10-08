#include <iostream>
#include <fstream>
#include <limits>
#include "Lista de adyacencia - lista.cpp"
#include "Conjuntos.cpp"
#define vertices 5
using namespace std;

/*
      Hecho ------- Comprobar si el dato inicio existe. Modificar la clase Lista_Adyacencia.
                    Hacer el metodo set_vertices. Es necesario para los vectores y conjuntos
                    Hacer metodo obtener_caminos
                    Completar todos los destructores.
                    Hacer el metodo imprimir caminos.
*/

class Dijkstra:public Lista_Adyacencia, public conjunto{
      private:
              conjunto Conocidos, Desconocidos;
              int start, predecesor[vertices];
              double peso[vertices];
      public:
             Dijkstra ();
             //~Dijkstra ();
             //void set_cant_vertices(Lista_Adyacencia* l){cant_vertices=l->get_vertices();};
             void obtener_caminos(Lista_Adyacencia*, int, int);
             void set_start(Lista_Adyacencia*, int);
             int get_start(){return start;};
             void imprimir_peso();
             void definir_peso(Lista_Elementos*);
             double menor_peso();
             void set_conocidos(int i){Conocidos+i;};
             void set_desconocidos(Lista_Adyacencia*);    
};

Dijkstra::Dijkstra(){
                     int i=0;
                     start=0;
                     for(i=0; i<vertices; i++){
                              predecesor[i]=0;
                              peso[i]=numeric_limits<double>::infinity();     
                     }   
                     imprimir_peso();               
}

void Dijkstra::set_start(Lista_Adyacencia* l, int i){
     if(!l->get_lista_ady()->is_dato(i)){
          cout<<"El dato no existe o no puede establecerse como vertice de inicio\n";
          system("pause");
          exit(1);
     }
     else{
          cout<<"El dato existe\n";  
          start=i; 
          Conocidos+i;         
     }
     cout<<"Start vale "<<get_start()<<endl;  
}

void Dijkstra::obtener_caminos(Lista_Adyacencia* l, int i, int entrada){
     if(entrada==0){ 
                    this->set_start(l, i);
                    this->set_desconocidos(l);
                    cout<<"El conjunto Desconocidos esta integrado por \n";
                    Desconocidos.imprimir();
                    
     }
     
     if(l->get_lista_ady()->get_czo_lista()->get_origen()==i){
              //Conocidos+i;
              cout<<"El conjunto de conocidos es \n";
              Conocidos.imprimir();cout<<endl<<endl;
              
              this->definir_peso(l->get_lista_ady()->get_czo_lista()->get_nextderecha());                                                    
              imprimir_peso();
              cout<<"imprimi peso"<<endl;
              l->resto_lista_adyacencia()->imprimir_lista_adyacencia();
     }
     else obtener_caminos(l->resto_lista_adyacencia(), i, entrada+1);
}

void Dijkstra::definir_peso(Lista_Elementos* l){
     if(l->get_czo()->get_next()!=NULL){
                      
                      int a=l->get_czo()->get_destino();
                      double b=l->get_czo()->get_peso();
                      
                      peso[a]=b ;
                      cout<<"La posicion es "<<l->get_czo()->get_destino()<<endl;
                      this->definir_peso(l->resto());
     }   
     if(this->menor_peso()==numeric_limits<double>::infinity()) cout<<"Imposible llegar\n";      //busco la distancia mas chica de Conocidos a Desconocidos.
     else  cout<<"La minima distancia es "<<this->menor_peso()<<endl;                                                                                                      
              
}

double Dijkstra::menor_peso(){
    double menor;
    for(int i=0; i<vertices; i++){
                           if(peso[i]<menor || i==0) menor=peso[i];
    }
    //if(menor==numeric_limits<double>::infinity()) 
    return menor;
}


void Dijkstra::imprimir_peso(){
     for(int i=0; i<vertices; i++){
             cout<<peso[i]<<endl;
     }     
}

void Dijkstra:: set_desconocidos(Lista_Adyacencia* l){
     if(l->get_lista_ady()->get_czo_lista()==NULL){}else{
     if(Conocidos.pertenece(l->get_lista_ady()->get_czo_lista()->get_origen()))
                   this->set_desconocidos(l->resto_lista_adyacencia());
     else{
          Desconocidos+l->get_lista_ady()->get_czo_lista()->get_origen();
          if(Desconocidos.pertenece(l->get_lista_ady()->get_czo_lista()->get_nextderecha()->get_czo()->get_destino())){
                                      
          } 
          this->set_desconocidos(l->resto_lista_adyacencia());    
     }
     }
}

























int main(){
    ifstream a;
    int b, c, d, inic;
    Lista_Adyacencia *l=new Lista_Adyacencia();
    
    a.open("datos2.txt");
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
