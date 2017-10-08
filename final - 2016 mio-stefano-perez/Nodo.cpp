#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string> 
#include <fstream>
#include <cmath>
#ifndef Nodo_cpp
#define Nodo_cpp

using namespace std;

template <typename tipoT>

class Nodo{
    protected: 
        tipoT dato;
        Nodo* next;
    public:
        Nodo() {next=NULL;};
        Nodo(tipoT a) {dato=a; next=NULL;};
        void set_dato(tipoT a) {dato=a; };
        void set_next(Nodo* n) {next=n; };
        tipoT getDato() {return dato; };
        Nodo *getNext() {return next; };
        bool es_vacio() {return next==NULL;};
};


//testeo de nodos
/*
int main()
{
    
    cout<<"ARRANCO"<<endl;
    system("PAUSE");
}
*/
#endif
