#include "Previaturas.h"

//Crear un grafo de N vértices y sin aristas

void CrearMatrizPreviaturas(Previaturas &prev)
{
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            prev[i][j]=0;
}
//Agregar un arista entre dos vértices
void AgregarPreviatura(Previaturas &prev, int u, int v)
{
    //El primer parametro corresponde a la asignatura que tiene la previa, mientras que el segundo es la previa
    prev[u][v]=1;
}
//Determinar el grado de un vértice
int Grado(Previaturas prev, int v)
{
    int cont = 0;
    for (int j=0; j<N ; j++)
        if (prev[v][j]==1)
            cont++;
    return cont;
}

//Dados dos vértices, determinar si hay una arista que los une
boolean HayArista(Previaturas prev, int u, int v)
{
    return (boolean) (prev[u][v] == 1);
}

void DFS (Previaturas prev, int verticeActual, int v, boolean visitado[N])
{
    visitado[verticeActual] = TRUE;
    int j=0;
    while (j < N && !visitado[v])
    {
        if (prev[verticeActual][j])
            if (!visitado[j])
                DFS (prev, j, v, visitado);
        j++;
    }
}

boolean GeneranCiclo(Previaturas prev, int u, int v)
{
    boolean visitado[N];
    for (int i = 0; i<N; i++)
        visitado[i] = FALSE;

    DFS (prev, v, u, visitado);
    return visitado[u];
}

boolean ExisteCamino(Previaturas prev, int u, int v)
{
    boolean visitado[N];
    for (int i = 0; i<N; i++)
        visitado[i] = FALSE;

    DFS (prev, u, v, visitado);
    return visitado[v];
}

boolean TienePreviasAprobadas (Previaturas prev, Secuencia escolaridad, int nroCurso)
{
    boolean estanAprobadas = TRUE;
    int i=0;

    do
    {
        if(prev[nroCurso][i] == 1)
        {
            estanAprobadas = EstaCursoAprobado(escolaridad, i);
        }
        i++;
    }
    while(i<N && estanAprobadas);

    return estanAprobadas;
}

boolean TienePrevia(Previaturas prev, int nroCurso)
{
    return (boolean) (Grado(prev, nroCurso) > 0);
}

void DesplegarPreviaturas(Previaturas prev, int codAsignatura, secuenciaAsignaturas asignaturas)
{
    boolean visitado[N];
    boolean materiaInicial = TRUE;
    for (int i = 0; i<N; i++)
        visitado[i] = FALSE;

    DFS_DesplegarPrevias (prev, codAsignatura, visitado, asignaturas, materiaInicial);
}

void DFS_DesplegarPrevias (Previaturas prev, int codAsignatura, boolean visitado[N], secuenciaAsignaturas asignaturas, boolean &materiaInicial)
{
    visitado[codAsignatura] = TRUE;

    if(materiaInicial)
    {
        materiaInicial = FALSE;
        printf("\n**********************\n");
        MostrarNombreyCodAsignatura(BuscarAsignatura(asignaturas, codAsignatura));
        printf("\n\n**********************\n");
    }
    else
    {
        MostrarNombreyCodAsignatura(BuscarAsignatura(asignaturas, codAsignatura));
        printf("\n");
    }

    for(int j=0; j<N; j++)
    {
        if(prev[codAsignatura][j] == 1)
        {
            if(!visitado[j])
            {
                DFS_DesplegarPrevias(prev, j, visitado, asignaturas,materiaInicial);
            }
        }

    }

}
