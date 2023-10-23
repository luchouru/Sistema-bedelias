#include "Escolaridad.h"

void Crear(Secuencia &l)
{
    l.primero = NULL;
    l.Ultimo = NULL;
}

void InsBack(Secuencia &l, Curso curso)
{
    Lista nuevo = new nodo;
    nuevo->info = curso;
    nuevo->sig = NULL;

    if(l.Ultimo == NULL)
    {
        l.primero = nuevo;
        l.Ultimo = nuevo;
    }
    else
    {
        l.Ultimo->sig = nuevo;
        l.Ultimo = nuevo;
    }
}
boolean EsVacia(Secuencia l)
{
    return (boolean) (l.primero == NULL && l.Ultimo == NULL);
}
//Precondici�n: la secuencia no es vac�a.
Curso Ultimo (Secuencia l)
{
    return l.Ultimo->info;
}

int Largo(Secuencia l)
{
    Lista aux = l.primero;
    int lar = 0;
    while(aux != NULL)
    {
        lar++;
        aux = aux ->sig;
    }

    return lar;
}

void ListarEscolaridad (Secuencia l)
{
    Lista aux = l.primero;
    while(aux != NULL)
    {
        printf("\n");
        Curso curso = aux->info;
        MostrarCurso(curso);
        aux = aux->sig;
    }

}


boolean EstaCursoAprobado(Secuencia l, int numero)
{
    Lista aux = l.primero;
    boolean aprobado = FALSE;
    while(aux != NULL && !aprobado)
    {
        if(GetNumero(aux->info) == numero)
        {
            aprobado = (boolean) (GetCalificacion(aux->info)>=6);
        }
        aux = aux->sig;
    }
    return aprobado;
}
