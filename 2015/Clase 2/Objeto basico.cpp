#include <iostream>
using namespace std;

class point{
	
	int xval,yval;
	public:
		void setpt(int,int);
		void offsetpt(int,int);
	
	
};

int main()
{
  
  //point *p=new point();
  //p->offsetpt(10,20);    FORMA 1 con puntero
 
  point p;
  p.offsetpt(10,20);//forma 2

//x referencia
point q;
p.offsetpt(30,40);//forma 3


}

void point::setpt(int x,int y)
{
	xval=x;
	yval=y;
}

void point::offsetpt(int x,int y)
{
		xval+=x;
	yval+=y;
	
	cout<<x;
}
