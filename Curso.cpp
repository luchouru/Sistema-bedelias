#include "Curso.h"

void CreaCurso (Curso &curso, int numero, stringDin nombreAsignatura, Fecha fechaFinalizacion, int calificacion)
{
    curso.numero = numero;
    StrCrear(curso.nombreAsignatura);
    StrCop(curso.nombreAsignatura, nombreAsignatura);
    curso.fechaFinalizacion = fechaFinalizacion;
    curso.calificacion = calificacion;
}

int GetNumero (Curso curso)
{
    return curso.numero;
}
void GetNombreAsignaturaCurso (Curso curso, stringDin &nombreAsignatura)
{
    StrCrear(nombreAsignatura);
    StrCop(nombreAsignatura, curso.nombreAsignatura);
}
Fecha GetFechaFinalizacion (Curso curso)
{
    return curso.fechaFinalizacion;
}
int GetCalificacion (Curso curso)
{
    return curso.calificacion;
}

void MostrarCurso(Curso curso){
        stringDin nombreAsignatura;
        printf("Numero: %d\n", GetNumero(curso));
        printf("Nombre:");
        GetNombreAsignaturaCurso(curso, nombreAsignatura);
        Print(nombreAsignatura);
        printf("\n");
        printf("Fecha de finalizacion:");
        MostrarFecha(GetFechaFinalizacion(curso));
        printf("\n");
        printf("Calificacion: %d\n", GetCalificacion(curso));
        GetCalificacion(curso) >= 6 ? printf("Aprobado") : printf("No aprobado");
}
