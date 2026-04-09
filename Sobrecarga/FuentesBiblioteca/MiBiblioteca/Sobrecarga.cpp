//
// Created by cueva.r on 25/03/2026.
//
#include  <iostream>
#include  <fstream>
#include  <iomanip>
#include  <cstring>
#include "Estructuras.h"
#include "Sobrecarga.h"

using namespace std;

//INF263,Algoritmia,3.75,35030611,INGA_FLORES_CESAR_ADOLFO
void operator>> (ifstream &arch,Cursos &curso) {
    char c;
    int numero;
    curso.codigo= leecadena(arch,10,',');
    curso.nombre= leecadena(arch,100,',');
    arch >> curso.creditos >> c >> numero >>c;
    curso.docente = leecadena(arch,100,'\n');
    curso.numpresencial=0;
    curso.numsemipresencial=0;
    curso.numvirtual=0;
    curso.tipofinal=nullptr;
}
// 202111260,GORDILLO/CASTRO/RONAL,P
// 202111397,ZEVALLOS/PRADO/RICARDO,S
void operator >> (ifstream &arch,Alumnos &alumno) {
    char c,*nombre;
    arch>>alumno.codigo>>c;
    alumno.nombre=leecadena(arch,50,',');
    arch >> alumno.tipo;
}

bool operator>(Cursos curso,char* codcur) {
    if (strcmp(curso.codigo,codcur)==0)
        return true;
    return false;
}

bool operator > (Alumnos alum,int codalu) {
    if (alum.codigo==codalu)
        return true;
    else
        return false;
}
int operator>=(Cursos *arrcur,Cursos curso) {
    for (int i=0;arrcur[i].codigo!=nullptr;i++)
        if (arrcur[i]>curso.codigo)
            return i;
    return -1;
}
int operator<=(Alumnos *arralu,const Alumnos codalu) {
    for (int i=0;arralu[i].codigo!=0;i++)
        if (arralu[i]>codalu.codigo)
            return i;
    return -1;
}
void operator ++(Cursos &cur,int a) {
    int total= cur.numpresencial+cur.numsemipresencial+cur.numvirtual;
    double porc = 1.0*cur.numpresencial/total;
    cur.tipofinal = new char[50];
    if (porc >=0.5)
        strcpy(cur.tipofinal,"La clase se dictara en aula");
    else
        strcpy(cur.tipofinal,"La clase se dictara 100% virtual");
}

void operator +=(Cursos &cur, Alumnos &alu) {
    if (alu.tipo=='P') {
        cur.presencial[cur.numpresencial]=alu;
        cur.numpresencial++;
    }
    if (alu.tipo=='S') {
        cur.semipresencial[cur.numsemipresencial]=alu;
        cur.numsemipresencial++;
    }
    if (alu.tipo=='V') {
        cur.vvirtual[cur.numvirtual]=alu;
        cur.numvirtual++;
    }
}

void operator<<(ofstream &arch,Cursos &cur) {
    arch << setw(10) << cur.codigo << setw(50)<<cur.nombre << endl;
    arch << cur.docente << endl;
    arch << "Presenciales: "<<cur.numpresencial << endl;
    arch << "Semipresencial: "<<cur.numsemipresencial << endl;
    arch << "Virtuales: "<<cur.numvirtual << endl;
    cur++;
    arch << cur.tipofinal << endl;
}

///////////////////////////////////////////////////////

char * leecadena(ifstream &arch,int max,char carlim) {
    char buff[max],*cad;
    arch.getline(buff,max,carlim);
    if (arch.eof()) return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

