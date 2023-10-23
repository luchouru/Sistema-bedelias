#ifndef PREVIATURAS_H_INCLUDED
#define PREVIATURAS_H_INCLUDED

#include "SecuenciaAsignaturas.h"
#include "Escolaridad.h"

typedef int Previaturas[N][N];

void CrearMatrizPreviaturas(Previaturas &previaturas);
void AgregarPreviatura(Previaturas &previaturas, int u, int v);

int Grado(Previaturas &previaturas, int v);
boolean HayArista(Previaturas previaturas, int u, int v);

void DFS (Previaturas prev, int verticeActual, int v, boolean visitado[N]);
boolean GeneranCiclo(Previaturas prev, int u, int v);
boolean ExisteCamino(Previaturas prev, int u, int v);

boolean TienePreviasAprobadas (Previaturas prev, Secuencia escolaridad, int nroCurso);
boolean TienePrevia(Previaturas prev, int nroCurso);

void DesplegarPreviaturas(Previaturas prev, int codAsignatura, secuenciaAsignaturas asignaturas);
void DFS_DesplegarPrevias (Previaturas prev, int codAsignatura, boolean visitado[N], secuenciaAsignaturas asignaturas, boolean &materiaInicial);
#endif // PREVIATURAS_H_INCLUDED
