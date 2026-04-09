#include "MiBiblioteca/Funciones.h"


int main() {
    Alumnos arrAlumno[100];
    Cursos arrCurso[10];
    LeerAlumnos("Alumnos.csv",arrAlumno);
    LeerCursos("Cursos.csv",arrCurso);
    LeerMatricula("Matricula.csv",arrAlumno,arrCurso);
    ImprimeCursos("reporte.txt",arrCurso);

    return 0;
}