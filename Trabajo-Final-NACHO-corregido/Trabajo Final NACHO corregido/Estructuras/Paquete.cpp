#include <iostream>
#ifndef PAQUETE_H
#define PAQUETE_H
using namespace std;

class Paquete{
	private:
		int orden;
		int toRout, toMac, fromRout, fromMac; //Guardan la direccion de origen y de destino del paquete.
		char info; //Guarda parte de la informacion de la pagina.
		int pageID, pageSize; //Nombre y tamanio de la pagina de la cual forman parte estos paquetes.
	public:
		Paquete(){orden = toRout = toMac = fromRout = fromMac = pageID = pageSize = 0;};
		void setOrden(int ord){orden = ord;};
		void setInfo(char inf){info = inf;};
		void setDestino(int maq, int rout){toRout = rout; toMac = maq;};
		void setOrigen(int maq, int rout){fromRout = rout; fromMac = maq;};
		void setID(int ID){pageID = ID;};
		void setPageSize(int Size){pageSize = Size;};
		int getOrden(){return orden;};
		char getInfo(){return info;};
		int getRoutDestino(){return toRout;};
		int getMaqDestino(){return toMac;};
		int getRoutOrigen(){return fromRout;};
		int getMaqOrigen(){return fromMac;};
		int getID(){return pageID;};
		int getPageSize(){return pageSize;};
};
#endif
