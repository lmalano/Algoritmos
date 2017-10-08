#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
 main(){
 	
 int max=9;
 int temp;
 int a[9]={5,4,3,2,5,12,34,43,219};
  
 
 
 
 	for(int i=0;i<max+1;i++)
 		{int min=a[i]; 
		 for(int j=i+1;j<max;j++)
			 {if(a[j]<min)
				 {min=a[j];
				 temp=a[i];
				 a[i]=a[j];
				 a[j]=temp;}
			}
		}
		 	
		 for(int i=0;i<max;i++)
		 	{cout<<a[i]<<" ";}
			 
			 	
	system("PAUSE");

     return 0;	 	
		 }
		 
		 	 
 	
 

