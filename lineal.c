#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lineal.h"

int G_lineal(unsigned long key, myreg t_hash[], int tam, char tipo[], int h, int i) {
  // G es: Prueba lineal
  int g = (h + i) % tam;

  if (i != 0) {
    printf("G: %d\n", g);
  }
  if (i > tam) {
    return -1; // No se encuentra/No se puede insertar
  }
  if (strcmp(tipo, "insert") == 0) { // Estamos insertando
    if (t_hash[g].key == key) { // Si lo encontramos
      return -2; // Ya existe
    } else if (t_hash[g].key == LIBRE || t_hash[g].key == BORRADO) { // Si est� libre
      return g; // Devuelvo la posici�n
    }
  } else { // Si estamos buscando
    if (t_hash[g].key == key) { // Si lo encontramos
      return g; // Devolvemos la posici�n
    }
  }
  i = i + 1;
  return G_lineal(key, t_hash, tam, tipo, h, i);
}

int H_lineal(unsigned long key, myreg t_hash[], int tam, char tipo[]) {
  // H es: m�dulo con el tama�o total
  int h = key % tam;
  int i = 0;
  printf("----------\n");
  printf("H: %d\n", h);
  int pos = G_lineal(key, t_hash, tam, tipo, h, i);
  printf("Intentos: %d\n", i);
  return pos;
}
