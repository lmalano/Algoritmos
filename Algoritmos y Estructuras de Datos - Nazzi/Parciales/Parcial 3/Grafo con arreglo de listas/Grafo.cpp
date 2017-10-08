#include <string>
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

class Grafo{
      private:
              bool dirigido;
              int num_v;
      public:
             //Grafo(int, bool);
            // ~Grafo ();
             int get_num_v (){return num_v;};
             bool es_dirigido(){dirigido==true;};
             void carga_archivo(ifstream&);
             void cargar_grafo(ifstream&, bool, int&);
};



void Grafo::carga_archivo(ifstream& a){
     if(a.fail()==1){
                     cout<<"El archivo no pudo abrir\n";
                     system("pause");
                     exit(1);                
     }     
     cout<<"El archivo abrio con exito\n";
}


int main(){
     ifstream archivo;
     string nombre_archivo;
     Grafo g;
     cout<<"Ingrese nombre de archivo\n";
     cin>>nombre_archivo;
     archivo.open(nombre_archivo.c_str());
     g.carga_archivo(archivo);
        
     system("pause");
     return 0;
}
