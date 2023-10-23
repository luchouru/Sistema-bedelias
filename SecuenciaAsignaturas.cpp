#include "SecuenciaAsignaturas.h"

void CrearSecAsignaturas(secuenciaAsignaturas &secAsig){
    secAsig.tope = 0;
}

boolean VaciaSecAsignaturas(secuenciaAsignaturas secAsig){
    return (boolean)(secAsig.tope==0);
}

boolean LlenoSecAsignaturas(secuenciaAsignaturas secAsig){
    return (boolean)(secAsig.tope==N);
}

//Precondici�n: !VaciaSecAsignaturas(secAsig) y
boolean ExisteAsignatura(secuenciaAsignaturas secAsig, int numero){
    boolean encontre = FALSE;
    int i = 0;
    do{
        if(GetNumero(secAsig.arreglo[i]) == numero)
            encontre = TRUE;
        else
            i++;
    }while(i<N && !encontre);

    return encontre;
}

//Precondici�n: !VaciaSecAsignaturas(secAsig) y ExisteAsignatura(secAsigm, numero)
Asignatura BuscarAsignatura(secuenciaAsignaturas secAsig, int numero){
    boolean encontre = FALSE;
    int i = 0;
    do{
        if(GetNumero(secAsig.arreglo[i]) == numero)
            encontre = TRUE;
        else
            i++;
    }while(i<N && !encontre);

    return secAsig.arreglo[i];
}

void GetNombreAsignatura(secuenciaAsignaturas secAsig, int numero, stringDin &nombre){
    boolean encontre = FALSE;
    int i = 0;
    do{
        if(GetNumero(secAsig.arreglo[i]) == numero){
            encontre = TRUE;
            StrCrear(nombre);
            GetNombre(secAsig.arreglo[i], nombre);
        }
        else
            i++;
    }while(i<N && !encontre);
}

//Precondici�n: !LlenoSecAsignaturas(secAsig)
void InsertarAsignatura(secuenciaAsignaturas &secAsig, Asignatura asig){
    secAsig.arreglo[secAsig.tope] = asig;
    secAsig.tope++;
}

int LargoSecAsignaturas(secuenciaAsignaturas secAsig){
    return secAsig.tope;
}

//Precondici�n: !VaciaSecAsignaturas(secAsig)
void ListarAsignaturas(secuenciaAsignaturas secAsig){
    for(int i =0; i< secAsig.tope; i++)
        MostrarAsignatura(secAsig.arreglo[i]);
}
