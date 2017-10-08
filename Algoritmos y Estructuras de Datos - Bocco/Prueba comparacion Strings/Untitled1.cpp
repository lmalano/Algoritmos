#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;
int main()
{
    string nombre1="Juan Perez";
    string nombre2="Juan Perez";
    string nombre3="Juan Perezghjhjk";

    if (strcmp(nombre1.c_str(),"Juan Perez") == 0)
    {cout<<"la compraracion anda bien \n\n";}
    else{cout<<"algo falla 1\n";}
    
    if (strcmp(nombre1.c_str(),"AGAGAGA") < 0 || strcmp(nombre1.c_str(),"AGAGAGA") > 0)
    {cout<<"la compraracion anda bien \n\n";}
    else{cout<<"algo falla 2\n";}
    
    if (strcmp(nombre1.c_str(),nombre2.c_str()) == 0)
    {cout<<"la compraracion anda bien \n\n";}
    else{cout<<"algo falla 3\n";}
    
    if (strcmp(nombre1.c_str(),nombre3.c_str()) != 0)
    {cout<<"la compraracion anda bien \n\n";}
    else{cout<<"algo falla 4\n";}
    
    system("PAUSE");
    return 0;

}
