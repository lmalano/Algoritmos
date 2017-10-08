#ifndef C_cpp
#define C_cpp


#include <iostream>




using namespace std;



class C
{
    private:
            
            int b;
            int asd;
            
            
    public:
           
           
            C(int b,int asd)
           {
                this->b=b;
                this->asd=asd;
            }
            
            virtual void llamada()
            {
                cout<<"Se ejecuto llamada de C"<<endl;
            }
            
};


#endif
