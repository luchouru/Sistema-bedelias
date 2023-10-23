#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "stdio.h"
#include "alumnos.h"
#include "Previaturas.h"

//despliega por pantalla el menu de opciones
void MostrarMenuPrincipal(int &op);

void RegistraAsignatura(secuenciaAsignaturas &asignaturas);
void ListaAsignaturas(secuenciaAsignaturas asignaturas);
void AgregarPreviatura(secuenciaAsignaturas asignaturas, Previaturas &previatura);
void ListarPrevia(secuenciaAsignaturas asignaturas, Previaturas previatura);
void InscribirAlumno(Diccionario &alumnos);
void AgregarAsignaturaAEscolaridad(secuenciaAsignaturas asignaturas, Diccionario &alumnos, Previaturas previatura);
void ListarAlumno(Diccionario alumnos);
void ListarEscolaridad(Diccionario alumnos);

#endif // MENU_H_INCLUDED
