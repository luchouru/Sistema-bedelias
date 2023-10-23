#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED
#include "Fecha.h"

typedef struct
{
    stringDin nombre;
    int horas;
    int numero;
} Asignatura;

void CrearAsignatura(Asignatura &asig, stringDin nombre, int horas, int numero);

void MostrarAsignatura(Asignatura asig);
void MostrarNombreyCodAsignatura(Asignatura asig);

void GetNombre(Asignatura asig, stringDin &nombre);
int GetHoras(Asignatura asig);
int GetNumero(Asignatura asig);


#endif // ASIGNATURA_H_INCLUDED
