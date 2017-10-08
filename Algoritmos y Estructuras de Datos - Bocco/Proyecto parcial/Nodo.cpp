#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;


#include "Nodo.h"

        Nodo::Nodo() {next=NULL; nodo=NULL;}
        Nodo::Nodo(Nodo *a) {next=a; nodo= NULL;}
        void Nodo::set_nodo(Nodoralo* a) {nodo=a;}
        void Nodo::set_next(Nodo* n) {next=n;}
        Nodoralo* Nodo::get_nodo() {return nodo;}
        Nodo* Nodo::get_next() {return next;}
