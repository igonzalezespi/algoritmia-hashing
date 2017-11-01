#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "clave.h"

int G_clave(unsigned int key, myreg t_hash[], int tam, char tipo[], int h, int i) {
  // G es: Prueba dependiente de clave
  unsigned long d = (unsigned long)(key / tam); // Se toma la parte entera automáticamente (FLOOR)
  if (d % 2 == 0 || d == 0) { // Impar mayor que cero para recorrer toda la tabla
    d += 1;
  }
  int g = (h + (d * i)) % tam;

  if (i > tam) {
    return -1; // No se encuentra/No se puede insertar
  }
  if (strcmp(tipo, "insert") == 0) { // Estamos insertando
    if (t_hash[g].key == key) { // Si lo encontramos
      return -2; // Ya existe
    } else if (t_hash[g].key == LIBRE || t_hash[g].key == BORRADO) { // Si está libre
      return g; // Devuelvo la posición
    }
  } else { // Si estamos buscando
    if (t_hash[g].key == key) { // Si lo encontramos
      return g; // Devolvemos la posición
    }
  }
  return G_clave(key, t_hash, tam, tipo, h, i + 1);
}

int H_clave(int key, myreg t_hash[], int tam, char tipo[]) {
  // H es: módulo con el tamaño total
  int h = key % tam;
  return G_clave(key, t_hash, tam, tipo, h, 0);
}

