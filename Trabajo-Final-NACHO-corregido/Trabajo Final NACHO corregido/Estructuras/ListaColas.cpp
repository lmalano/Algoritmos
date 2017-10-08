#include <iostream>
#include <iomanip>
#include <sstream>
#include "Cola.cpp"
#include "Paquete.cpp"
#ifndef LISTACOLAS_H
#define LISTACOLAS_H
using namespace std;

typedef Cola<Paquete>* tipolist;

class NodoCola{
	private:
		tipolist dato;
		NodoCola *next;
	public:
		NodoCola(tipolist d){dato = d; next = NULL;};
		tipolist getDato(){return dato;};
		void setDato(tipolist d){dato = d;};
		NodoCola *getNext(){return next;};
		void setNext(NodoCola *n){next = n;};
};

class ListaColas{
	private:
		NodoCola *comienzo;
	public:
		ListaColas(){comienzo = NULL;};
		ListaColas(NodoCola *n){comienzo = n;};
		NodoCola *getNext(){return comienzo->getNext();};
		void add(tipolist d);
		bool esVacia(){return comienzo == NULL;};
		tipolist cabecera(){return comienzo->getDato();};
		ListaColas *resto();
		NodoCola *getComienzo(){return comienzo;};
		Cola<Paquete>* getColaNum(int d);
		void encolarEn(int d, Paquete p);
		Paquete desencolarDe(int d){return getColaNum(d)->desencolar();};
		void toPrint();
		NodoCola* eliminarCola(int nombreCola);
};

/*------------------------------ADD---------------------------------OK*/

void ListaColas::add(tipolist d){
	NodoCola *n1 = new NodoCola(d);
	n1->setNext(comienzo);
	comienzo = n1;
}

/*-----------------------------RESTO--------------------------------OK*/

ListaColas *ListaColas::resto(){
	ListaColas *l = new ListaColas(comienzo->getNext());
	return l;
}

/*--------------------------GET COLA NUM----------------------------OK*/

Cola<Paquete>* ListaColas::getColaNum(int d){
	if(cabecera()->getNombreCola() == d)
		return cabecera();
	else if(resto()->esVacia()){
		cout << "La cola no pertenece a la lista" << endl;
		return NULL;
	}
	else
		return resto()->getColaNum(d);
}

/*---------------------------ENCOLAR EN-----------------------------OK*/

void ListaColas::encolarEn(int d, Paquete p){
	if(cabecera()->getNombreCola() == d)
		cabecera()->encolar(p);
	else
		resto()->encolarEn(d, p);
}

/*----------------------------TO PRINT------------------------------OK*/

void ListaColas::toPrint(){
	if(comienzo == NULL)
		return;
	else{
		cabecera()->toPrint();
		return resto()->toPrint();
	}
	
}

/*--------------------------ELIMINAR COLA---------------------------OK*/

NodoCola* ListaColas::eliminarCola(int nombreCola){
	if(cabecera()->getNombreCola() == nombreCola){
		NodoCola* aux = comienzo->getNext();
		delete comienzo;
		comienzo = aux;
		return comienzo;
	}
	else if(comienzo->getNext() != NULL){
		comienzo->setNext(resto()->eliminarCola(nombreCola));
	}
	return comienzo;
}

/*int main(){
	ListaColas lc;
	Cola<Paquete> *a,*b,*c;
	a = new Cola<Paquete>();
	b = new Cola<Paquete>();
	c = new Cola<Paquete>();
	Paquete p,q,r,s,t,u;
	p.setInfo('L');
	q.setInfo('u');
	r.setInfo('c');
	s.setInfo('a');
	t.setInfo('s');
	u.setInfo('.');
	a->setNombreCola(4);
	b->setNombreCola(9);
	c->setNombreCola(15);
	lc.add(a);
	lc.add(b);
	lc.add(c);
	lc.encolarEn(9, p);
	lc.encolarEn(9, q);
	lc.encolarEn(9, r);
	lc.encolarEn(9, s);
	lc.encolarEn(9, t);
	lc.encolarEn(9, u);
	b->toPrint();
	lc.encolarEn(4, u);
	lc.encolarEn(4, t);
	lc.encolarEn(4, s);
	lc.encolarEn(4, r);
	lc.encolarEn(4, q);
	lc.encolarEn(4, p);
	a->toPrint();
	lc.encolarEn(15, u);
	lc.encolarEn(15, r);
	lc.encolarEn(15, s);
	lc.encolarEn(15, t);
	lc.encolarEn(15, p);
	lc.encolarEn(15, q);
	c->toPrint();
	cout << "Todas las colas" << endl;
	lc.toPrint();
	lc.eliminarCola(1);
	cout << "Todas las colas" << endl;
	lc.toPrint();
	lc.encolarEn(9, p);
	lc.encolarEn(9, q);
	lc.encolarEn(9, r);
	lc.encolarEn(9, s);
	lc.encolarEn(9, t);
	lc.encolarEn(9, u);
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	lc.encolarEn(9, u);
	lc.encolarEn(9, t);
	lc.encolarEn(9, s);
	lc.encolarEn(9, s);
	lc.encolarEn(9, t);
	lc.encolarEn(9, u);
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	cout << b->desencolar().getInfo() << endl;
	return 0;
}
*/
#endif
