//#include <cstdlib>
#include <iostream>
#include <sstream>
#include "ListaClase.cpp"
#include <ctime>
#include "ListaInt.cpp"

using namespace std;

NodoArbolB::NodoArbolB() {
   for (int i=0;i<ORDEN+2;i++)
       hijos[i]=NULL;
       lastused=-1;
}

void NodoArbolB::set_dato(int a) {
      int i=lastused;
      
      dato[lastused+1]=a;
      while((a<dato[i])&&(i>=0)){
                                 int temp=dato[i];
                                 dato[i]=dato[i+1];
                                 dato[i+1]=temp;
                                 i--;
      }
      lastused++;  
   ///cambiar esta funcion por una que inserte ordenando por insercion
}

bool NodoArbolB::is_dato(int a) {
     bool ret=false;
     int pos, Li=0,Ls=lastused;
     
     while (Li<=Ls){
           pos=(Ls+Li)/2;
           if (dato[pos]==a) return true;
           else{
                if (a<dato[pos]) Ls=pos-1;
                else Li=pos+1;
           }
     }
     return ret;
   ///cambiar por una funcion que haga busqueda binaria
}

int NodoArbolB::get_pos(int a) {
    int ret=-100, pos, Li=0, Ls=lastused;
    
    while (Li<=Ls){
          pos=(Ls+Li)/2;
          if (dato[pos]==a) return pos;
          else{
               if (a<dato[pos]) Ls=pos-1;
               else Li=pos+1;
          }
    }
    return ret;
}

class ArbolB{
    private: 
             int altura1(int suma,NodoArbolB *a);
             void insert2(int,NodoArbolB*,Pila &,bool,NodoArbolB* Hi,NodoArbolB* Hd);
             void toPrint2(NodoArbolB*);
             void toLista2(Lista1*,NodoArbolB*);
    public:
            NodoArbolB *nodo;
            ArbolB() {nodo=NULL;};
            ArbolB(NodoArbolB *p) {nodo=p;};
            ~ArbolB(void) ;
            NodoArbolB *get_nodo() {return nodo;};
            bool esvacio(void) {return nodo==NULL;};
            int altura();
            void insert(int a);
            Lista1 *toLista();
            void toPrint();
            void borrador(NodoArbolB* &a);
};

ArbolB::~ArbolB(void){
                       borrador(nodo);
}

void ArbolB::borrador(NodoArbolB* &a){
     if(a==NULL){
                delete a;
                a=NULL;
     }
     else{               
          for (int i=0;i<=a->get_lastused()+1;i++){
              borrador(a->hijos[i]);
          }
          delete a;
          a=NULL;
     } 
}

int ArbolB::altura(){
    return altura1(0,nodo);
}

int ArbolB::altura1(int suma,NodoArbolB* a){
    if (a==NULL) return suma;
    else return altura1(suma+1,a->get_hijo(0));
}

void ArbolB::insert(int a){
     if (nodo==NULL){
                     nodo=new NodoArbolB();
                     nodo->set_dato(a);
     }
     else{
          Pila pila;
          insert2(a,nodo,pila,false,NULL,NULL);
     }
}

void ArbolB::insert2(int a,NodoArbolB* p,Pila &pila,bool insercion,NodoArbolB* Hi,NodoArbolB* Hd){
     if(p->is_dato(a)==false){
                  if((p->es_hoja())||(Hi!=NULL)){
                                //cout<<"es hoja ";
                                if (p->is_dato(a)==false){                
                                                     if(p->lleno()){
                                                                    if(Hi==NULL) p->set_dato(a);
                                                                    else{
                                                                         p->set_dato(a);  
                                                                         int pos=p->get_pos(a);
                                                                         p->set_hijo(pos,Hi);
                                                                         int inicial=p->get_lastused()+1;
                                                                         int j=ORDEN+1;
                                                                         p->set_hijo(j,Hd);
                                                                         
                                                                         for(int i=0;i<ORDEN-pos;i++){
                                                                                 NodoArbolB* temp=p->get_hijo(j-1);
                                                                                 p->set_hijo(j-1,p->get_hijo(j));
                                                                                 p->set_hijo(j,temp);j--;
                                                                         }
                                                                    }
                                                                    if (pila.pilavacia()){
                                                                             //cout<<"entro ";
                                                                             NodoArbolB* padre=new NodoArbolB();
                                                                             NodoArbolB* hi=new NodoArbolB();
                                                                             NodoArbolB* hd=new NodoArbolB();
                                                                             padre->set_hijo(0,hi);
                                                                             padre->set_hijo(1,hd);
                                                                                 
                                                                                 
                                                                             for(int i=0;i<ORDEN/2+1;i++){
                                                                                                          if(i<ORDEN/2) hi->set_dato(nodo->get_dato(i));
                                                                                                          hi->set_hijo(i,nodo->get_hijo(i));
                                                                                                          }
                                                                             padre->set_dato(nodo->get_dato(ORDEN/2));
                                                                                 
                                                                             int j=0;
                                                                             for(int i=ORDEN/2+1;i<ORDEN+2;i++){
                                                                                                                if(i<ORDEN+1){hd->set_dato(nodo->get_dato(i));}
                                                                                                                hd->set_hijo(j,nodo->get_hijo(i));j++;
                                                                                                                }
                                                                             nodo=padre;
                                                                             delete p;
                                                                             insercion=true;
                                                                    }
                                                                    else{
                                                                         NodoArbolB* hi=new NodoArbolB();
                                                                         NodoArbolB* hd=new NodoArbolB();
                                                                         a=p->get_dato(ORDEN/2);
                                                                                 
                                                                         for(int i=0;i<ORDEN/2+1;i++){
                                                                                 if(i<ORDEN/2){hi->set_dato(p->get_dato(i));}
                                                                                 hi->set_hijo(i,p->get_hijo(i));
                                                                         }
                                                                                 
                                                                         int j=0;
                                                                         for(int i=ORDEN/2+1;i<ORDEN+2;i++){
                                                                                 if(i<ORDEN+1){hd->set_dato(p->get_dato(i));}
                                                                                 hd->set_hijo(j,p->get_hijo(i));j++;
                                                                         }
                                                                         
                                                                         NodoArbolB* anterior=pila.tope();
                                                                         pila.pop();
                                                                         delete p; 
                                                                         insert2(a,anterior,pila,false,hi,hd);
                                                                    }                    
                                                     }
                                                     else{
                                                          if(Hi==NULL){p->set_dato(a);insercion=true;}
                                                          else {
                                                               p->set_dato(a);
                                                               int pos=p->get_pos(a);
                                                               p->set_hijo(pos,Hi);
                                                               int inicial=p->get_lastused()+1;
                                                               int ultimoLugar=ORDEN+2;
                                                               int j=ORDEN+1;
                                                               p->set_hijo(j,Hd);
                                                               for(int i=0;i<ORDEN-pos;i++){
                                                                       NodoArbolB* temp=p->get_hijo(j-1);
                                                                       p->set_hijo(j-1,p->get_hijo(j));
                                                                       p->set_hijo(j,temp);j--;
                                                               }
                                                          insercion=true;
                                                          }
                                                     }
                                }
                  }
                  else{
                       int i=0;
                       while ((a>p->get_dato(i))&&(i<=p->get_lastused())){
                                                             i++;
                                                             cout<<i<<" ";
                       }
                       pila.push(p);
                       insert2(a,p->get_hijo(i),pila,false,NULL,NULL);
                  }
     }
}


Lista1 *ArbolB::toLista(){
       Lista1* lista=new Lista1();
       toLista2(lista,nodo);
       return lista;
}

void ArbolB::toLista2(Lista1* lista,NodoArbolB* a){
     if(a==NULL)
     {}
     else{
          int j=0;            
          
          for (int i=0;i<=a->get_lastused()+1;i++){
              toLista2(lista,a->get_hijo(i));
              if (i<=a->get_lastused()){
                                        lista->add(a->get_dato(i));j++;
              }
          }
     }  
}

void ArbolB::toPrint(){
     toPrint2 (nodo);
}
     
void ArbolB::toPrint2(NodoArbolB* a){
     if(a==NULL)
     {}
     else{
          cout<<"\n";int j=0;            
                          
          for (int i=0;i<=a->get_lastused()+1;i++){
              toPrint2(a->get_hijo(i));
              if (i<=a->get_lastused()){
                                        cout<<" "<<a->get_dato(i);j++;
              }
          }
     }                
}

int main(){
    NodoArbolB *b =new NodoArbolB();
    ArbolB *a=new ArbolB();
    
    b->set_dato(2);
    b->set_dato(5);
    b->set_dato(3);
    cout<<b->get_dato(0)<<endl;
    cout<<b->get_dato(1)<<endl;
    cout<< b->get_dato(2)<<endl;  
   /* a->insert(97);
    a->insert(95);
    a->insert(92);
    a->insert(85);
    a->insert(76);
    a->insert(74);
    a->insert(63);
    a->insert(42);
    a->insert(35);
    a->insert(25);
    a->insert(20);
    a->insert(10);*/
    
    for(int I=0;I<1000;I++)
            a->insert(rand()%100);
      
    a->insert(24);
    a->toPrint();
   // a->get_nodo()->set_hijo(0,b);
    Lista1* lista=a->toLista();
    cout<<"\n";
    cout<<lista->toPrint("");
    cout<<"\n altura: "<<a->altura()<<"\n";
    a->borrador(a->nodo);
    a->toPrint();
    cout<< "altura: " << a->altura() <<endl;
    
    delete a;    

    system("PAUSE");
}
