#include "hashing.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* priv */

int G(int key, myreg t_hash[], int tam, char tipo[], int h, int i) {
  // G es: Prueba lineal
  int g = h + i;

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
  return G(key, t_hash, tam, tipo, h, i + 1);
}

int H(int key, myreg t_hash[], int tam, char tipo[]) {
  // H es: módulo con el tamaño total
  int h = key % tam;
  return G(key, t_hash, tam, tipo, h, 0);
}


/* pub */

void h_init(myreg t_hash[], int tam) {
  int i;
  for(i=0; i < tam; i++) {
    t_hash[i].key = LIBRE;
  }
}

int h_insert(myreg r, myreg t_hash[], int tam) {
  int pos;

  pos = H(r.key, t_hash, tam, "insert");
  if(pos >= 0) {
    t_hash[pos] = r;
    return 1;
  }
  return pos; // No se puede insertar
}

int h_search(int v, myreg t_hash[], int tam) {
  return H(v, t_hash, tam, "search");
}

int h_remove(int v, myreg t_hash[], int tam) {
  int pos;

  pos = H(v, t_hash, tam, "remove");
  if (pos >= 0) {
    t_hash[pos].key = BORRADO;
    return 1;
  }
  return pos; // No se puede borrar
}

// N/M, donde N es el numero de elemento insertados
// M es el tamano de la tabla hash
float h_loadfactor(myreg t_hash[], int tam) {
  int n_elems = 0;
  int i;

  for (i = 0; i < tam; i++) {
    if (t_hash[i].key != LIBRE && t_hash[i].key != BORRADO)
      n_elems++;
  }

  return ((float)n_elems/tam);
}

void h_show(myreg t_hash[], int tam) {
  int i;

  for(i = 0; i < tam; i++) {
    printf("| %d", t_hash[i].key);
  }
  printf("|\n");
}

