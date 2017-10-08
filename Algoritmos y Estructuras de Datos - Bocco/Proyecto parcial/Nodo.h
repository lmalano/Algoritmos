#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

#include "Nodoralo.h"

#ifndef Included_Nodo_H
#define Included_Nodo_H


class Nodo{
    private: 
        Nodo *next;
        Nodoralo *nodo;
    public:
        Nodo();
        Nodo(Nodo *a);
        void set_nodo(Nodoralo *a);
        void set_next(Nodo *n);
        Nodoralo *get_nodo();
        Nodo *get_next();
        
        //bool es_vacio() {return next==NULL;}
};

#endif
