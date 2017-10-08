#ifndef A_cpp
#define A_cpp


#include <iostream>
#include "C.cpp"




using namespace std;



class A : public C
{
    private:
            C* c;
            int a;
            
            
    public:
           
           
            A(int b, int asd):C(b,asd)
           {
                a=2;
            }
            
};


#endif
