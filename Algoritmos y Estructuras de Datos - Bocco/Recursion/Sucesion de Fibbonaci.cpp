#include<iostream>
using namespace std;
int main()
{
    int fib(int);
    int fib2(int,int,int,int);
    for(int i=1;i<21;i++)
    {
        cout<< fib(i)<< " ";
    }
    system("PAUSE");
    return 0;
}
int fib2(int x, int c, int p, int s)
{
    if(x==c){
    return p+s;}
    else {
    return fib2(x,c+1,p+s,p);}
}
int fib(int x)
{
    if(x<=2){
    return 1;}
    else {
    return fib2(x,3,1,1);}
    
}
