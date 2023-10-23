#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include "stringDin.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

int GetDia(Fecha fecha);

int GetMes(Fecha fecha);

int GetAnio(Fecha fecha);

void MostrarFecha(Fecha fecha);

void ScanFecha(Fecha &fecha);

void CrearFecha(Fecha &fecha);

boolean EsFechaValida(Fecha fecha);

// Retorna true si la primer fecha es mayor a la segunda
boolean EsFechaMayor(Fecha primerFecha, Fecha segundaFecha);


#endif // FECHA_H_INCLUDED
