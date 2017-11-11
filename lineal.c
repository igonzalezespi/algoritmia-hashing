#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lineal.h"

hash_result G_lineal(unsigned long key, myreg t_hash[], int tam, char tipo[], int h, int i) {
  // G es: Prueba lineal
  int g = (h + i) % tam;
  hash_result result;

//  if (i != 0) {
//    printf("G: %d\n", g);
//  }
  if (i > tam) {
    result.pos = -1;
    result.intentos = i;
    return result; // No se encuentra/No se puede insertar
  }
  if (strcmp(tipo, "insert") == 0) { // Estamos insertando
    if (t_hash[g].key == key) { // Si lo encontramos
      result.pos = -2;
      result.intentos = i;
      return result; // Ya existe
    } else if (t_hash[g].key == LIBRE || t_hash[g].key == BORRADO) { // Si est� libre
      result.pos = g; // Devuelvo la posici�n
      result.intentos = i;
      return result;
    }
  } else { // Si estamos buscando
    if (t_hash[g].key == key) { // Si lo encontramos
      result.pos = g; // Devolvemos la posici�n
      result.intentos = i;
      return result; // Devolvemos la posici�n
    }
  }
  return G_lineal(key, t_hash, tam, tipo, h, i + 1);
}

hash_result H_lineal(unsigned long key, myreg t_hash[], int tam, char tipo[]) {
  // H es: m�dulo con el tama�o total
  int h = key % tam;
  int i = 0;
  hash_result result;
//  printf("----------\n");
//  printf("H: %d\n", h);
  result = G_lineal(key, t_hash, tam, tipo, h, i);
//  printf("Intentos: %d\n", result.intentos);
  return result;
}
