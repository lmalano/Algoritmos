#include <iostream>
int posicion (char[], int, int, int, int, int);
using namespace std;
main()
{
    char oracion[]=("Trabajo de algoritmos y estructuras de datos");
    cout<< "La posicion del primer caracter de la palabra mas larga es: "<<posicion(oracion, 0, 0, 0, 0, 0)<<endl<<endl;
    
    system("pause");
    return 0;    
}

int posicion(char c[], int posInic, int posActual, int posMax, int largoPal, int largoMax){
    
    if(c[posActual]==' ' || c[posActual]==NULL){
                             if(c[posActual]==NULL){cout<<"\nentre\n"<<endl;
                                         if(largoPal>largoMax)  return posInic;
                                         return posMax;}
                             else{        if(largoPal>largoMax){cout<<"2"<<"\nposInic: "<<posInic<< "\nposActual: "<< posActual<<"\nposMax: "<<posMax<< "\nlargoPal: "<< largoPal<<"\nlargoMax: "<<largoMax<<endl<<endl; 
                                                                return posicion(c, posActual+1, posActual+1,posInic, 0, largoPal); 
                                          }
                                          else{
                                          cout<<"3"<<"\nposInic: "<<posInic<< "\nposActual: "<< posActual<<"\nposMax: "<<posMax<< "\nlargoPal: "<< largoPal<<"\nlargoMax: "<<largoMax<<endl<<endl;
                                          return posicion(c, posActual+1, posActual+1, posMax, 0, largoMax); 
                                          }
                             }
                             }
    else{
    cout<<"1"<<"\nposInic: "<<posInic<< "\nposActual: "<< posActual<<"\nposMax: "<<posMax<< "\nlargoPal: "<< largoPal<<"\nlargoMax: "<<largoMax<<endl<<endl;
    return posicion(c, posInic, posActual+1, posMax, largoPal+1, largoMax);    }                 
}
