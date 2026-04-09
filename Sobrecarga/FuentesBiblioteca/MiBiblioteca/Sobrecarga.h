//
// Created by cueva.r on 25/03/2026.
//

#ifndef FUENTESBIBLIOTECA_SOBRECARGA_H
#define FUENTESBIBLIOTECA_SOBRECARGA_H
#include <fstream>
#include "Estructuras.h"
using namespace std;

char * leecadena(ifstream &arch,int max,char carlim);
void operator>> (ifstream &arch,Cursos &curso);
void operator >> (ifstream &arch,Alumnos &alumno);
bool operator>(Cursos curso,char* codcur);
bool operator > (Alumnos alum,int codalu);
int operator>=(Cursos *arrcur,Cursos curso);
int operator<=(Alumnos *arralu,const Alumnos codalu);
void operator ++(Cursos &cur,int a);
void operator ++(Cursos &cur,int a);
void operator<<(ofstream &arch,Cursos &);
void operator +=(Cursos &cur, Alumnos &alu);
#endif //FUENTESBIBLIOTECA_SOBRECARGA_H