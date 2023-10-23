#ifndef STRINGDIN_H_INCLUDED
#define STRINGDIN_H_INCLUDED
#include "boolean.h"

const int MAX = 80;
typedef char * stringDin;

void StrCrear(stringDin &str);

void StrDestruir(stringDin &str);

int StrLar(stringDin str);

void StrCop(stringDin &str,stringDin str2);

void Scan(stringDin &str);

void Print(stringDin str);

void convertirMayus(stringDin &s);

int convertirNumero(stringDin s);

boolean soloNumeros(stringDin s);

#endif // STRINGDIN_H_INCLUDED
