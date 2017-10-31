#include "hashing.h"
#include <stdlib.h>
#include <stdio.h>

void h_init(myreg t_hash[], int tam) {
  int i;
  for(i=0; i < tam; i++) {
    t_hash[i].key = LIBRE;
  }
}

int H(int k, int tam) {
  return (k%tam);
}

int h_insert(myreg r, myreg t_hash[], int tam) {
  int pos;

  pos = h_search(r.key, t_hash, tam);
  if(pos >= 0) {
    t_hash[pos] = r;
    return 1;
  } else {
    return -1; // No se puede insertar
  }
}


int h_search(int v, myreg t_hash[], int tam) {
  int pos;

  pos = H(v, tam);

  if(pos == -1) {
    return -1;  // No esta en la tabla
  } else {
    return pos;
  }
}


int h_remove(int v, myreg t_hash[], int tam) {
  int pos;

  pos = h_search(v,t_hash,tam);
  if(pos == -1) return -1; // No se puede borrar
  t_hash[pos].key = BORRADO;
  return 1;
}

// N/M, donde N es el numero de elemento insertados
// M es el tamano de la tabla hash
float h_loadfactor(myreg t_hash[], int tam) {
  int n_elems = 0;
  int i;

  for(i = 0; i < tam; i++) {
    if(t_hash[i].key != LIBRE  &&  t_hash[i].key != BORRADO)
      n_elems++;
  }

  return ((float)n_elems/tam);
}

void h_show(myreg t_hash[], int tam) {
  int i;

  for(i = 0; i < tam; i++) {
    printf("%d | ", t_hash[i].key);
  }
  printf("\n");
}

