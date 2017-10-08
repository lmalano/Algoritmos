//#include <cstdlib>
#include <iostream>
#include <sstream>
#include "ListaClase.cpp"

using namespace std;

NodoArbolB::NodoArbolB() {
   for (int i=0;i<ORDEN+2;i++)
       hijos[i]=NULL;
       padre=NULL;
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
//cambiar esta funcion por una que inserte ordenando por insercion
}

bool NodoArbolB::is_dato(int a) {    // Pregunta si el dato esta en el arbol
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

int NodoArbolB::get_pos(int a) {  /// Devuelve la posicion del dato
   int ret=-1, pos, Li=0,Ls=lastused;
   
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
             NodoArbolB *nodo;
             int altura1(int suma,NodoArbolB *a);
             void insert2(int,NodoArbolB*,Pila &,bool,NodoArbolB* Hi,NodoArbolB* Hd);
             void toPrint2(NodoArbolB*);
    public:
            ArbolB() {nodo=NULL;};
            ArbolB(NodoArbolB *p) {nodo=p;};
            ~ArbolB(void);
            NodoArbolB *get_nodo() {return nodo;};
            bool esvacio(void) {return nodo==NULL;};
            int altura();
            void insert(int a);
            Lista *toLista(Lista *l);
            void toPrint();
};

ArbolB::~ArbolB(void)
{
   if (!esvacio()){
      delete nodo;
      ///completar
   }
}

int ArbolB::altura()
{
    return altura1(0,nodo);
}

int ArbolB::altura1(int suma,NodoArbolB* a)
{
   if (a==NULL) return suma;
   else return altura1(suma+1,a->get_hijo(0));     
}

void ArbolB::insert(int a)
{
   if (nodo==NULL){
      nodo=new NodoArbolB();
      nodo->set_dato(a);
   }
   else{
        Pila pila;
        insert2(a,nodo, pila, false, NULL, NULL);
   }
}

void ArbolB::insert2(int a, NodoArbolB* p, Pila &pila, bool insercion, NodoArbolB* Hi, NodoArbolB* Hd)
{
     if(insercion==true)
     {}  
     else {
          if((p->es_hoja())||(Hi!=NULL)){
                    cout<<"es hoja ";
                    if(p->lleno()){
                          if(Hi==NULL){
                                       p->set_dato(a);
                          }
                          else {
                               p->set_dato(a);  
                               int pos=p->get_pos(a);
                               p->set_hijo(pos,Hi);
                               int inicial=p->get_lastused()+1;
                               
                               for(int i=0;i<inicial-1-pos;i++){
                                       p->set_hijo(inicial,p->get_hijo(inicial-1));inicial--;
                               }
                               p->set_hijo(pos+1,Hd);
                          }
                          if (pila.pilavacia()){     /// hace la division del nodo
                                cout<<"entro ";
                                NodoArbolB* padre=new NodoArbolB();
                                NodoArbolB* hi=new NodoArbolB();
                                NodoArbolB* hd=new NodoArbolB();
                                hi->set_padre(padre);
                                hd->set_padre(padre);
                                padre->set_hijo(0,hi);
                                padre->set_hijo(1,hd);
                                                                                                
                                for(int i=0;i<ORDEN/2+1;i++){
                                        if(i<ORDEN/2){
                                                      hi->set_dato(nodo->get_dato(i));
                                        }
                                        hi->set_hijo(i,nodo->get_hijo(i));
                                }
                                padre->set_dato(nodo->get_dato(ORDEN/2));
                                                                                 
                                int j=0;
                                for(int i=ORDEN/2+1;i<ORDEN+2;i++){
                                        if(i<ORDEN+1){
                                                      hd->set_dato(nodo->get_dato(i));
                                        }
                                        hd->set_hijo(j,nodo->get_hijo(i));j++;
                                }
                                nodo=padre;
                                delete p;
                                insercion=true;
                          }
                          else{
                               NodoArbolB* hi=new NodoArbolB();
                               NodoArbolB* hd=new NodoArbolB();
                               hi->set_padre(pila.tope());
                               hd->set_padre(pila.tope());
                               a=p->get_dato(ORDEN/2);
                                                                                 
                               for(int i=0;i<ORDEN/2+1;i++){
                                       if(i<ORDEN/2){
                                                     hi->set_dato(p->get_dato(i));
                                       }
                                       hi->set_hijo(i,p->get_hijo(i));
                               }
                                                                                 
                               int j=0;
                               for(int i=ORDEN/2+1;i<ORDEN+2;i++){
                                       if(i<ORDEN+1){
                                                     hd->set_dato(p->get_dato(i));
                                       }
                                       hd->set_hijo(j,p->get_hijo(i));j++;
                               }
                               NodoArbolB* anterior=p->get_padre();
                               pila.pop();
                               insert2(a,anterior,pila,false,hi,hd);
                          }                    
                                                                                 
                    }      
                   else{
                        if(Hi==NULL){
                                     p->set_dato(a);insercion=true;
                        }
                        else {
                             p->set_dato(a);
                             int pos=p->get_pos(a);
                             p->set_hijo(pos,Hi);
                             int inicial=p->get_lastused()+1;
                             for(int i=0;i<inicial-1-pos;i++){
                                     p->set_hijo(inicial,p->get_hijo(inicial-1));inicial--;
                             }
                             p->set_hijo(pos+1,Hd);
                             insercion=true;
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


/*Lista *ArbolB::toLista(Lista *l){
      for (int i=0;i<=this->get_nodo()->get_lastused();i++){
         l->add(this->get_nodo()->get_dato(i));
      }
      return l;
      ///reemplazar por la version correcta
}
*/

void ArbolB::toPrint()
{
     toPrint2 (nodo);
}
     
void ArbolB::toPrint2(NodoArbolB* a)
{
     if(a==NULL)
     {}
     else{
          cout<<"\n";int j=0;            
          for (int i=0;i<=a->get_lastused()+1;i++){
              toPrint2(a->get_hijo(i));
              if (j<=a->get_lastused(){
                                       cout<<" "<<a->get_dato(j);j++;
              }
          }
     }                
}
     

int main()
{
    NodoArbolB *b =new NodoArbolB();
    ArbolB *a=new ArbolB();
    
    b->set_dato(2);
    b->set_dato(5);
    b->set_dato(3);
    cout<<b->get_dato(0)<<endl;
    cout<<b->get_dato(1)<<endl;
    cout<< b->get_dato(2)<<endl;  
    
    for(int I=0;I<16;I++)
    a->insert(I);
      
    a->toPrint();
   // a->get_nodo()->set_hijo(0,b);
    cout<< "altura" << a->altura() <<endl;
    
    delete a;    

    system("PAUSE");
}
