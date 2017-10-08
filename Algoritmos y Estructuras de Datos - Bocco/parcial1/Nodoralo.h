#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

#ifndef Included_Nodoralo_H
#define Included_Nodoralo_H


class Nodoralo
{
    private: 
        int dato;
        int fil;
        int col;
        Nodoralo *der;
        Nodoralo *inf;
        
    public:
        Nodoralo();
        Nodoralo(int a, int i, int j);
        void set_dato(int a);
        void set_der(Nodoralo *n);
        void set_inf(Nodoralo *n);
        void set_col(int);
        void set_fil(int);
		int get_dato();
        Nodoralo* get_der();
        Nodoralo* get_inf();
        int get_fil();
        int get_col();
};

#endif
