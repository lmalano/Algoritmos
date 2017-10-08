#include <iostream>
#include "pagina.cpp"
#include <cstdlib>
#include <string>
#ifndef MAQUINA_H
#define MAQUINA_H
using namespace std;

struct IP{
	int maquina;
	int router;
};

class Maquina {
	private:
		IP ip;
	    int numeroAleatorio(int limite){return (rand() % (limite + 1));};
	    string stringAleatorio(int tamanio);
	public:
	    Maquina(int rout,int maq){setIP(rout,maq);srand(time_t(NULL));};
	    void setIP(int rout,int maq){ip.maquina=maq;ip.router=rout;};
	    IP getIP(){return ip;};
	    Pagina mandarPagina();
};
/*--------------------------STRING ALEATORIO--------------------------*/
string Maquina::stringAleatorio(int tamanio){
	char lista[36] = {'0','1','2','3','4','5','6','7','8','9','A','B',
	'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S',
	'T','U','V','W','X','Y','Z'};
	string cadena;
	for(int i = 0; i < tamanio; i++)
		cadena += lista[numeroAleatorio(35)];
	return cadena;
}
/*---------------------------MANDAR PAGINA----------------------------*/
Pagina Maquina::mandarPagina(){
	Pagina  pagina(1 + numeroAleatorio(39)); //Genera una página de tamanio aleatorio entre 1 y 40
	pagina.setNombre(numeroAleatorio(99999999));
    pagina.setInformacion(stringAleatorio(pagina.getTamanio()));
    pagina.setMaqOrigen(ip.maquina);
    pagina.setRoutOrigen(ip.router);
    pagina.setMaqDestino(numeroAleatorio(255));
    pagina.setRoutDestino(numeroAleatorio(255));
	return pagina;
}
#endif
