#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED

#include "stringDin.h"
#include "Fecha.h"

typedef struct
{
    int numero;
    stringDin nombreAsignatura;
    Fecha fechaFinalizacion;
    int calificacion;
} Curso;

void CreaCurso (Curso &curso, int numero, stringDin nombreAsignatura, Fecha fechaFinalizacion, int calificacion);

int GetNumero (Curso curso);
void GetNombreAsignaturaCurso (Curso curso, stringDin &nombreAsignatura);
Fecha GetFechaFinalizacion (Curso curso);
int GetCalificacion (Curso curso);
void MostrarCurso(Curso curso);
#endif // CURSO_H_INCLUDED
