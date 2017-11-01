#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lineal.h"
#include "clave.h"
#include "hashing.h"

int hashing(int key, myreg t_hash[], int tam, char tipo[], char prueba[]) {
  if (strcmp(prueba, "lineal") == 0) {
    return H_lineal(key, t_hash, tam, tipo);
  } else if (strcmp(prueba, "clave") == 0) {
    return H_clave(key, t_hash, tam, tipo);
  }
  return -3;
}

void h_init(myreg t_hash[], int tam) {
  int i;
  for(i=0; i < tam; i++) {
    t_hash[i].key = LIBRE;
  }
}

int h_insert(myreg r, myreg t_hash[], int tam, char prueba[]) {
  int pos;

  pos = hashing(r.key, t_hash, tam, "insert", prueba);
  if(pos >= 0) {
    t_hash[pos] = r;
    return 1;
  }
  return pos; // No se puede insertar
}

int h_search(int v, myreg t_hash[], int tam, char prueba[]) {
  return hashing(v, t_hash, tam, "search", prueba);
}

int h_remove(int v, myreg t_hash[], int tam, char prueba[]) {
  int pos;

  pos = hashing(v, t_hash, tam, "remove", prueba);
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
    if (t_hash[i].key >= 0) {
      printf("| %s", t_hash[i].matricula);
    } else {
      printf("|        ");
    }
  }
  printf("|\n");
}
