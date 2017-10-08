#include <iostream>
#ifndef PAGINA_H
#define PAGINA_H
using namespace std;

class Pagina{
	private:
		int maqOrigen, routOrigen;
		int maqDestino, routDestino;
        int tamanio;
        int nombre; //las paginas se identifican con un int
		string informacion; //las paginas tienen un limite de 40 caracteres

    public:
        Pagina(int size) {tamanio = size;};
        int getMaqOrigen(){return maqOrigen;};
        int getRoutOrigen(){return routOrigen;};
        int getMaqDestino(){return maqDestino;};
        int getRoutDestino(){return routDestino;};
        void setMaqOrigen(int maqFrom){maqOrigen = maqFrom;};
        void setRoutOrigen(int routFrom){routOrigen = routFrom;};
        void setMaqDestino(int maqTo){maqDestino = maqTo;};
        void setRoutDestino(int routTo){routDestino = routTo;};
        int getNombre() {return nombre;};
        int getTamanio() {return tamanio;};
        string getInformacion() {return informacion;}; //devuelve el la informacion de la pagina
        void setNombre(int id) {nombre = id;};
        void setTamanio(int size) {tamanio=size;};
        void setInformacion(string info) {informacion = info;};
        void toPrint();
};

void Pagina::toPrint(){
	cout << "Nombre: " << getNombre()
		 << " - Origen: " << getRoutOrigen() << '.' << getMaqOrigen()
		 << " - Destino: " << getRoutDestino() << '.' << getMaqDestino()
		 << " - Informacion: " << getInformacion()
		 << " - Tamanio: " << getTamanio() << endl;
}
#endif
