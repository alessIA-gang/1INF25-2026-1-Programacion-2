//
// Created by cueva.r on 27/03/2026.
//

#ifndef FUENTESBIBLIOTECA_FUNCIONES_H
#define FUENTESBIBLIOTECA_FUNCIONES_H
#include "Estructuras.h"
    void LeerAlumnos(const char *nom,Alumnos *arralumno);
    void LeerCursos(const char *nom,Cursos *arrcurso);
    void ImprimeCursos(const char*nom,Cursos *arrcur);
    void LeerMatricula(const char*nom,Alumnos *arralu,Cursos *arrcur);
#endif //FUENTESBIBLIOTECA_FUNCIONES_H