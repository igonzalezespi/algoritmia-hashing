#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "menu.h"

void cls() {
  system("cls");
}

char menu_prueba() {
  char seleccion;
  char prueba;
  int seleccionado = 0;
  cls();
  printf("=========== Telovendo ===========\n\n");
  printf("== Escoja la prueba de hashing ==\n");
  printf("1. Lineal\n");
  printf("2. Clave\n");
  printf("S. Salir\n");
  scanf(" %c", &seleccion);

  switch (tolower(seleccion)) {
  case '1':
    prueba = 'l';
    seleccionado = 1;
    break;
  case '2':
    prueba = 'c';
    seleccionado = 1;
    break;
  case 's':
    exit(0);
  }
  if (seleccionado == 1) {
    return prueba;
  }
  return menu_prueba();
}

char menu_accion(char prueba) {
  char seleccion;
  char accion;
  int seleccionado = 0;
  cls();
  printf("=========== Telovendo ===========\n\n");
  if (prueba == 'l') {
    printf("========= Prueba: lineal ========\n");
  } else {
    printf("========= Prueba: clave =========\n");
  }
  printf("====== Seleccione la accion =====\n");
  printf("1. Insertar\n");
  printf("2. Eliminar\n");
  printf("3. Buscar\n");
  printf("S. Salir\n");
  scanf(" %c", &seleccion);

  switch (tolower(seleccion)) {
  case '1':
    accion = 'i';
    seleccionado = 1;
    break;
  case '2':
    accion = 'e';
    seleccionado = 1;
    break;
  case '3':
    accion = 'b';
    seleccionado = 1;
    break;
  case 's':
    exit(0);
  }
  if (seleccionado == 1) {
    return accion;
  }
  return menu_accion(prueba);
}

void menu_matricula(char* matricula) {
  cls();
  printf("=========== Telovendo ===========\n\n");
  printf("====== Escriba la matricula =====\n");
  scanf(" %s", matricula);

  if (strlen(matricula) != 7) {
    menu_matricula(matricula);
  }
  for ( ; *matricula; ++matricula) *matricula = toupper(*matricula); // Convirtiendo a mayus
}
