#ifndef B_cpp
#define B_cpp


#include <iostream>
#include "C.cpp"




using namespace std;



class B : public C
{
    private:
            C* c;
            int h;
            
            
    public:
           
           
            B(int b,int asd,  int hh):C(b,asd)//aca vos pasas los parametros para C
           {
           
                //C(b);
                h=hh;
            }
            
            void llamada()
            {
                cout<<"Se ejecuto llamada de b"<<endl;
            }
            
};


#endif
