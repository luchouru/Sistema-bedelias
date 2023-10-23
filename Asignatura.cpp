#include "Asignatura.h"

void CrearAsignatura(Asignatura &asig, stringDin nombre, int horas, int numero)
{
    StrCrear(asig.nombre);
    StrCop(asig.nombre, nombre);
    asig.horas = horas;
    asig.numero = numero;
}

void MostrarAsignatura(Asignatura asig)
{
    MostrarNombreyCodAsignatura(asig);
    printf("\nHoras:\t%d", asig.horas);
    printf("\n");
}

void MostrarNombreyCodAsignatura(Asignatura asig)
{
    printf("\nNombre:\t");
    Print(asig.nombre);
    printf("\nNumero:\t%d", asig.numero);
}

void GetNombre(Asignatura asig, stringDin &nombre)
{
    StrCrear(nombre);
    StrCop(nombre, asig.nombre);
}

int GetHoras(Asignatura asig)
{
    return asig.horas;
}

int GetNumero(Asignatura asig)
{
    return asig.numero;
}
