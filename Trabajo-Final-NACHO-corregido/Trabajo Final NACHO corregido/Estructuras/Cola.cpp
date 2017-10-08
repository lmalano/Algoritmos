#include <iostream>
#include <fstream>
#include "Lista.cpp"
#include "Paquete.cpp"
#ifndef COLA_H
#define COLA_H
using namespace std;
ofstream pantalla("pantalla.dat", ios::out);

template<typename Tcola>
class Cola{
	private:
		int nombreCola;
		Lista<Tcola> *l;
		Nodo<Tcola> *tope;
		Nodo<Tcola> *ultimo;
	public:
		Cola(){l = new Lista<Tcola>(); nombreCola = 0; tope = NULL; ultimo = NULL;};
		void setNombreCola(int rout){nombreCola = rout;};
		int getNombreCola(){return nombreCola;};
		void encolar(Tcola d);
		Tcola desencolar();
		bool esVacia(){return tope == NULL;};
		Tcola getTope(){return tope->getDato();};
		Lista<Tcola>* getLista(){return l;};
		void toPrint(){if(!esVacia())pantalla << "    Cola al router " << getNombreCola() << " --- " << l->toPrint() << endl;};
		int getTamanio(Lista<Tcola>* list, int tamanioAcumulado);
};

/*------------------------------ENCOLAR-----------------------------OK*/

template<typename Tcola>
void Cola<Tcola>::encolar(Tcola d){
	l->add(d);
	ultimo = l->getComienzo();
	if(tope == NULL){
		tope = l->getComienzo();
	}
}

/*----------------------------DESENCOLAR----------------------------OK*/

template<typename Tcola>
Tcola Cola<Tcola>::desencolar(){
	if(!esVacia()){
		Lista<Tcola>* aux = l;
		Tcola retorno = getTope();
		while(aux->resto()->getComienzo() != tope && aux->resto()->getComienzo() != NULL){
			aux = aux->resto();
		}
		if(tope == ultimo){
			tope = NULL;
		}
		else
			tope = aux->getComienzo();
		getLista()->borrarUltimo();
		return retorno;
	}
	else{
		Tcola retorno;
		retorno.setInfo('!');
		cout << "La cola esta vacia";
		return retorno;
	}
}

/*----------------------------GET TAMANIO---------------------------OK*/

template<typename Tcola>
int Cola<Tcola>::getTamanio(Lista<Tcola>* list, int tamanioAcumulado){
	if(list->getComienzo() == tope){
		if(esVacia())
			return 0;
		else
			return tamanioAcumulado+1;
	}
	else
		return getTamanio(list->resto(), tamanioAcumulado + 1);
}

/*
int main(){
	Cola<Paquete> c;
	Paquete p,q,r,s,t,u;
	p.setInfo('L');
	q.setInfo('u');
	r.setInfo('c');
	s.setInfo('a');
	t.setInfo('s');
	u.setInfo('.');
	c.encolar(p);
	c.encolar(q);
	c.encolar(r);
	c.encolar(s);
	c.encolar(t);
	c.encolar(u);
	cout << "Cola antes de desencolar " << endl;
	c.toPrint();
	cout << c.desencolar().getInfo() << endl;
	cout << "Cola despues de desencolar" << endl;
	c.toPrint();
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	c.encolar(u);
	c.encolar(t);
	c.encolar(s);
	c.encolar(s);
	c.encolar(t);
	c.encolar(u);
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	c.encolar(u);
	c.encolar(t);
	c.encolar(s);
	c.encolar(s);
	c.encolar(t);
	c.encolar(u);
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	cout << c.desencolar().getInfo() << endl;
	return 0;
}
*/
#endif
