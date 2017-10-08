#include <iostream>
#include "Lista.cpp"
#ifndef SET_H
#define SET_H
using namespace std;

template<typename Tset>
class Set{
	private:
		bool pertenece2(Lista<Tset>* conj, Tset d);
		Lista<Tset>* conjunto;
	public:
		Set(){conjunto = new Lista<Tset>();};
		void agregar(Tset d){if(!pertenece(d))conjunto->add(d);};
		bool pertenece(Tset d){return pertenece2(this->getConjunto(), d);};
		Lista<Tset>* getConjunto(){return conjunto;};
		bool esVacio(){return conjunto->esVacia();};
		Set<Tset>* uneon(Set<Tset>* B);       //A U B
		Set<Tset>* interseccion(Set<Tset>* B);//A & B
		Set<Tset>* diferencia(Set<Tset>* B);  //A - B
		void toPrint(){cout << conjunto->toPrint() << endl;};
};
/*---------------------------PERTENECE2-------------------------------*/
template<typename Tset>
bool Set<Tset>::pertenece2(Lista<Tset>* conj, Tset d){
	if(conj->esVacia())
		return false;
	else if(conj->cabecera() == d)
		return true;
	else
		return pertenece2(conj->resto(), d);
}
/*------------------------------UNEON---------------------------------*/
template<typename Tset>
Set<Tset>* Set<Tset>::uneon(Set<Tset>* B){
	Set<Tset>* retorno = new Set<Tset>();
	Lista<Tset>* aux;
	aux = getConjunto();
	while(!aux->esVacia()){ //Llena el conjunto con los elementos de A.
		retorno->agregar(aux->cabecera());
		aux = aux->resto();
	}
	aux = B->getConjunto();
	while(!aux->esVacia()){ //Agrega al conjunto los elementos de B que no estaban en A.
		if(!pertenece(aux->cabecera()))
			retorno->agregar(aux->cabecera());
		aux = aux->resto();
	}
	return retorno;
}
/*--------------------------INTERSECCION------------------------------*/	
template<typename Tset>
Set<Tset>* Set<Tset>::interseccion(Set<Tset>* B){
	Set<Tset>* retorno = new Set<Tset>();
	Lista<Tset>* aux;
	aux = getConjunto();
	while(!aux->esVacia()){
		if(B->pertenece(aux->cabecera()))
			retorno->agregar(aux->cabecera());
		aux = aux->resto();
	}
	return retorno;
}
/*---------------------------DIFERENCIA-------------------------------*/
template<typename Tset>
Set<Tset>* Set<Tset>::diferencia(Set<Tset>* B){
	Set<Tset>* retorno = new Set<Tset>();
	Lista<Tset>* aux;
	aux = getConjunto();
	while(!aux->esVacia()){
		if(!B->pertenece(aux->cabecera()))
			retorno->agregar(aux->cabecera());
		aux = aux->resto();
	}
	return retorno;
}
/*
int main(){
	Set<int> conjunto;
	Set<int> conj1;
	Set<int> conj2;
	conj1.agregar(12);
	conj1.agregar(15);
	conj2.agregar(5);
	conj2.agregar(9);
	cout << "Esta vacio?" << conjunto.esVacio() << endl;
	conjunto.agregar(5);
	cout << "Esta vacio?" << conjunto.esVacio() << endl;
	conjunto.agregar(9);
	conjunto.agregar(6);
	conjunto.agregar(1);
	conjunto.agregar(4);
	conjunto.agregar(2);
	conjunto.agregar(3);
	cout << "El 5 pertenece?" << conjunto.pertenece(5) << endl;
	cout << conjunto.getConjunto()->toPrint() << endl;
	cout << "Metodo toPrint()";
	conjunto.toPrint();
	cout << endl;
	cout << "Interseccion entre conjunto y conj2";
	conjunto.interseccion(&conj2)->toPrint();
	cout << endl;
	cout << "Union entre conjunto y conj1";
	conjunto.uneon(&conj1)->toPrint();
	cout << endl;
	cout << "Diferencia entre conjunto y conj2";
	conjunto.diferencia(&conj2)->toPrint();
	cout << endl;
	return 0;
}
*/
#endif
