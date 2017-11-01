#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "lineal.h"
#include "clave.h"
#include "hashing.h"

int hashing(unsigned long key, myreg t_hash[], int tam, char tipo[], char prueba[]) {
  if (strcmp(prueba, "lineal") == 0) {
    return H_lineal(key, t_hash, tam, tipo);
  } else if (strcmp(prueba, "clave") == 0) {
    return H_clave(key, t_hash, tam, tipo);
  }
  return -3;
}

void h_init(myreg t_hash[], int tam) {
  int i;
  for (i=0; i < tam; i++) {
    t_hash[i].key = LIBRE;
  }
}

int h_insert(myreg r, myreg t_hash[], int tam, char prueba[]) {
  int pos;

  r.key = get_key(r.matricula);
  pos = hashing(r.key, t_hash, tam, "insert", prueba);
  if (pos >= 0) {
    t_hash[pos] = r;
    return 1;
  }
  return pos; // No se puede insertar
}

int h_search(char matricula[], myreg t_hash[], int tam, char prueba[]) {
  return hashing(get_key(matricula), t_hash, tam, "search", prueba);
}

int h_remove(char matricula[], myreg t_hash[], int tam, char prueba[]) {
  int pos;

  pos = hashing(get_key(matricula), t_hash, tam, "remove", prueba);
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
    if (t_hash[i].key != LIBRE && t_hash[i].key != BORRADO) {
      n_elems++;
    }
  }

  return ((float)n_elems/tam);
}

void h_show(myreg t_hash[], int tam) {
  int i;

  for(i = 0; i < tam; i++) {
    if (t_hash[i].key == LIBRE) {
      printf("|   libre");
    } else if (t_hash[i].key == BORRADO) {
      printf("| borrado");
    } else {
      printf("| %s", t_hash[i].matricula);
    }
  }
  printf("|\n");
}


void char_int_value(char str_val[], char letra) {
  // A valor ASCII. Garantizado que funcione por el estandar
  int val = toupper(letra) - '0'; // Convertimos a MAYUS para asegurar dos d�gitos
  sprintf(str_val, "%d", val); // Guardando el INT en formato CHAR
}

unsigned long get_key(char matricula[]) {
  /*
   * El prop�sito de esta funci�n es convertir la matr�cula en un identificador
   * num�rico �nico (sin perder el caracter �nico de las matr�culas).
   * Vamos a convertir la matr�cula en un n�mero.
   * Para ello vamos a convertir las letras de la matr�cula en ASCII
   * Luego de hacer esto, le concatenaremos los n�meros al final.
   * De este modo conseguiremos:
   *   Matr�cula: 9999ZZZ
   *   Valor final: 4242429999  (Siendo Z = 42)
   * Este valor, y teniendo en cuenta que ese ser�a el valor m�ximo,
   * podremos castear ese string en un "unsigned long", cuyo valor m�ximo es:
   * 4294967295
   * Que como vemos, es mayor que el m�ximo posible.
   */
  const int mat_len = 7; // Matr�cula = 4 numeros + 3 letras
  const int key_len = 10; // Por cada letra se cuentan 2 (valor ascii)
  char key[key_len + 1];
  unsigned long key_final = 0;
  int i, j;

  strcpy(key, "0000000000"); // Inicializo el string

  if (strlen(matricula) != mat_len) { // Tiene que ser de este tama�o obligatoriamente
    return 0;
  }

  /*
   * Copiamos los valores ascii de las letras
   * El valor num�rico desde la A hasta la Z es siempre de dos d�gitos
  */
  for (i = 0, j = 4; j <= mat_len - 1; i = i + 2, j++) {
    // i: Recorre "key", como cada letra son dos d�gitos, va de dos en dos
    // j: Recorre "matricula", de uno en uno ya que son las letras, no d�gitos
    char letra[3]; // Dos d�gitos + \0
    char_int_value(letra, matricula[j]); // Ahora tendr�amos el "42\0" si fuese una "Z"

    key[i] = letra[0];
    key[i + 1] = letra[1];
  }
  // Copiamos los n�meros
  // (No se convierte a ASCII para ahorrar memoria, solo necesitamos un INT al final)
  for (i = 6, j = 0; j <= 3; i++, j++) {
    // "key" ya tiene 3 letras, que son dos d�gitos, por lo tanto 3*2=6 [6, 9]
    // Los n�meros de la "matricula" empiezan en la posici�n 0 y son 4. [0, 3]
    key[i] = matricula[j];
  }
  key_final = strtoul(key, NULL, 0);
  return key_final;
};
