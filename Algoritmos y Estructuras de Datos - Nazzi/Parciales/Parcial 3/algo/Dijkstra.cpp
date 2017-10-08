#include <iostream>
using namespace std;
#include "ListaAdyacencia.cpp"
#define Size 20
#include <fstream>
#include "conjuntos.cpp"
class graph{
      private:
              Lista listaAdyacencia[Size];
              void Djikstra2(int inicial,int [Size],int [Size]);  
      
      
      public:
             graph(){};
             void cargar_desde_archivo(ifstream& in);
             void Djikstra(int inicial);
             void agregar (int source, int destino, int costo);
             void imprimirCaminos();
      
      
      
      
      };

void graph::imprimirCaminos(){
     cout<<"\n Lista Adyacencia \n";
     for (int i=0;i<Size;i++)
     listaAdyacencia[i].toPrint();
     
     }

void graph::agregar(int source,int destino,int costo){
     listaAdyacencia[source].add(source,destino,costo);
     }

void graph::cargar_desde_archivo(ifstream& in)
{int source,destino,costo;
     cout<<"Entrada: \n";
     while (in.eof()==false){
           in>>source>>destino>>costo; cout<<source<<" "<<destino<<" "<<costo<<" "<<endl;
           agregar(source,destino,costo);
           }
     }
     

void graph::Djikstra(int inicial)
{conjunto conocidos,desconocidos;
conocidos + inicial;
int d[Size],p[Size];

for (int i=0;i<Size;i++){
    if (i==inicial){}
    else{desconocidos + i;}
    d[i]=1000;//pone todos los caminos en infinito
    p[i]=inicial;
    }

Lista *caminoInicial=&listaAdyacencia[inicial];
while (!caminoInicial->esvacia()){
      d[caminoInicial->get_czo()->get_dest()]=caminoInicial->get_czo()->get_costo();
      //cout<<caminoInicial->get_czo()->get_dest()<<" "<<caminoInicial->get_czo()->get_costo()<<endl;
      caminoInicial=caminoInicial->resto();
      }
      
//conocidos.imprimir();
//desconocidos.imprimir();
//system("pause");
while (!desconocidos.esvacio())
{int min=10000;
int menor=0;
      for (int j=0;j<Size;j++)
      {if (d[j]<min)
          {if(desconocidos.pertenece(j))
          {menor=j;
          min=d[j];}}
          
      }//cout<<menor;
     // system("pause");
      
      conocidos + menor;
      desconocidos= desconocidos - conocidos;
      //desconocidos.imprimir();
      //conocidos.imprimir();
    //system("pause");
     Djikstra2(menor,d,p);
      
      }
      
cout<<"\nTabla\nvector  costo  anterior";     
for(int a=0;a<Size;a++)
{cout<<"\n"<<a<<"       "<<d[a]<<"          "<<p[a]<<endl;}

for(int b=0;b<Size;b++)
{if (b==inicial){}
else{int next=b;
if(d[b]>=1000){//cout<<"no hay camino desde "<<inicial<<" hacia: "<<b<<endl;
}
else{
cout<<"\n camino hacia: "<<b<<" desde: "<<inicial<<" con costo total: "<<d[b]<<"\n";
cout<<next<<" ";
while (next!=inicial){
      cout<<p[next]<<" ";
      next=p[next];
      
      }
      
     }   }
     }   
        
          
          
          }

void graph::Djikstra2(int inicial,int d[Size],int p[Size])
{int distancia=d[inicial];
//cout<<" "<<distancia<<endl;
     Lista *caminoInicial=&listaAdyacencia[inicial];
while (!caminoInicial->esvacia()){
      if(d[caminoInicial->get_czo()->get_dest()]>(caminoInicial->get_czo()->get_costo()+distancia)){
      d[caminoInicial->get_czo()->get_dest()]=caminoInicial->get_czo()->get_costo()+distancia;
      p[caminoInicial->get_czo()->get_dest()]=inicial;
      }
      //cout<<caminoInicial->get_czo()->get_dest()<<" "<<caminoInicial->get_czo()->get_costo()<<endl;
      caminoInicial=caminoInicial->resto();
      }
     
     }




main()
{ifstream in;
in.open("datos2.txt");
graph A;
A.cargar_desde_archivo(in);
A.imprimirCaminos();
cout<<"ingrese el origen "<<endl;
int n;
cin>>n;
A.Djikstra(n);
system("pause");
      
      
      
      }

