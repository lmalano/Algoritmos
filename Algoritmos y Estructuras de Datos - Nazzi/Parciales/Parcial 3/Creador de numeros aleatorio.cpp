#include<iostream>
#include<ctime>
#include <fstream>
using namespace std;

int main(){
    ofstream a;
    int n[1000], i;
    
    srand(time(NULL)); 
    
    for(i=0; i<1000; i++){
             
             n[i]=rand()%1000; 
                    
    }
    
    a.open("numeros1000.txt");
    
    for(i=0;i<1000;i++){
             a<<n[i]<<", ";
    }
    
    return 0;
}
