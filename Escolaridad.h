#ifndef ESCOLARIDAD_H_INCLUDED
#define ESCOLARIDAD_H_INCLUDED

#include "Curso.h"

typedef struct nodoA
{
    Curso info;
    nodoA * sig;
} nodo;

typedef nodo * Lista;

typedef struct
{
    Lista primero;
    Lista Ultimo;
} Secuencia;

void Crear(Secuencia &l);
void InsBack(Secuencia &l, Curso curso);
boolean EsVacia(Secuencia l);
//Precondici�n: la secuencia no es vac�a.
Curso Ultimo (Secuencia l);
int Largo(Secuencia l);

void ListarEscolaridad (Secuencia l);
boolean EstaCursoAprobado(Secuencia l, int numero);

#endif // ESCOLARIDAD_H_INCLUDED
