#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashing.h"

#define TAM_LINEAL 250
#define TAM_CLAVE 256

int main() {
//  int pos;
  myreg tabla_lineal[TAM_LINEAL];
  myreg tabla_clave[TAM_CLAVE];

  h_init(tabla_lineal, TAM_LINEAL);
  h_insert_fichero("coches.csv", tabla_lineal, TAM_LINEAL, "lineal");
  h_show(tabla_lineal, TAM_LINEAL);

//  system("PAUSE");

  h_init(tabla_clave, TAM_CLAVE);
  h_insert_fichero("coches.csv", tabla_clave, TAM_CLAVE, "clave");
  h_show(tabla_clave, TAM_CLAVE);

  system("PAUSE");
  return EXIT_SUCCESS;
}
