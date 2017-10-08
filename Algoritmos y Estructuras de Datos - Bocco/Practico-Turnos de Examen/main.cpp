#include <cstdlib>
#include <iostream>

using namespace std;

#include "Turno.h"

int main(int argc, char *argv[])
{
    Fecha f;
    f.setFecha(12,4,2012);
    f.imprime();
    Alumno a;
    a.setAlumno("Juan Lopez",32112009);
    a.imprime();
    Materia m;
    m.setMateria("Alg. y Estr. Datos",7410);
    m.imprime();
    Turno t;
//    Examen e;
//    e.setExamen(Examen(Fecha(2,3,2001),Materia("AyED",7410),Alumno("Ana Castro",31001234),7));
//    t.addExamen(e);
    t.addExamen(Examen(Fecha(2,3,2001),Materia("AyED",7410),Alumno("Ana Castro",31001234),7));
    t.addExamen(Examen(Fecha(21,7,2007),Materia("Mat II",2110),Alumno("Luis Amaya",33981834),2));
    Examen e;
    e.setExamen(Fecha(2,12,2000),Materia("Informatica",2422),Alumno("Ana Castro",31001234),8);
    t.addExamen(e);
    t.imprime();
    e.setExamen(Fecha(24,11,2000),Materia("Informatica",2422),Alumno("Ana Castro",31001234),1);
    t.addExamen(e);
    t.imprime();
    cout<<" El mejor examen fue" << t.bestExamen().asString() << endl;
    cout<<" El ultimo examen fue" << t.lastExamen().asString() << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
