#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED
#include "Alumno.h"

const int B = 150;

typedef struct nodoL{
    Alumno a;
    nodoL * sig;
}nodoAlumno;

typedef nodoAlumno * lista;
typedef lista Diccionario[B];

//Crea un diccionario vac�o.
void Make(Diccionario &d);

//Determina si en el diccionario existe un elemento con la clave especificada.
boolean Member(Diccionario d, int clave);

//Dada la clave de un elemento devuelve el elemento con dicha clave
//Precondici�n: el elemento es miembro del diccionario.
Alumno Find(Diccionario d, int clave);

//Inserta un elemento de tipo T en el diccionario.
//Precondici�n: el elemento a insertar no es miembro del diccionario.
void Insert(Diccionario &d, Alumno a);

//Sustituye el viejo elemento de tipo T en el diccionario por el nuevo elemento.
//Precondici�n: el elemento a sustituir es miembro del diccionario.
void Modify(Diccionario &d, Alumno a);

//Muestra por pantalla los datos de un alumno
//PRECONDICION: el alumno existe
void ListarAlumno(Diccionario d, int clave);

//Agrega un curso a la escolaridad del alumno
//PRECONDICION: el alumno existe
void AgregarCursoAlumno(Diccionario &d, Curso c, Alumno a);

#endif // ALUMNOS_H_INCLUDED
