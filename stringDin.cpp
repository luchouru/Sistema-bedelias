#include "stringDin.h"

void StrCrear (stringDin & s)
{
    s = new char[1];
    s[0] = '\0';
}
void StrDestruir (stringDin &s)
{
    delete [] s;
    s = NULL;
}
int StrLar (stringDin s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
void StrCop (stringDin &s1,stringDin s2)
{
    int i = 0;
    int Largo = StrLar(s2) + 1;
    delete [] s1;
    s1 = new char[Largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}


void Scan (stringDin &s)
{
    StrCrear(s);
    stringDin aux = new char[MAX];
    int i=0;
    char c;
    fflush(stdin);
    scanf ("%c", &c);
    while (c!= '\n' && i < MAX-1)
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    StrCop (s,aux);
    StrDestruir (aux);
}


void Print (stringDin s)
{
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

void convertirMayus(stringDin &s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] >= 'a' && s[i] <='z')
            s[i] = s[i] - 32;
        i++;
    }
}

int convertirNumero(stringDin s)
{
    int i = 0, digito, num = 0;

    while (s[i] != '\0')
    {
        digito = s[i] - 48;
        num = digito + 10 * num;
        i++;
    }
    return num;
}

boolean soloNumeros(stringDin s)
{
    int i = 0;
    boolean numeros = TRUE;
    while(numeros && s[i] != '\0')
    {
        if(!(s[i] >= '0' && s[i] <= '9'))
            numeros = FALSE;
        i++;
    }
    return numeros;
}
