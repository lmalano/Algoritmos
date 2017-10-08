#include <iostream>
#include <iomanip>
#include "Set.cpp"
#ifndef GRAFO_H
#define GRAFO_H
using namespace std;

const int INF = 9999;//lo cambie a int...........
const int numeroVertices = 256;

template<typename datos, typename etiqueta>
class Grafo{
	private:
		int iMin, jMin;
		etiqueta aristaMin; //se utilizan para los algoritmos que comienzan con el camino con menor peso.
		Set<datos>* vertices;
		etiqueta arcos[numeroVertices][numeroVertices];
		bool dirigido;
	public:
		Grafo(bool dir){dirigido = dir; vertices = new Set<datos>(); fillArcos(); aristaMin = INF;};
		void fillArcos();
		void addVertice(datos vert){vertices->agregar(vert);};
		void setArco(int i, int j, etiqueta peso);
		Set<datos>* getVertices(){return vertices;};
		etiqueta getEtiqueta(int i, int j){return arcos[i][j];};
		bool esDirigido(){return dirigido;};
		bool esVertice(datos vert){return vertices->pertenece(vert);};
		Grafo<datos, etiqueta>* Prim();
		void Dijkstra(int origen, int precedencias[numeroVertices]);
		void toPrint();
};
/*----------------------------FILL ARCOS------------------------------*/
template<typename datos, typename etiqueta>
void Grafo<datos, etiqueta>::fillArcos(){ //este metodo llena la matriz de adyacencia cuando se construye el grafo, con todos
										  //valores infinitos.
	for(int i = 0; i < numeroVertices; i++){
		for(int j = 0; j < numeroVertices; j++)
			arcos[i][j] = INF;
	}
}
/*-----------------------------SET ARCO-------------------------------*/
template<typename datos, typename etiqueta>
void Grafo<datos, etiqueta>::setArco(int i, int j, etiqueta peso){
	if(peso != 0){
		arcos[i][j] = peso;
		if(!esDirigido())
			arcos[j][i] = peso;
	}
	else{
		arcos[i][j] = INF;
		if(!esDirigido())
			arcos[j][i] = INF;
	}
	if(peso < aristaMin){
		aristaMin = peso;
		iMin = i; //guarda el vertice de origen del arco de peso mínimo.
		jMin = j; //guarda el vertice de destino del arco de peso mínimo.
	}
}
/*-----------------------------TO PRINT-------------------------------*/
template<typename datos, typename etiqueta>
void Grafo<datos, etiqueta>::toPrint(){
	cout << "      ";
	for(int i = 0; i < numeroVertices; i++)
		cout << setw(6) << i;
	cout << endl;
	for(int i = 0; i < numeroVertices; i++){
		cout << setw(6) << i;
		for(int j = 0; j < numeroVertices; j++)
			cout << setw(6) << arcos[i][j];
		cout << endl;
	}
}
/*-------------------------------PRIM---------------------------------*/
template<typename datos, typename etiqueta>
Grafo<datos, etiqueta>* Grafo<datos, etiqueta>::Prim(){
	Grafo<datos, etiqueta>* MST;
	Set<datos>* aux;
	bool encontroMinimo;
	etiqueta auxPeso;

	aux = vertices; //aux es el conjunto de los vertices no conectados.
	MST = new Grafo<datos, etiqueta>(false);
	MST->addVertice(iMin);
	MST->addVertice(jMin);
	MST->setArco(iMin, jMin, aristaMin);
	aux = aux->diferencia(MST->getVertices());
	while(!aux->esVacio()){ //mientras aux no sea vacio (haya vertices no conectados).
		encontroMinimo = false;
		auxPeso = 1;
		while(!encontroMinimo){
			for(int i = 0; !encontroMinimo && i < numeroVertices; i++){
				if(MST->getVertices()->pertenece(i + 1)){
					for(int j = 0; !encontroMinimo && j < numeroVertices; j++){
						if(arcos[i][j] == auxPeso && aux->pertenece(j+1)){	
							MST->addVertice(j+1);
							MST->setArco(i+1, j+1, arcos[i][j]);
							aux = aux->diferencia(MST->getVertices());
							encontroMinimo = true;
						}
					}
				}
			}
			auxPeso += 1;
		}
	}
	return MST;//Minimum Spanning Tree
}
/*-----------------------------DIJKSTRA-------------------------------*/
template<typename datos, typename etiqueta>
void Grafo<datos, etiqueta>::Dijkstra(int origen, int precedencias[numeroVertices]){
	Set<datos>* S; 				//vertices con camino mas corto conocido
	etiqueta D[numeroVertices];	//Arreglo con el costo del CMC a cada vertice
	etiqueta minimo;
	int w; 						//vertice que se va a agregar al conjunto S.
	
	S = new Set<datos>();
	S->agregar(origen);
	for(int i = 0; i < numeroVertices; i++){
		D[i] = arcos[origen][i];
		if(vertices->pertenece(i))
			precedencias[i] = origen;
		else
			precedencias[i] = INF;
	}
	precedencias[origen]= -1;
	//Esta completa la tabla de precedencias inicial.
		
	while(!vertices->diferencia(S)->esVacio()){  //mientras no se hayan encontrado los CMC a todos los destinos
		minimo = INF; 							 //el camino mas corto al comenzar cada iteracion es infinito.
		for(int i = 0; i < numeroVertices; i++){ //Busco el camino mas corto a algun destino
			if(vertices->diferencia(S)->pertenece(i) && D[i] < minimo){ //si i pertenece a los vertice no conectados y 
																		//el arreglo con el costo al CMC en i es menor que el minimo
				minimo = D[i];
				w = i;
			}
		}
		S->agregar(w); 							//Agrego el destino encontrado, el que tenia el CMC desde el origen.
		for(int i = 0; i < numeroVertices; i++) //Modifico las distancias desde el origen a los destinos, viendo si
		                                        //el nuevo camino posible es mas corto que el anterior.
			if(vertices->diferencia(S)->pertenece(i) && D[w] + arcos[w][i] < D[i]){
				D[i] = D[w] + arcos[w][i];
				precedencias[i] = w;
			}
	}
	
}
/*
int main(){
	Grafo<int, int>* graph = new Grafo<int, int>(false);
	int precedencias[5];
	graph->addVertice(0);
	graph->addVertice(1);
	graph->addVertice(2);
	graph->addVertice(3);
	graph->addVertice(4);
	graph->setArco(0, 1, 10);
	graph->setArco(0, 3, 30);
	graph->setArco(0, 4, 100);
	graph->setArco(1, 2, 50);
	graph->setArco(2, 4, 10);
	graph->setArco(3, 2, 20);
	graph->setArco(3, 4, 60);
	graph->Dijkstra(0, precedencias);
	for(int i = 0; i < 5; i++)
		cout << precedencias[i] << "    ";
	cout << endl;
	graph->toPrint();
	return 0;
}
*/
#endif
