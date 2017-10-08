#include "estructura lista.cpp"

#include<iostream>
#include<fstream>
#include<cstring>
#include <cstdlib>
#include<cmath>
using namespace std;
int tamanioMatrix(ifstream &);
void agregarMatrix(ifstream &,int,matrix);
void dato(ifstream &);
void suma(matrix,matrix,matrix,int);
void guardarMatrix (matrix,char[50]);
void suma_aux(nodo* a,nodo* b,matrix C);
void suma_fila(nodo2* elementoA,nodo2*elementoB,matrix C);
void multiplicacion(matrix A,matrix B,matrix C);

void multi_aux1(nodo* fila,nodo* columna,matrix C,int nrofila,int nrocolumna);
void multi_aux2(nodo* fila,nodo* columna,matrix C,int nrofila,int nrocolumna);
void multi_fila(nodo2* filaA,nodo2*columnaB,int suma,int fila,int columna,matrix C);
int main(){
       
        
       ifstream entrada, entrada2,entrada20,entrada21;
       
      
       entrada.open("matriza.txt");
       
       if(entrada.fail()==1){
            cout<<"El archivo no pudo abrir."<<endl;
            system("pause");
            exit(1);
       }
             int tamanio=tamanioMatrix(entrada);
             //cout<<tamanio<<endl;
    matrix A(tamanio);
    entrada.close();        
    entrada2.open("matriza.txt");
    agregarMatrix(entrada2, tamanio,A);        
            //A.toprint();
             entrada20.open("matrizb.txt");
       if(entrada20.fail()==1){
            cout<<"El archivo no pudo abrir."<<endl;
            system("pause");
            exit(1);
       }
             int tamanio1=tamanioMatrix(entrada20);
            // cout<<tamanio1<<endl;
    matrix B(tamanio1);
    entrada20.close();        
    entrada21.open("matrizb.txt");       
             agregarMatrix(entrada21,tamanio1,B);
             //B.toprint();
      //guardarMatrix(B,"conespacios.txt");
     
     matrix C(tamanio);
      suma(A,B,C,tamanio);
      //C.toprint();       
             guardarMatrix(C,"matsuma.txt");
            matrix D(tamanio);
            multiplicacion(A,B,D);
        //    D.toprint();
            guardarMatrix(D,"matmult.txt");
            
            matrix* a=&A;
             matrix* b=&B;
             matrix* c=&C;
             matrix* d=&D;
             delete a,b,c,d;
             system("pause");
             return 0;
}

int tamanioMatrix(ifstream &a){
    int dato, n=0;
    while(a.eof()==0){
            a>> dato;
            n++;                     
    }
    n=sqrt(n);
    return n;
}

void agregarMatrix(ifstream &a, int n, matrix A){
   int fila=0,columna=0, dato;
   
   while(a.eof()==0){
          a>>dato;
          A.agregar(fila,columna,dato);
          columna++;
                 if(columna>(n-1))
                 {columna=0;
                 fila++;                   
                 }           
   }  
}

void suma(matrix A, matrix B,matrix C,int tamanio){
       //int fila=0,columna=0;
       
       nodo* a=A.getFilas().get_czo();
       nodo* b=B.getFilas().get_czo();
       suma_aux(a,b,C);
}
     
void suma_aux(nodo* a,nodo* b,matrix C){
     if (a->get_next()==NULL){}
     else{
          nodo2* elementoA=a->get_puntero();
          nodo2* elementoB=b->get_puntero();
          suma_fila(elementoA,elementoB,C);
          suma_aux(a->get_next(),b->get_next(),C);
     }
}       
       
void suma_fila(nodo2* elementoA,nodo2*elementoB,matrix C){
     if((elementoA->get_nextfila()==NULL)&&(elementoB->get_nextfila()==NULL)){}
     else{
          if((elementoA->get_nextfila()==NULL)||(elementoB->get_nextfila()==NULL)){
                              if(elementoA->get_nextfila()==NULL){
                                      C.agregar(elementoB->get_fila(),elementoB->get_col(),elementoB->get_dato());
                                      suma_fila(elementoA,elementoB->get_nextfila(),C);
                              }
                              else{ 
                                    C.agregar(elementoA->get_fila(),elementoA->get_col(),elementoA->get_dato());
                                    suma_fila(elementoA->get_nextfila(),elementoB,C);
                              }
          }                                
          else{
               if(elementoA->get_col()==elementoB->get_col()){
                              C.agregar(elementoA->get_fila(),elementoA->get_col(),elementoA->get_dato()+elementoB->get_dato());
                              suma_fila(elementoA->get_nextfila(),elementoB->get_nextfila(),C);
               }
               if(elementoA->get_col()>elementoB->get_col()){
                                          C.agregar(elementoB->get_fila(),elementoB->get_col(),elementoB->get_dato());
                                          suma_fila(elementoA,elementoB->get_nextfila(),C);
               }
               if (elementoA->get_col()<elementoB->get_col()){
                                          C.agregar(elementoA->get_fila(),elementoA->get_col(),elementoA->get_dato());
                                          suma_fila(elementoA->get_nextfila(),elementoB,C);
               }
          }
      }                                                                         
}

void guardarMatrix(matrix A,char nombre[50])
{    
     ofstream salida;
     salida.open(nombre);
     nodo* fila=A.getFilas().get_czo();
     nodo2* elemento=fila->get_puntero();

     for (int i=0;i<A.tamanio;i++){
         for(int j=0;j<A.tamanio;j++){
                 if(elemento->get_col()==j){
                                            salida<<elemento->get_dato()<<" ";
                                            elemento=elemento->get_nextfila();}
                 else salida<<0<<" ";
         }
         salida<<endl;
         fila=fila->get_next();
         elemento=fila->get_puntero();
     }
}


void multiplicacion(matrix A,matrix B,matrix C){
     multi_aux1(A.getFilas().get_czo(),B.getColumna().get_czo(),C,0,0);
}

void multi_aux1(nodo* fila,nodo* columna,matrix C,int nrofila,int nrocolumna){
              if(fila->get_next()==NULL)
              {}
              else{
                   multi_aux2(fila,columna,C,nrofila,nrocolumna);
                   multi_aux1(fila->get_next(),columna,C,nrofila+1,nrocolumna);
              }
}   

void multi_aux2(nodo* fila,nodo* columna,matrix C,int nrofila,int nrocolumna){
     if (columna->get_next()==NULL){}
     else{
          multi_fila(fila->get_puntero(),columna->get_puntero(),0,nrofila,nrocolumna,C);
          multi_aux2(fila,columna->get_next(),C,nrofila,nrocolumna+1);
     }
}
     
void multi_fila(nodo2* filaA,nodo2*columnaB,int suma,int fila,int columna,matrix C){
      //cout<<"fila "<<fila<<"columna "<<columna<<"suma "<<suma<<endl;
      if((filaA->get_nextfila()==NULL)||(columnaB->get_nextcol()==NULL)){
                                                                         C.agregar(fila,columna,suma);
                                                                         }
      else{
           if(filaA->get_col()==columnaB->get_fila()){                                                      
                                                      multi_fila(filaA->get_nextfila(),columnaB->get_nextcol(),suma+(filaA->get_dato()*columnaB->get_dato()),fila,columna,C);
                                                      }
           if(filaA->get_col()>columnaB->get_fila()){
                                                     multi_fila(filaA,columnaB->get_nextcol(),suma,fila,columna,C);
                                                     }
           if(filaA->get_col()<columnaB->get_fila()){
                                                     multi_fila(filaA->get_nextfila(),columnaB,suma,fila,columna,C);
                                                     }
           }                 
}
