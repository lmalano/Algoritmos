#include <iostream>
#include <string>

using namespace std;


template <typename keyT, typename datoT>


class NodoHash
{
      private:
              keyT key;//q seria el datod el nodo o key, generalmente es un string
              NodoHash* siguiente;
              datoT dato;//se organiza asi... [KEY][VALOR] asis e organiza un hashmap
              
      public: 
              NodoHash(){siguiente=NULL;key=NULL;dato=NULL;};
              NodoHash(keyT k, datoT a);
              void setDato(datoT a){dato=a;};
              void setValue(datoT a){dato=a;};
              datoT getValue(){return dato;};
              
              keyT getKey(){return key;};
              void setNext(NodoHash* next){siguiente=next;};
              NodoHash<keyT,datoT>* getNext(){return siguiente;};
              
              void imprimir()
              {
                   //if(typeid(key)==typeid(int) || typeid(key)==typeid(double) || typeid(key)==typeid(string) || 
                    //  typeid(key)==typeid(float) || typeid(key)==typeid(long) || typeid(key)==typeid(char)  )
                      cout<<endl<<key<<"  :  "<<dato<<endl;
                   //else
                       //cout<<"asdasdas  "<<key.getNumeroDeNodo()<<endl;
                       //cout<<endl<<key.toString()<<"  :  "<<dato<<endl;
                   
              };
              /*void set_dato(tipolista a) {dato=a; };
              void set_next(Nodo* n) {next=n; };
              tipolista get_dato() {return dato; };
              Nodo *get_next() {return next; };
              bool es_vacio() {return next==NULL;}*/
              
};

template <typename keyT, typename datoT>
NodoHash<keyT, datoT>::NodoHash(keyT k, datoT a)
{
    key=k;
    dato=a;
    siguiente=NULL; 
}

/*
int main()
{
    cout<<"LCDSMDMAMSDASLM"<<endl<<endl;
    
    NodoHash<int,int> nodo(2,30);
    nodo.imprimir();
    
    system("PAUSE");
}*/
