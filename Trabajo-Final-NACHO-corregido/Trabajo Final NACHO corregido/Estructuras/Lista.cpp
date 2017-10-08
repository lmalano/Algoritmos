#include <iostream>
#include <iomanip>
#include <sstream>
#include "Paquete.cpp"
#ifndef LISTA_H
#define LISTA_H
using namespace std;

template<typename Tnodo>
class Nodo{
	private:
		Tnodo dato;
		Nodo *next;
	public:
		Nodo(Tnodo data){dato = data; next = NULL;};
		Tnodo getDato(){return dato;};
		void setDato(Tnodo d){dato = d;};
		Nodo *getNext(){return next;};
		void setNext(Nodo *n){next = n;};
};

template<typename Tlista>
class Lista{
	private:
		Nodo<Tlista> *comienzo;
	public:
		Lista(){comienzo = NULL;};
		Lista(Nodo<Tlista> *n){comienzo = n;};
		Nodo<Tlista> *getNext(){return comienzo->getNext();};
		void add(Tlista data);
		bool esVacia(){return comienzo == NULL;};
		Tlista cabecera(){return comienzo->getDato();};
		Lista *resto();
		string toPrint();
		Lista *concatenarLista(Lista *L);
		void borrarCabecera();
		Nodo<Tlista> *getComienzo(){return comienzo;};
		bool pertenece(Tlista nodo);
		void borrarUltimo();
};
/*------------------------------ADD---------------------------------*/
template<typename Tlista>
void Lista<Tlista>::add(Tlista data){
	Nodo<Tlista> *n1 = new Nodo<Tlista>(data);
	n1->setNext(comienzo);
	comienzo = n1;
}
/*------------------------------RESTO---------------------------------*/
template<typename Tlista>
Lista<Tlista> *Lista<Tlista>::resto(){
	Lista<Tlista> *l = new Lista(comienzo->getNext());
	return l;
}
/*-----------------------------TO PRINT-------------------------------*/
template<typename Tlista>
string Lista<Tlista>::toPrint(){
	if(esVacia()){
		return "";
	}
	else{
		std::ostringstream stm;
		stm << " - " << cabecera() << resto()->toPrint() ;
		return stm.str();
	}
}

/*------------------------CONCATENAR LISTA----------------------------*/
template<typename Tlista>
Lista<Tlista> *Lista<Tlista>::concatenarLista(Lista<Tlista> *L){
	if(!L->esVacia()){
		concatenarLista(L->resto());
		this->add(L->cabecera());
	}
	return this;
}
/*-------------------------BORRAR CABECERA----------------------------*/
template<typename Tlista>
void Lista<Tlista>::borrarCabecera(){
	if(esVacia())
		return;
	Nodo<Tlista> *aux = comienzo;
	comienzo = aux->getNext();
	delete aux;
}
/*----------------------------PERTENECE-------------------------------*/
template<typename Tlista>
bool Lista<Tlista>::pertenece(Tlista nodo){
	if(esVacia())
		return false;
	if(cabecera() == nodo)
		return true;
	else if(!resto()->esVacia())
		return resto()->pertenece(nodo);
	return false;
}

/*-------------------------TO PRINT PAQUETES--------------------------*/
template<>
string Lista<Paquete>::toPrint(){
	if(esVacia()){
		return "";
	}
	else{
		std::ostringstream stm;
		stm << " - " << cabecera().getInfo() << " / " << cabecera().getID() << "/" << cabecera().getOrden() << "/" << cabecera().getRoutDestino() << '.' << cabecera().getMaqDestino() << endl << resto()->toPrint() ;
		return stm.str();
	}
}

/*---------------------------BORRAR ULTIMO----------------------------*/
template<typename Tlista>
void Lista<Tlista>::borrarUltimo(){
	if(getComienzo()->getNext() == NULL){
		comienzo = NULL;
		return;
	}
	if(resto()->getComienzo()->getNext() == NULL){
		comienzo->setNext(NULL);
		return;
	}
	else{
		resto()->borrarUltimo();
	}
}
/*--------------------------------------------------------------------*/
/*
int main(){	
	Lista<double> list;
	Lista<double> list2;
	list.add(2);
	list.add(2.13);
	list.add(56);
	cout << list.toPrint() << endl;
	list.borrarUltimo();
	cout << list.toPrint() << endl;
	list.borrarUltimo();
	cout << list.toPrint() << endl;
	list.borrarUltimo();
	cout << list.toPrint() << endl;
	list2.add(4.5);
	list2.add(5);
	cout << list.toPrint() << endl;
	cout << "pertenece el 3? " << list.pertenece(3) << endl;
	list.borrarCabecera();
	cout << list.toPrint() << endl;
	cout << list2.toPrint() << endl;
	list.concatenarLista(&list2);
	cout << list.toPrint() << endl;
	return 0;
}
*/
#endif
