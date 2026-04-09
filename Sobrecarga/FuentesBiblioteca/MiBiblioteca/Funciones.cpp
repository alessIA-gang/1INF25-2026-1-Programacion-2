//
// Created by cueva.r on 27/03/2026.
//

#include "Funciones.h"
#include  <iostream>
#include  <fstream>
#include  <iomanip>
#include  <cstring>
#include  "Sobrecarga.h"
#include "Estructuras.h"

using namespace std;

void LeerAlumnos(const char *nom,Alumnos *arralumno) {
    int i=0;
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "Error al abrir el archivo de alumnos" << endl;
        exit(1);
    }
    while (true) {
        arch >> arralumno[i];
        if (arch.eof())break;
        i++;
    }
    arralumno[i].codigo=0;
}

void LeerCursos(const char *nom,Cursos *arrcurso) {
    int i=0;
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "Error al abrir el archivo de cursos" << endl;
        exit(1);
    }
    while (true) {
        arch >> arrcurso[i];
        if (arch.eof())break;
        i++;
    }
    arrcurso[i].codigo=nullptr;
}
void LeerMatricula(const char*nom,Alumnos *arralu,Cursos *arrcur){
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "Error al abrir el archivo de matricula" << endl;
        exit(1);
    }
    while (true) {
        Cursos auxcur;
        Alumnos auxalu;
        auxcur.codigo=leecadena(arch,10,',');
        if (arch.eof())break;
        arch >> auxalu.codigo;
        arch.get();
        int indcur = arrcur>=auxcur;
        int indalu = arralu<=auxalu;
        arrcur[indcur]+=arralu[indalu];

    }

}

void ImprimeCursos(const char*nom,Cursos *arrcur) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout << "Error al abrir el archivo de impresion cursos" << endl;
        exit(1);
    }
    for (int i=0;arrcur[i].codigo!=nullptr;i++) {
        arch << arrcur[i];
        arch << endl;
    }



}