#include<iostream>
using namespace std;
int main()
{
    int mcm(int,int);
    int mcm2(int,int,int,int);
    int a,b;
    cin>>a;
    cin>>b;
    cout<< mcm(a,b)<<"\n";
    system("pause");
    return 0;
}
int mcm2(int x,int y,int sx,int sy)
{
         if(sx==sy)
         {return sx;}
         else
         {
             if(sx<sy)
             {return mcm2(x,y,sx+x,sy);}
             else if(sx>sy)
             {return mcm2(x,y,sx,sy+y);}
         }
}
int mcm(int x,int y)
{
        return mcm2(x,y,x,y);
}
