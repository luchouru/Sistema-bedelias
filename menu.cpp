#include "menu.h"

void MostrarMenuPrincipal(int &op)
{
    printf("\n\n(1)- Registrar asignatura.");
    printf("\n(2)- Listar asignaturas");
    printf("\n(3)- Agregar previatura.");
    printf("\n(4)- Listar previa.");
    printf("\n(5)- Inscribir alumno.");
    printf("\n(6)- Agregar asignatura a escolaridad.");
    printf("\n(7)- Listar alumno.");
    printf("\n(8)- Listar escolaridad.");
    printf("\n(9)- Salir.");
    printf("\n\nIngrese una opcion: ");
    scanf("%d",&op);
}

void RegistraAsignatura(secuenciaAsignaturas &asignaturas)
{
    stringDin nombreAsignaturaNueva, hs;
    StrCrear(hs);
    int horas;

    printf("\t\tREGISTRAR NUEVA ASIGNATURA\n\n");
    if(!LlenoSecAsignaturas(asignaturas))
    {
        Asignatura asig;
        printf("\nNombre: ");
        StrCrear(nombreAsignaturaNueva);
        Scan(nombreAsignaturaNueva);
        do
        {
            printf("Cantidad de horas: ");
            Scan(hs);
        }
        while(!soloNumeros(hs));
        horas = convertirNumero(hs);
        CrearAsignatura(asig,nombreAsignaturaNueva,horas,LargoSecAsignaturas(asignaturas));
        InsertarAsignatura(asignaturas,asig);
        printf("\nAsignatura registrada correctamente.\n");
    }
    else printf("\nMaximo de asignaturas registradas en el sistema.\n");
    printf("\nPresione enter para continuar.");
    fflush(stdin);
    getchar();
}

void ListaAsignaturas(secuenciaAsignaturas asignaturas)
{
    printf("\t\tLISTADO DE ASIGNATURAS\n\n");
    if(!VaciaSecAsignaturas(asignaturas))
    {
        ListarAsignaturas(asignaturas);
    }
    else printf("\nNo hay asignaturas registradas en el sistema.\n");
    printf("\nPresione enter para continuar.");
    fflush(stdin);
    getchar();
}

void AgregarPreviatura(secuenciaAsignaturas asignaturas, Previaturas &previatura)
{
    if(!VaciaSecAsignaturas(asignaturas))
    {
        int asig1, asig2;

        printf("\t\tREGISTRAR INGRESO DE NUEVA PREVIA\n\n");
        printf("\nComplete los siguientes datos para definir la previa:\n");
        fflush(stdin);

        printf("\nNumero de la asignatura previa:\t");
        fflush(stdin);
        scanf("%d", &asig1);


        printf("\nNumero de la asignatura que tiene la previa:");
        fflush(stdin);
        scanf("%d", &asig2);


        if(ExisteAsignatura(asignaturas, asig1))
        {
            if(ExisteAsignatura(asignaturas, asig2))
            {
                if(asig1 != asig2)
                {
                    if(HayArista(previatura,asig2,asig1))
                    {
                        printf("\nLa previatura ya existe en el sistema.\n");
                    }
                    else
                    {
                        if(!ExisteCamino(previatura,asig2, asig1))
                        {
                            if(!GeneranCiclo(previatura, asig2, asig1))
                            {
                                AgregarPreviatura(previatura, asig2, asig1);
                                printf("\nSe asigno la previa correctamente.\n", asig2);
                            }
                            else
                                printf("\nLas asignaturas generan un ciclo.\n", asig2);
                        }
                        else
                        {
                            printf("\nLa asignatura ya es previa indirectamente.\n", asig2);
                        }

                    }

                }
                else
                    printf("\nLas asignaturas son iguales, una asignatura no puede ser previa de si misma.\n");
            }
            else
                printf("\nNo existe la asignatura con el numero %d.\n", asig2);
        }
        else
            printf("\nNo existe la asignatura con el numero %d.\n", asig1);

    }
    else printf("\nNo hay asignaturas registradas en el sistema.\n");
    printf("\nPresione enter para continuar.");
    fflush(stdin);
    getchar();
}

void ListarPrevia(secuenciaAsignaturas asignaturas, Previaturas previatura)
{
    int prev1;
    printf("\t\tLISTADO DE PREVIAS\n\n");
    if(!VaciaSecAsignaturas(asignaturas))
    {
        printf("\nIngrese codigo de la asignatura para desplegar previaturas: ");
        fflush(stdin);
        scanf("%d",&prev1);
        if(ExisteAsignatura(asignaturas,prev1))
        {
            if(TienePrevia(previatura,prev1))
            {
                printf("\nMostrando previas de la materia:");
                DesplegarPreviaturas(previatura,prev1, asignaturas);
            }
            else printf("\nLa asignatura no tiene previaturas.\n");
        }
        else printf("\nCodigo de asignatura incorrecto.\n");
    }
    else printf("\nNo hay asignaturas registradas en el sistema.\n");
    printf("\nPresione enter para continuar.");
    fflush(stdin);
    getchar();
}

void InscribirAlumno(Diccionario &alumnos)
{
    stringDin cedula;
    StrCrear(cedula);
    int ci;
    Alumno alumno;
    printf("\t\tINSCRIBIR ALUMNO\n\n");
    do{
        printf("\nIngrese cedula: ");
        Scan(cedula);
    }while(!soloNumeros(cedula));
    ci = convertirNumero(cedula);
    if(!Member(alumnos,ci))
    {
        CargaAlumno(alumno,ci);
        Insert(alumnos,alumno);
        printf("\nAlumno inscrito correctamente.\n");
    }
    else printf("\nEl alumno ya se encuentra registrado en el sistema.\n");
    printf("\nPresione enter para continuar.");
    fflush(stdin);
    getchar();
}

void AgregarAsignaturaAEscolaridad(secuenciaAsignaturas asignaturas, Diccionario &alumnos, Previaturas previatura)
{
    int ci, nroAsignatura, calificacion;
    stringDin cedula;
    StrCrear(cedula);
    printf("\t\tAGREGAR ASIGNATURA A ESCOLARIDAD\n\n");
    if(!VaciaSecAsignaturas(asignaturas))
    {
        do
        {
            printf("Ingrese cedula del alumno:");
            Scan(cedula);
        }
        while(!soloNumeros(cedula));
        ci = convertirNumero(cedula);
        if(Member(alumnos,ci))
        {
            printf("Ingrese el numero de asignatura:");
            fflush(stdin);
            scanf("%d",&nroAsignatura);
            if(ExisteAsignatura(asignaturas,nroAsignatura))
            {
                Alumno alumnoAux = Find(alumnos,ci);
                if(!EstaCursoAprobado(GetEscolaridad(alumnoAux),nroAsignatura))
                {
                    Secuencia escolaridadAlumno = GetEscolaridad(alumnoAux);
                    if(!TienePrevia(previatura,nroAsignatura) || TienePreviasAprobadas(previatura,escolaridadAlumno,nroAsignatura))
                    {
                        Fecha fechaFinalizacion;
                        printf("\nIngrese fecha de finalizacion del curso");
                        CrearFecha(fechaFinalizacion);
                        if(EsVacia(escolaridadAlumno) || EsFechaMayor(fechaFinalizacion,GetFechaFinalizacion(Ultimo(escolaridadAlumno))))
                        {
                            do
                            {
                                printf("\nIngrese la calificacion obtenida (0 a 12):");
                                scanf("%d", &calificacion);
                            }
                            while(calificacion < 0 || calificacion > 12);
                            Curso curso;
                            stringDin nombreAsignatura;
                            GetNombre(BuscarAsignatura(asignaturas,nroAsignatura),nombreAsignatura);
                            CreaCurso(curso,nroAsignatura,nombreAsignatura,fechaFinalizacion,calificacion);
                            AgregarCursoAlumno(alumnos,curso,alumnoAux);
                            printf("\nAsignatura agregada correctamente.\n");
                        }
                        else printf("\nLa fecha de finalizacion del curso debe ser mayor a la ultima ingresada.\n");
                    }
                    else printf("\nLa asignatura no tiene alguna de las previas inmediatas aprobadas.\n");
                }
                else printf("\nLa asignatura ya se encuentra aprobada para este alumno.\n");
            }
            else printf("\nCodigo de asignatura incorrecto.\n");
        }
        else printf("\nEl alumno no se encuentra registrado en el sistema.\n");
    }
    else printf("\nNo hay asignaturas registradas en el sistema.\n");
    printf("\nPresione enter para continuar.");
    fflush(stdin);
    getchar();

}

void ListarAlumno(Diccionario alumnos)
{
    int ci;
    stringDin cedula;
    StrCrear(cedula);
    printf("\t\tLISTAR ALUMNO\n\n");
    do{
        printf("\nIngrese cedula: ");
        Scan(cedula);
    }while(!soloNumeros(cedula));
    ci = convertirNumero(cedula);
    if(Member(alumnos,ci))
    {
        ListarAlumno(alumnos,ci);
    }
    else printf("\nEl alumno no se encuentra registrado en el sistema.\n");
    printf("\nPresione enter para continuar.");
    fflush(stdin);
    getchar();
}

void ListarEscolaridad(Diccionario alumnos)
{
    int ci;
    stringDin cedula;
    StrCrear(cedula);
    printf("\t\tLISTAR ESCOLARIDAD\n\n");
    do{
        printf("Ingrese cedula para listar escolaridad: ");
        Scan(cedula);
    }while(!soloNumeros(cedula));
    ci = convertirNumero(cedula);
    if(Member(alumnos,ci))
    {
        Alumno alumno = Find(alumnos,ci);
        Secuencia escolaridadAlumnoAux = GetEscolaridad(alumno);
        if(!EsVacia(escolaridadAlumnoAux))
        {
            ListarEscolaridadAlumno(alumno);
        }
        else printf("\nEl alumno no tiene asignaturas cursadas.\n");
    }
    else printf("\nEl alumno no se encuentra registrado en el sistema.\n");
    printf("\nPresione enter para continuar.");
    fflush(stdin);
    getchar();
}




