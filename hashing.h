#ifndef _HASHING_
#define _HASHING_

#define LIBRE -1
#define BORRADO -2
#define MAX_LENGTH 250

typedef struct myreg {
  int key;
  char matricula[8];
  char marca[MAX_LENGTH];
  char modelo[MAX_LENGTH];
  int anyo;
  int precio;
} myreg;

void h_init(myreg t_hash[], int tam);
int h_insert(myreg r, myreg t_hash[], int tam, char prueba[]);
int h_search(int v, myreg t_hash[], int tam, char prueba[]);
int h_remove(int v, myreg t_hash[], int tam, char prueba[]);
float h_loadfactor(myreg t_hash[], int tam);

void h_show(myreg t_hash[], int tam);

#endif
