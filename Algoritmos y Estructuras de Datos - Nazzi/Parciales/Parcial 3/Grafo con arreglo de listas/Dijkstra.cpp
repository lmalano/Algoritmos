#include <iostream>
#include <fstream>
#include <sstream>
//#include "ListaPruebaSolamente-arreglo.cpp"
#include "Lista Adyacencia-arreglo.cpp"
#include "Conjuntos.cpp"

using namespace std;

class Dijkstra{
               private:
                       conjunto Conocidos, Desconocidos;
                       int d[], verticesGrafo, start;
                       double p[];
               public:
                      Dijkstra(Lista_Adyacencia*);
                      //~Dijkstra();
                      void set_verticesGrafo(Lista_Adyacencia*);
                      void set_elemento_Conocidos(int a){Conocidos+a;};
                      void set_elemento_Desconocidos(int a){Desconocidos+a;};
                      void set_start(Lista_grafo*);                      
};

Dijkstra::Dijkstra(Lista_Adyacencia* l){
                     double a= numeric_limits<double>::infinity();
                     for(int i=0; i<verticesGrafo; i++){
                             p[i]=a;        
                     }
                     this->set_verticesGrafo(l);
                     this->set_start(l);           
}

void Dijkstra::set_verticesGrafo(Lista_Adyacencia *l){
     verticesGrafo=l->get_vertices();
}

void Dijkstra::set_start(Lista_Adyacencia *l){
     //definir comienzo.   
} 


//void Dijkstra::camino_mas_corto(Lista_Adyacencia)

int main(){
    ifstream archivo_entrada;
    string nombre;
    
    cout<<"Ingrese nombre de archivo\n";
    cin>>nombre;
    
    archivo_entrada.open(nombre.c_str());
    if(archivo_entrada.fail()){
                  cout<<"El archivo no se encuentra\n";
                  system("pause");
                  exit(1);
    }
    Lista_Adyacencia *l=new Lista_Adyacencia(archivo_entrada);
    
    
    system("pause");
    return 0;
}
