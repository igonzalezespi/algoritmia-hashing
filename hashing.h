#ifndef _HASHING_
#define _HASHING_

#define LIBRE 1
#define BORRADO 0
#define MAX_LENGTH 250
#define MATRICULA_LENGTH 8

typedef struct myreg {
  unsigned long key;
  char matricula[MATRICULA_LENGTH];
  char marca[MAX_LENGTH];
  char modelo[MAX_LENGTH];
  int anyo;
  int precio;
} myreg;

typedef struct hash_result {
  int pos;
  int intentos;
} hash_result;

void h_init(myreg t_hash[], int tam);
hash_result h_insert(myreg r, myreg t_hash[], int tam, char prueba[], int es_fichero);
void h_insert_fichero(char* nombre_fichero, myreg t_hash[], int tam, char prueba[]);
int h_search(char matricula[], myreg t_hash[], int tam, char prueba[]);
void h_remove(char matricula[], myreg t_hash[], int tam, char prueba[]);
float h_loadfactor(myreg t_hash[], int tam);
void h_show(myreg t_hash[], int tam);

unsigned long get_key(char matricula[]);

#endif
