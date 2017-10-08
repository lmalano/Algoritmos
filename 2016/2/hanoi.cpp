#include <iostream>

using namespace std;

void hanoi(char a, char c, char b, int n)
{if(n>0){
hanoi(a,b,c,n-1);
cout<<"Mover "<< n << " desde " << a << " hasta " << c << endl;
hanoi(b, c, a, n-1);
}
}

int main(){
	
	hanoi('a','b','c', 6);
	
	system("pause");
	
	return 0;
}
