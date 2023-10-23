#include "Menu.h"
#include "stdlib.h"

int main()
{
    Diccionario alumnos;
    Make(alumnos);

    secuenciaAsignaturas asignaturas;
    CrearSecAsignaturas(asignaturas);

    Previaturas previatura;
    CrearMatrizPreviaturas(previatura);
    Secuencia escolaridadAlumno;

    int opcion = 0;

    do
    {
        system("cls");
        printf("\n\nMENU PRINCIPAL");
        MostrarMenuPrincipal(opcion);
        switch (opcion)
        {
        case 1:
            system("cls");
            RegistraAsignatura(asignaturas);
            break;
        case 2:
            system("cls");
            ListaAsignaturas(asignaturas);
            break;
        case 3:
            system("cls");
            AgregarPreviatura(asignaturas, previatura);
            break;
        case 4:
            system("cls");
            ListarPrevia(asignaturas,previatura);
            break;
        case 5:
            system("cls");
            InscribirAlumno(alumnos);
            break;
        case 6:
            system("cls");
            AgregarAsignaturaAEscolaridad(asignaturas,alumnos,previatura);
            break;
        case 7:
            system("cls");
            ListarAlumno(alumnos);
            break;
        case 8:
            system("cls");
            ListarEscolaridad(alumnos);
            break;
        case 9:
            break;
        default:
            printf("\nOpcion incorrecta\n\nPresione enter para continuar");
            fflush(stdin);
            getchar();
            break;
        }
    }
    while (opcion !=9);
}
