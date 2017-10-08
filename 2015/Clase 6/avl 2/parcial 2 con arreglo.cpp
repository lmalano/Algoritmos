#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define tam1 1000
#define tam2 500

using namespace std;


struct tarbol{
       string palabra;
       int FB; 
       int hi, hd, contador;
       bool flag; 
};

tarbol arbol[tam1]; //definimos un arreglo del tipo arbol

class arbolAVL{
    int raiz;
    void Insert(string x, bool &aumento, int &i);
    void show(int aux, int n);
    void rotarLL(int &A);
    void rotarRR(int &A);
    void rotarLRalter(int &A);
    void rotarRLalter(int &A);
    void posiciones(int i);

    
public:
    arbolAVL(){raiz=0;};
    ~arbolAVL(){};
    void CreaArbolAVL(string x);
    void VerArbol(){ show(raiz,0);
	}
};

void arbolAVL::CreaArbolAVL(string x)
{    bool aumento;
     aumento=false;
     Insert(x,aumento, raiz);
 }
 
 void arbolAVL::posiciones(int i){    //asigna posiciones de hijos
 	            
				int k=0;
				     
                for (int j=i+1;j<tam1;j++)
                {
                	if((arbol[j].palabra=="")&&(arbol[j].flag)){   //condicion de que falg sea verdadera para entrar
                    arbol[i].hi=j;
					k=j;
					arbol[j].flag=false;  //cambia el flag de esa poscion para que no pueda entrar nunca mas en el for
					k=j; 
                	break;
					}

				}
                    for(int m=k+1;m<tam1;m++){
                    	if((arbol[m].palabra=="")&&(arbol[m].flag)){
                    		arbol[i].hd=m; 
                    		arbol[m].flag=false;
                    		break;
						}        	
					}

				                    
 }
 


void arbolAVL::Insert(string x, bool &aumento, int &i){
       if (arbol[i].palabra==""){

             arbol[i].palabra = x;
             arbol[i].flag=false;

                arbol[i].FB = 0;
                
                posiciones(i);
                aumento = true;
                arbol[i].contador=1;   //porque la palabra entra por primera vez al arbol
                
        }
		else{
                if (x<arbol[i].palabra){                       
                        Insert(x, aumento, arbol[i].hi);                     
                        if (aumento){
                                switch (arbol[i].FB){
                                        case -1:{
                                                arbol[i].FB = 0;
                                                aumento = false;
                                                break;
                                        }
                                        case 0:{
                                                arbol[i].FB = 1;
                                                aumento = true;
                                                break;
                                        }
                                        case 1:{
                                        	   int j=arbol[i].hi;
                                               if (arbol[j].FB == 1){ 
                                                        rotarLL(i);
                                                }else{
                                                        rotarLRalter(i);
                                                }
                                                aumento = false;
                                                break;
                                        }
                                }
                        }
                }
                else if(x>arbol[i].palabra){
                	
					
                        Insert(x, aumento, arbol[i].hd);                     
                        if (aumento){
                                switch (arbol[i].FB){
                                        case -1:{
                                        		int j=arbol[i].hd;
                                                if (arbol[j].FB == 1){ 
                                                        rotarRLalter(i);
                                                }else{
                                                        rotarRR(i);
                                                }
                                                aumento = false;                                                
                                                break;
                                        }
                                        case 0:{
                                                arbol[i].FB = -1;
                                                aumento = true;
                                                break;
                                        }
                                        case 1:{
                                                arbol[i].FB = 0;
                                                aumento = false;
                                                break;
                                        }
                                }
                        }
                }
                
                else {
                	
                	arbol[i].contador++;
    	
					}       
        }
}

void arbolAVL::rotarLL(int &i){ 
       // cout<<"\ LL>> "<<arbol[i].palabra<<endl<<endl;
        int j=arbol[i].hi;
        int aux = arbol[j].hd;      
        arbol[j].hd=i; 
        arbol[j].FB=0;  
        arbol[i].hi=aux; 
        arbol[i].FB=0; 
        i=j; 
        // VerArbol();
}
 
void arbolAVL::rotarRR(int &i){ 
       // cout<<"\RR "<<arbol[i].palabra<<endl<<endl; 
        int j=arbol[i].hd;
        int aux=arbol[j].hi; 
        arbol[j].hi=i; 
        arbol[j].FB=0; 
        arbol[i].hd=aux; 
        arbol[i].FB=0; 
        i=j; 
		// VerArbol();
}
 
void arbolAVL::rotarLRalter(int &A){ 
        //cout<<"\ Rotacion Doble RR+LL"<<endl;
        rotarRR(arbol[A].hi);
       // VerArbol();
        rotarLL(A);
}
 
void arbolAVL::rotarRLalter(int &A){ 
        //cout<<"\ Rotacion Doble LL+RR"<<endl;
        rotarLL(arbol[A].hd);
       // VerArbol();
        rotarRR(A);
}

void arbolAVL::show(int aux, int n)
{ int i;
   if(arbol[aux].palabra!=""){                      
       show(arbol[aux].hd, n+1); 
       for(i=1; i<=n; i++) cout<<"        ";
       cout<<"("<<arbol[aux].palabra<<" "<<arbol[aux].FB<<"  "<<arbol[aux].contador<<")"<<"\n";
       show(arbol[aux].hi,n+1);
   }
}



//-------------------------------------------------------

int main (int argc, char *argv[])
{   tarbol x;
   arbolAVL T;
   
   tarbol arbolarreglo [tam2]; //arreglo que va a terner las palabras ordenadas
   
   
   for(int i=0; i<tam1;i++)
{
       arbol[i].palabra="";
       arbol[i].flag=true;
       arbol[i].contador=0;
       
        }
	for(int i=0; i<tam2;i++){
		arbolarreglo[i].contador=0;
       	arbolarreglo[i].palabra="";
	}
 
   string nombre_archivo="textoparcial.txt";
   string palabra;
   
   ifstream archivo_entr;
   
   archivo_entr.open(nombre_archivo.c_str());
   
   if (archivo_entr.fail())
   {
   	cout<<"El archivo no se abrio"<<endl<<endl;
	exit(1);
   }
   
   for(int i=0;i<tam1;i++){
   	if(archivo_entr.good()){
 
   		archivo_entr>>palabra;
   		std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);	
   		T.CreaArbolAVL(palabra);
   	
   		
   	//	T.VerArbol();
   	//	 system("PAUSE");
   	//	cout<<arbol[i].palabra<<endl;
	   }
   }
   for(int i=0;i<150;i++){
   		arbolarreglo[i].contador=arbol[i].contador;	
   		arbolarreglo[i].palabra=arbol[i].palabra;
   	//	cout<<arbolarreglo[i].palabra<<" "<<arbolarreglo[i].contador<<endl; // imrpime arreglo sin que se ordene por cantidad de repeticiones.
   }
   	//------------------------------- 
   	cout<<"Vamos a imprimir el arbol AVL:"<<endl<<endl;
   T.VerArbol();
   
   int j,aux;      
tarbol temp;     
int m,c;
m=0; c=0; 
//ordenamiento del arreglo:
for(aux=1;aux<tam2;aux++){
   j=aux-1; temp=arbolarreglo[aux];            m++; c++;
   while(temp.contador>arbolarreglo[j].contador && j>=0){
      arbolarreglo[j+1]=arbolarreglo[j];            m++ ;c++;
      j--;
   }
   arbolarreglo[j+1]=temp;     m++ ;
 }
 	cout<<"Esto muestra el arreglo ordenado de acuerdo a la cantidad de repeticiones:"<<endl<<endl;
  for (int i=0;i<tam2;i++){
  		if(arbolarreglo[i].palabra!=""){
		  
	cout<<arbolarreglo[i].contador<<" "<< arbolarreglo[i].palabra<<endl;
  									}
  }

	cout<<endl<<endl<<endl;
   system("PAUSE");
   return 0;
}
