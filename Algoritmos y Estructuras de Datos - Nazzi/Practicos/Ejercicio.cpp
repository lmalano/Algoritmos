/* Hacer una lista de caracteres, que indique 
la cantidad de palabras iguales que contiene*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

class nodo{
      private:
              nodo* next;
              string cadena;
      public:
             nodo(){next=NULL;};
             nodo(string a){set_cadena(a);next=NULL;};
             void set_cadena(string a){cadena=a;};
             string get_cadena(){return cadena;};
             void set_next(nodo* a){next=a;};
             nodo* get_next(){return next;};
             bool nodo_vacio(){return next==NULL;}
};

class Lista{
      private:
              nodo* czo;
              //int contador();
      public:
             Lista(){czo = new nodo();};
             Lista(nodo* a){czo=a;};
             nodo* get_czo(){return czo;};
             void add(string a);
             string toPrint(string p);
             string Head();
             Lista* Resto(void); 
             bool lista_vacia(){return czo->nodo_vacio();};
             //void comparo();
};

void Lista :: add(string a){
     nodo* nuevo = new nodo(a);
     nuevo->set_next(czo);
     czo=nuevo;
     cout<<"se agrego "<<nuevo->get_cadena()<<" a la lista."<<endl;     
}

Lista* Lista::Resto(){
      Lista* l= new Lista(czo->get_next());
      return (l);
}

string Lista :: Head(){
      if(this->lista_vacia()){}
      else return czo->get_cadena();
}

string Lista :: toPrint(string a){                                                                          /*No se imprimir esto*/
     if(this->lista_vacia()){cout<<"se vacio\n"; return a;}
     else{
          std::ostringstream stm;
          //cout<< "hola"<<endl;
          stm << this->Head() <<" "<< this->Resto()->toPrint(a);
          return stm.str();
     }
}

int main(){
      Lista* A=new Lista;
      
      A->add("Hola");
      A->add("chau");
      A->add("Hola");
      A->add("Hasta");
      A->add("Luego");
      A->add("chau");
      A->add("chau");
      
      A->toPrint("");
      
      system("pause");
      return 0;        
}
