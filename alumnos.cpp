#include "alumnos.h"

int h(int e)
{
    return e % B;
}

void CrearL(lista &l)
{
    l = NULL;
}

void Make(Diccionario &d)
{
    for(int i = 0; i < B; i++)
        CrearL(d[i]);
}

boolean Member(Diccionario d, int clave)
{
    int cubeta = h(clave);
    lista aux = d[cubeta];
    boolean existe = FALSE;
    while(aux != NULL && !existe)
    {
        if(clave == GetCedula(aux->a))
            existe = TRUE;
        else aux = aux->sig;
    }
    return existe;
}

Alumno Find(Diccionario d, int clave)
{
    int cubeta = h(clave);
    lista aux = d[cubeta];
    while(GetCedula(aux->a) != clave)
        aux = aux->sig;
    return aux->a;
}

void InsFront(lista &l, Alumno a)
{
    lista nuevo = new nodoAlumno;
    nuevo->a = a;
    nuevo->sig = l;
    l = nuevo;
}

void Insert(Diccionario &d, Alumno a)
{
    int clave = GetCedula(a);
    int cubeta = h(clave);
    InsFront(d[cubeta],a);
}

void Modify(Diccionario &d, Alumno a)
{
    int clave = GetCedula(a);
    int cubeta = h(clave);
    lista aux = d[cubeta];
    while(GetCedula(aux->a) != GetCedula(a))
        aux = aux->sig;
    aux->a = a;
}

void ListarAlumno(Diccionario d, int clave)
{
    DesplegarAlumno(Find(d,clave));
}

//Agrega un curso a la escolaridad del alumno
//PRECONDICION: el alumno existe
void AgregarCursoAlumno(Diccionario &d, Curso c, Alumno a)
{
    modificarEscolaridad(a,c);
    Modify(d,a);
}
