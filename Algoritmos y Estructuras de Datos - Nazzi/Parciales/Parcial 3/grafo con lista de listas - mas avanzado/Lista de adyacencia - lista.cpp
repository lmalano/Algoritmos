#include <iostream>
#include <fstream>
#include "Lista-lista-bien.cpp"

using namespace std;

class Lista_Adyacencia{
      private:
              Lista *lista_ady;        
      public:
             Lista_Adyacencia();
             Lista_Adyacencia(Lista* n){lista_ady=n;};
             //~Lista_Adyacencia();
             void cargar_lista(ifstream&);                      //carga la lista de adyacencia con datos extraidos de un archivo.
             Lista* get_lista_ady(){return lista_ady;};
             void imprimir_lista_adyacencia();
             Lista_Adyacencia* resto_lista_adyacencia();         
};

Lista_Adyacencia::Lista_Adyacencia(){
                 lista_ady=new Lista();
}

void Lista_Adyacencia::cargar_lista(ifstream& a){
     int b, c, d;
     while(!a.eof()){
                     a>>b>>c>>d;
                     lista_ady->set_lista_elementos(b,c,d);
     }
     a.close();
     this->imprimir_lista_adyacencia();
}

void Lista_Adyacencia::imprimir_lista_adyacencia(){
     lista_ady->impresionlista();
}

Lista_Adyacencia* Lista_Adyacencia::resto_lista_adyacencia(){
                                    Lista_Adyacencia *l=new Lista_Adyacencia(lista_ady->lista_resto());
                                    return (l);
}


