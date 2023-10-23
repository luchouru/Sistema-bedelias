#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include "stringDin.h"
#include "Escolaridad.h"
typedef struct{
    int cedula;
    stringDin nombre;
    stringDin apellido;
    int telefono;
    Secuencia escolaridad;
}Alumno;

//Carga un alumno por teclado. PRECONDICION: CI no existe
void CargaAlumno(Alumno &a, int ci);

//Despliega un alumno por pantalla
void DesplegarAlumno(Alumno a);

//Devuelve la cedula de un alumno
int GetCedula(Alumno a);

//Devuelve el nombre de un alumno
void GetNombre(Alumno a, stringDin &resu);

//Devuelve el apellido de un alumno
void GetApellido(Alumno a, stringDin &resu);

//Devuelve el telefono de un alumno
int GetTelefono(Alumno a);

//Devuelve la escolaridad de un alumno
Secuencia GetEscolaridad(Alumno a);

void modificarEscolaridad(Alumno &a, Curso c);

void ListarEscolaridadAlumno(Alumno a);
#endif // ALUMNO_H_INCLUDED
