#include "Fecha.h"

void ScanFecha(Fecha &fecha)
{
    printf("\nIngrese dia:");
    scanf("%d", &fecha.dia);
    printf("\nIngrese mes:");
    scanf("%d", &fecha.mes);
    printf("\nIngrese anio:");
    scanf("%d", &fecha.anio);
}

void CrearFecha(Fecha &fecha)
{
    ScanFecha(fecha);
    while(!EsFechaValida(fecha))
    {
        printf("\n La fecha ingresada es invalida.\n");
        ScanFecha(fecha);
    }
}

int GetDia(Fecha fecha)
{
    return fecha.dia;
}

int GetMes(Fecha fecha)
{
    return fecha.mes;
}

int GetAnio(Fecha fecha)
{
    return fecha.anio;
}

void MostrarFecha(Fecha fecha)
{
    printf ("%02d/%02d/%04d", fecha.dia, fecha.mes, fecha.anio);
}

boolean EsFechaValida(Fecha fecha)
{
    boolean esValida = FALSE;

    switch(fecha.mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(fecha.dia>0 && fecha.dia<=31)
            esValida = TRUE;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(fecha.dia>0 && fecha.dia<=30)
            esValida = TRUE;
        break;
    case 2:
        if(fecha.anio%4==0)
        {
            if(fecha.dia>0 && fecha.dia<=29)
                esValida = TRUE;
        }
        else
        {
            if(fecha.dia>0 && fecha.dia<=28)
                esValida = TRUE;
        }
        break;
    }
    return esValida;
}

// Retorna true si la primer fecha es mayor a la segunda
boolean EsFechaMayor(Fecha primerFecha, Fecha segundaFecha)
{
    boolean esMayor = FALSE;
    if(primerFecha.anio > segundaFecha.anio)
    {
        esMayor = TRUE;
    }
    else
    {
        if(primerFecha.anio == segundaFecha.anio && primerFecha.mes > segundaFecha.mes)
        {
            esMayor = TRUE;
        }
        else
        {
            if(primerFecha.anio == segundaFecha.anio && primerFecha.mes == segundaFecha.mes && primerFecha.dia > segundaFecha.dia)
            {
                esMayor = TRUE;
            }
        }
    }
    return esMayor;
}
