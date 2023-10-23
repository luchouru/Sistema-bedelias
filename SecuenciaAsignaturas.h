#ifndef ASIGNATURAS_H_INCLUDED
#define ASIGNATURAS_H_INCLUDED

#include "Asignatura.h"

const int N = 30;

typedef Asignatura arregloAsignaturas[N];

typedef struct {
    arregloAsignaturas arreglo;
    int tope;
} secuenciaAsignaturas;

void CrearSecAsignaturas(secuenciaAsignaturas &secAsig);
boolean VaciaSecAsignaturas(secuenciaAsignaturas secAsig);
boolean LlenoSecAsignaturas(secuenciaAsignaturas secAsig);
Asignatura BuscarAsignatura(secuenciaAsignaturas secAsig, int numero);
void GetNombreAsignatura(secuenciaAsignaturas secAsig, int numero, stringDin &nombre);
boolean ExisteAsignatura(secuenciaAsignaturas secAsig, int numero);
void InsertarAsignatura(secuenciaAsignaturas &secAsig, Asignatura asig);
int LargoSecAsignaturas(secuenciaAsignaturas secAsig);

void ListarAsignaturas(secuenciaAsignaturas secAsig);

#endif // ASIGNATURAS_H_INCLUDED
