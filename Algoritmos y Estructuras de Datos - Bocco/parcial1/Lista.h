#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;


#include "Nodo.h"

#ifndef Included_Lista_H
#define Included_Lista_H

class Lista{
    private: 
			Nodo *czo;
			int cant;   
    public:
            Lista ();
            Lista (Nodo*);
            Nodo* cabeza(void);
            Lista *resto(void);
            void add(int);
        
            
};
#endif
