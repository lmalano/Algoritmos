#include <iostream>

#include "C.cpp"
#include "A.cpp"
#include "B.cpp"

using namespace std;

int main()

{
    cout<<endl;
    C* noditoB=new B(1,2,3);
    C* noditoA=new A(5,7);
    C* noditoC=new C(8,9);
    
    noditoA->llamada();
    noditoB->llamada();
    noditoC->llamada();
    
    
    cout<<endl;
    system("PAUSE");   
}
