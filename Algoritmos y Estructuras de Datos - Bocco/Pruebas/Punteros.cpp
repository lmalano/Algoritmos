#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int x,y,z;
    int *p;
    
    x=21;
    y=10;
    z=x;
    p=&x;
    
    cout<<x<<endl;
    cout<<&x<<endl<<endl;
    
    cout<<y<<endl;
    cout<<&y<<endl<<endl;
    
    cout<<z<<endl;
    cout<<&z<<endl<<endl;
    
    *p=y;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<x;

    getch();
}
