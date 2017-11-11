#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "clave.h"

hash_result G_clave(unsigned long key, myreg t_hash[], int tam, char tipo[], int h, int i) {
  // G es: Prueba dependiente de clave
  unsigned long d = (unsigned long)(key / tam); // Se toma la parte entera automáticamente (FLOOR)
  hash_result result;

  if (d % 2 == 0 || d == 0) { // Impar mayor que cero para recorrer toda la tabla
    d += 1;
  }
  int g = (h + (d * i)) % tam;

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
    } else if (t_hash[g].key == LIBRE || t_hash[g].key == BORRADO) { // Si está libre
      result.pos = g; // Devuelvo la posición
      result.intentos = i;
      return result;
    }
  } else { // Si estamos buscando
    if (t_hash[g].key == key) { // Si lo encontramos
      result.pos = g; // Devolvemos la posición
      result.intentos = i;
      return result;
    }
  }
  return G_clave(key, t_hash, tam, tipo, h, i + 1);
}

hash_result H_clave(unsigned long key, myreg t_hash[], int tam, char tipo[]) {
  // H es: módulo con el tamaño total
  int h = key % tam;
  int i = 0;
  hash_result result;
//  printf("----------\n");
//  printf("H: %d\n", h);
  result = G_clave(key, t_hash, tam, tipo, h, i);
//  printf("Intentos: %d\n", result.intentos);
  return result;
}

