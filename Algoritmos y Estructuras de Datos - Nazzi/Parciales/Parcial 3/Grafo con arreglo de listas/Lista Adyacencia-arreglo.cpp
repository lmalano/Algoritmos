#include <iostream>
#include <fstream>
#include "ListaPruebaSolamente-arreglo.cpp"

using namespace std;

class Lista_Adyacencia{
      private:
              int vertices;
              Lista *lista_ady[];
      public:
             Lista_Adyacencia(ifstream&);
             ~Lista_Adyacencia();
             void set_vertices(ifstream&);
             void carga_archivo(ifstream&);
             int get_vertices(){return vertices;};
             void imprimir();
};

Lista_Adyacencia::Lista_Adyacencia(ifstream& a){
                           set_vertices(a);cout<<this->get_vertices()<<"\n";
                           for(int i=0; i<vertices; i++){
                                   lista_ady[i]=new Lista();       //creo tantas listas como vertices tengo. Cada lista, crea un nodo que apunta a null, por defecto.        
                           } 
                           carga_archivo(a);
                           imprimir();
}

Lista_Adyacencia::~Lista_Adyacencia(){
                           for(int i=0; i<vertices; i++){
                                   lista_ady[i]->~Lista();        
                           }                                      
} 

void Lista_Adyacencia::set_vertices(ifstream& a){
     a>>vertices;          
}

void Lista_Adyacencia::carga_archivo(ifstream& a){
    while(a.eof()!=1){
                      int b, c, d;
                      a>>b>>c>>d;
                      lista_ady[b]->add(b, c, d);
                      cout<< "b= "<<b<<" c= "<<c<<" d= "<<d<<endl;       
     }
     a.close();
}

void Lista_Adyacencia::imprimir(){
     for(int i=0; i<vertices; i++){
             lista_ady[i]->impresion();
             cout<<endl;     
     }     
}
