#include <cstdlib>
#include <iostream>
#define INFI  9000
#define MAXNODOS  5
#define MIEMBRO   1
#define NO_MIEMBRO 0

int *shortpath(int peso[][MAXNODOS],int s, int t, int precede[]);

using namespace std;

int main(int argc, char *argv[])
{   int peso[MAXNODOS][MAXNODOS]={INFI, INFI,    4,   7, INFI,
                                  INFI, INFI,    1, INFI, INFI,
                                  INFI, INFI, INFI,    2,   11,
                                  INFI, INFI, INFI, INFI,    2,
                                  INFI, INFI, INFI,    1, INFI      
                                 };
    int *pdist, i, j, precede[MAXNODOS],s,t;
    
    for(i=0;i<MAXNODOS;i++){
           cout<<"\n";                 
           for(j=0;j<MAXNODOS;j++){
                  printf(" %5i",peso[i][j]);                 
           }                 
    }
    s=0;  // vertice de inicio
    t=4;  // vertice final
    pdist=shortpath(peso,s,t,precede);
    cout<<"\n\n distancia minima del nodo "<<s
        <<" al nodo "<<t<<" es= "<<pdist[t];
    cout<<"\n\n CAMINO= ";
    cout<<"   "<<t;
    for(i=t;i>0;i--){
                     if(precede[i]==s) break;
                     if(precede[i]!=-1)
                        cout<<"   "<<precede[i];
                     }
    cout<<"   "<<s;                     
    cout<<endl<<endl<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
// peso[i][j] peso del arco de i a j
// distancia[i] costo del camino mínimo conocido hasta el 
//              momento de s a i
//              inicialmente distancia[s]=0 y distancia[i]=INFI
// perm[i] conjunto de nodos cuya distancia minima a s es conocida
//         y permanente, inicialmente perm[] solo contiene a s
//         perm[i]=1 si i pertenece, =0 si i no pertenece
// precede[i] contiene el nodo que precede a i en el camino 
//            minimo encontrado hasta el momento

int *shortpath(int peso[][MAXNODOS],int s, int t, int precede[])
{
 static int distancia[MAXNODOS];
 int perm[MAXNODOS];
 int actual, i, k, dc, b;
 int menordist, nuevadist;
// inicialización
 for(i=0;i<MAXNODOS;i++){
                         perm[i]=NO_MIEMBRO;
                         distancia[i]=INFI;
                         precede[i]= -1;
 }//fin for
 perm[s]=MIEMBRO; distancia[s]=0; actual=s; b=1;
 while((actual!=t)&&(b==1)){
                  b=0;
                  menordist=INFI;
                  dc=distancia[actual];
                  printf("\n\n  actual=%3i  dc=%3i ",actual,dc);
                  for(i=0;i<MAXNODOS;i++){
                          cout<<"\n  i= "<<i;                
                          if(perm[i]==NO_MIEMBRO){
                                 nuevadist=dc+peso[actual][i];
                                 printf("\n nuevadist=%3i distancia[%2i]=%3i ",nuevadist,i,distancia[i]);
                                 if(nuevadist<distancia[i]){
                                        distancia[i]=nuevadist;//por actual es menor que la anterior
                                        precede[i]=actual; b=1;
                                 }//fin if
                                 printf("\n menordist=%3i distancia[%2i]=%3i ",menordist,i,distancia[i]);
                                 if(distancia[i]<menordist){
                                        menordist=distancia[i];//guardo el nodo de la menor distancia
                                        k=i;  b=1;
                                 }//fin if
                          }//fin if
                  }//fin for
                  actual=k; //printf("\n k= %i",k);
                  perm[actual]=MIEMBRO;
                  printf("\n\n     distan  perm  precede");
                  for(i=0;i<MAXNODOS;i++){
                           printf("\n[%2i] %5i %5i %5i     ",i,distancia[i], perm[i],precede[i]);
                   } system("PAUSE");
 }//fin while
 return distancia;
}// fin shortpath     
