#include <iostream>
#include <fstream>
#include "Estructuras/Grafo.cpp"
#ifndef ADMIN_H
#define ADMIN_H
using namespace std;

class Admin{
	private:
		double BW[256][256];
		Grafo<int, double>* server;
	public:
		Admin(int[256][256]);
		void setBW(int rout1, int rout2, int bw){BW[rout1][rout2] = bw;};
		void setPeso(int origen, int destino, int tamanioCola){server->setArco(origen, destino, tamanioCola/BW[origen][destino]);};
		void encontrarCMC(int origen, int []);
};

/*----------------------------CONSTRUCTOR-----------------------------*/

Admin::Admin(int matriz[256][256]){
	server = new Grafo<int, double>(false);
	for(int i = 0 ; i < 256; i++)
		for(int j = 0; j < 256; j++){
			if(matriz[i][j] != 0){
				BW[i][j] = matriz[i][j];
				server->addVertice(i);
				server->addVertice(j);
			}
			else
				BW[i][j] = 0;
			setPeso(i, j, 1);
		}
}

/*------------------ENCONTRAR CAMINO MAS CORTO------------------------*/

void Admin::encontrarCMC(int origen, int precedencias[256]){
	server->Dijkstra(origen, precedencias);
}

#endif
