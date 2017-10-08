using namespace std;
#include <iostream>
#include <iomanip>
class nodo2{
      private:
              nodo2* next_fila;
              nodo2* next_col;
              int dato;
              int fila;
              int col;
      public:
             nodo2(){set_fila(-1);set_col(-1);set_dato(-1);set_nextfila(NULL);set_nextcol(NULL);}
             nodo2(int dato,int fila,int col){set_fila(fila);set_col(col);set_dato(dato);set_nextfila(NULL);set_nextcol(NULL);}
             int get_dato(){return dato;}
             void set_dato(int a){dato=a;}
             int get_fila(){return fila;}
             void set_fila(int a){fila=a;}
             int get_col(){return col;}
             void set_col(int a){col=a;}
             void set_nextfila(nodo2* a){next_fila=a;}
             nodo2* get_nextfila(){return next_fila;}
             void set_nextcol(nodo2* a){next_col=a;}
             nodo2* get_nextcol(){return next_col;}
};

class nodo{
           private:
                   nodo2* puntero;
                   nodo* next;
         
           public:
                  nodo(){next=NULL; 
                  puntero=NULL;}
                  nodo* get_next(){return next;}
                  void set_next(nodo* a){next=a;}
                  nodo2* get_puntero(){return puntero;}
                  void set_puntero(nodo2* a){puntero=a;}
};
      
class lista:public nodo{
      private:
              nodo* czo;
         
      public:
             lista(){czo=new nodo();}
       
             void add(){
                  nodo* p=new nodo();
                  nodo2* final =new nodo2();
                  p->set_next(czo);
                  p->set_puntero(final);
                  czo=p;
             }
             nodo* get_czo(){return czo;}
};

class matrix:public nodo2{
                    private:
                            lista filas;
                            lista columnas;
                            void agregar_fila(nodo2*,nodo2*,nodo2*);
                            void agregar_columna(nodo2*,nodo2*,nodo2*);
                            nodo* avanzarAposicion(int,nodo*);
                    public:
                           int tamanio;
                           matrix(int size){
                                      tamanio=size;
                                      for (int i=0;i<size;i++){
                                          filas.add();
                                          columnas.add();}
                           }
                           void agregar(int fila,int columna,int dato){
                            if(dato==0){
                                        }
                            else{
                                nodo2* nuevo=new nodo2(dato,fila,columna);
                                nodo* posicion_fila;
                                nodo* posicion_columna;
                                nodo2* primer_elemento_fila;
                                nodo2* primer_elemento_columna;
                    
                                posicion_columna=avanzarAposicion(columna,columnas.get_czo());
                                primer_elemento_columna=posicion_columna->get_puntero();
                                
                                if(primer_elemento_columna->get_nextcol()==NULL){
                                         posicion_columna->set_puntero(nuevo);
                                         nuevo->set_nextcol(primer_elemento_columna);}
                                else{agregar_columna(primer_elemento_columna,nuevo,NULL);}
                                
                                posicion_fila=avanzarAposicion(fila,filas.get_czo());
                                primer_elemento_fila=posicion_fila->get_puntero();
                       
                                if(primer_elemento_fila->get_nextfila()==NULL){
                                         posicion_fila->set_puntero(nuevo);
                                         nuevo->set_nextfila(primer_elemento_fila); }
                                else{agregar_fila(primer_elemento_fila,nuevo,NULL);}
                           }                 
                           }
                           lista getFilas(){return filas;}
                           lista getColumna(){return columnas;} 
                           void toprint();
};

void matrix::agregar_fila(nodo2* primero,nodo2* elemento,nodo2*anterior){    
     if(primero->get_nextfila()==NULL){
                                       elemento->set_nextfila(primero);
                                       anterior->set_nextfila(elemento);}
     else{
          agregar_fila(primero->get_nextfila(),elemento,primero);}   
}

void matrix::agregar_columna(nodo2* primero,nodo2* elemento,nodo2*anterior)
{    if(primero->get_nextcol()==NULL){
                                      elemento->set_nextcol(primero);
                                     anterior->set_nextcol(elemento);}
     
     else {agregar_columna(primero->get_nextcol(),elemento,primero);}   
}

nodo* matrix::avanzarAposicion(int n,nodo* apuntador){
      if (n==0)
         return apuntador;
      else return avanzarAposicion(n-1,apuntador->get_next());
}
         
    
void matrix::toprint(){
     
     cout<<"soy to print "<<endl;
     nodo* d;
     nodo2* a;
     int fila=0,columna=0;
     d=filas.get_czo();
     
     while (d->get_next()!=NULL){
           a=d->get_puntero();
           while (a->get_nextfila()!=NULL){
                 while((a->get_col()>columna)/*&&(columna<=tamanio)*/){
                                             cout<<setw(4)<<"0";
                                             columna++;
                                             }
                                           
                                           
                   columna++;                        
                 cout<<setw(4)<<a->get_dato();
                 a=a->get_nextfila();
                        //system("pause");
           }
           columna=0;
     //cout<<"siguiente fila "<<endl;
     d=d->get_next();
     cout<<endl;
     }
}

