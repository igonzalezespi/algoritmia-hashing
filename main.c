#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "hashing.h"

#define TAM_LINEAL 250
#define TAM_CLAVE 256

void recursive_menu(myreg tabla[], int tam, char c_prueba, char prueba[]) {
  char accion; // i/e/b -- insertar/eliminar/buscar
  char matricula[MATRICULA_LENGTH];
  myreg reg;

  accion = menu_accion(c_prueba);
  menu_matricula(matricula);
  switch (accion) {
  case 'i':
    strcpy(reg.matricula, matricula);
    h_insert(reg, tabla, tam, prueba, 0);
    break;
  case 'e':
    h_remove(matricula, tabla, tam, prueba);
    break;
  case 'b':
    h_search(matricula, tabla, tam, prueba);
    break;
  }
  h_show(tabla, tam);
  system("PAUSE");
  recursive_menu(tabla, tam, c_prueba, prueba);
}

int main() {
  char c_prueba; // l/c -- lineal/clave
  char prueba[10]; // lineal/clave
  int tam;

  c_prueba = menu_prueba();
  if (c_prueba == 'l') {
    tam = TAM_LINEAL;
    strcpy(prueba, "lineal");
  } else {
    tam = TAM_CLAVE;
    strcpy(prueba, "clave");
  }
  myreg tabla[tam];
  h_init(tabla, tam);
  h_insert_fichero("coches.csv", tabla, tam, prueba);
  h_show(tabla, tam);

  system("PAUSE");
  recursive_menu(tabla, tam, c_prueba, prueba);

  return EXIT_SUCCESS;
}
