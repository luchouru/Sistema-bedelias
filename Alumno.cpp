#include "Alumno.h"

void CargaAlumno(Alumno &a, int ci)
{
    a.cedula = ci;
    printf("Ingrese nombre: ");
    StrCrear(a.nombre);
    Scan(a.nombre);
    printf("Ingrese apellido: ");
    StrCrear(a.apellido);
    Scan(a.apellido);
    printf("Ingrese telefono: ");
    fflush(stdin);
    scanf("%d",&a.telefono);
    Crear(a.escolaridad);
}

void DesplegarAlumno(Alumno a)
{
    printf("Cedula: %d\n",a.cedula);
    printf("Nombre: ");
    Print(a.nombre);
    printf("\nApellido: ");
    Print(a.apellido);
    printf("\nTelefono: %d\n",a.telefono);
    printf("Cursos registrados: ");
    printf("%d",Largo(a.escolaridad));
}

int GetCedula(Alumno a)
{
    return a.cedula;
}

void GetNombre(Alumno a, stringDin &resu)
{
    StrCrear(resu);
    StrCop(resu,a.nombre);
}

void GetApellido(Alumno a, stringDin &resu)
{
    StrCop(resu,a.apellido);
}

int GetTelefono(Alumno a)
{
    return a.telefono;
}

Secuencia GetEscolaridad(Alumno a)
{
    return a.escolaridad;
}

void modificarEscolaridad(Alumno &a, Curso c)
{
    InsBack(a.escolaridad,c);
}

void ListarEscolaridadAlumno(Alumno a)
{
    ListarEscolaridad(a.escolaridad);
}
