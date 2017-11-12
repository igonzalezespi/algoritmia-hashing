#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "tiempo.h"
#include "lineal.h"
#include "clave.h"
#include "hashing.h"

hash_result hashing(unsigned long key, myreg t_hash[], int tam, char tipo[], char prueba[]) {
  if (strcmp(prueba, "lineal") == 0) {
    return H_lineal(key, t_hash, tam, tipo);
  } else if (strcmp(prueba, "clave") == 0) {
    return H_clave(key, t_hash, tam, tipo);
  }
  hash_result result;
  result.intentos = 0;
  result.pos = -3;
  return result;
}

void h_init(myreg t_hash[], int tam) {
  printf("Inicializando tabla (%d)\n", tam);
  int i;
  for (i=0; i < tam; i++) {
    t_hash[i].key = LIBRE;
  }
  printf("Tabla inicializada (%d)\n", tam);
}

hash_result h_insert(myreg r, myreg t_hash[], int tam, char prueba[], int es_fichero) {
  hash_result result;

  if (es_fichero == 0)  {
    empieza_tiempo();
    printf("Insertando coche \"%s\"...\n", r.matricula);
  }
  r.key = get_key(r.matricula);
  result = hashing(r.key, t_hash, tam, "insert", prueba);
  if (result.pos >= 0) {
    t_hash[result.pos] = r;
    if (es_fichero == 0)  {
      printf("Coche \"%s\" intertado\n", r.matricula);
      printf("%d intentos\n", result.intentos);
      termina_tiempo();
    }
    return result;
  } else if (result.pos == -2) {
    printf("ERROR el coche \"%s\" ya esta en la tabla\n", r.matricula);
  } else if (result.pos == -1) {
    printf("ERROR tabla llena\n");
  } else {
    printf("ERROR insertando coche \"%s\"\n", r.matricula);
  }
  termina_tiempo();
  return result;
}

void h_insert_fichero(char* nombre_fichero, myreg t_hash[], int tam, char prueba[]) {
  char linea[500]; // Para guardar la linea de cada fichero
  char *token;     // Para cada token de cada linea
  int i;
  hash_result result;
  int intentos_totales = 0;

  empieza_tiempo();
  printf("Insertando fichero %s...\n", nombre_fichero);

  //Abrimos el fichero
  FILE *fp = fopen(nombre_fichero,"r");

  // Comprobar que no hay error al abrir
  if(fp == NULL) {
    printf("Error de lectura del archivo %s\n", nombre_fichero);
  }

  // Recorremos cada linea del fichero
  while(fgets(linea,500,fp)!=NULL) {
    myreg reg;
    i = 0;
//    printf("Linea leida: %s\n", linea);
    token = strtok(linea,","); // Separamos cada linea por ","
    while (token != NULL) {
      switch (i) {
      case 0:
        strncpy(reg.matricula, token, MATRICULA_LENGTH);
        break;
      case 1:
        strncpy(reg.modelo, token, MAX_LENGTH);
        break;
      case 2:
        strncpy(reg.marca, token, MAX_LENGTH);
        break;
      case 3:
        reg.anyo = atoi(token);
        break;
      case 4:
        reg.precio = atoi(token);
        break;
      }
      token = strtok(NULL, ",");  // Siguiente token en la linea (si quedan)
      i++;
    }
    result = h_insert(reg, t_hash, tam, prueba, 1);
    intentos_totales += result.intentos;
//    system("PAUSE");
  }
  printf("Fichero insertado en la tabla (%d).\n", tam);
  printf("Intentos totales: %d\n", intentos_totales);
  printf("Factor de capacidad: %f\n", h_loadfactor(t_hash, tam));
  termina_tiempo();
}

int h_search(char matricula[], myreg t_hash[], int tam, char prueba[]) {
  hash_result result = hashing(get_key(matricula), t_hash, tam, "search", prueba);
  empieza_tiempo();
  if (result.pos >= 0) {
    printf("Coche \"%s\" encontrado en la posicion %d\n", matricula, result.pos);
    printf("%d intentos\n", result.intentos);
    termina_tiempo();
    return result.pos;
  }
  printf("Coche \"%s\" no encontrado\n", matricula);
  termina_tiempo();
  return -1;
}

void h_remove(char matricula[], myreg t_hash[], int tam, char prueba[]) {
  hash_result result;

  empieza_tiempo();
  result = hashing(get_key(matricula), t_hash, tam, "remove", prueba);
  if (result.pos >= 0) {
    t_hash[result.pos].key = BORRADO;
    printf("Borrado coche \"%s\"\n", matricula);
    printf("%d intentos\n", result.intentos);
  } else {
    printf("ERROR borrando coche \"%s\"\n", matricula);
  }
  termina_tiempo();
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

  printf("\n========= Tabla lineal =========\n\n");
  for(i = 0; i < tam; i++) {
    if (t_hash[i].key == LIBRE) {
      printf("|   libre");
    } else if (t_hash[i].key == BORRADO) {
      printf("| borrado");
    } else {
      printf("| %s", t_hash[i].matricula);
    }
  }
  printf("|\n\n");
}


void char_int_value(char str_val[], char letra) {
  // A valor ASCII. Garantizado que funcione por el estandar
  int val = toupper(letra) - '0'; // Convertimos a MAYUS para asegurar dos dígitos
  sprintf(str_val, "%d", val); // Guardando el INT en formato CHAR
}

unsigned long get_key(char matricula[]) {
  /*
   * El propósito de esta función es convertir la matrícula en un identificador
   * numérico único (sin perder el caracter único de las matrículas).
   * Vamos a convertir la matrícula en un número.
   * Para ello vamos a convertir las letras de la matrícula en ASCII
   * Luego de hacer esto, le concatenaremos los números al final.
   * De este modo conseguiremos:
   *   Matrícula: 9999ZZZ
   *   Valor final: 4242429999  (Siendo Z = 42)
   * Este valor, y teniendo en cuenta que ese sería el valor máximo,
   * podremos castear ese string en un "unsigned long", cuyo valor máximo es:
   * 4294967295
   * Que como vemos, es mayor que el máximo posible.
   */
  const int mat_len = 7; // Matrícula = 4 numeros + 3 letras
  const int key_len = 10; // Por cada letra se cuentan 2 (valor ascii)
  char key[key_len + 1];
  unsigned long key_final = 0;
  int i, j;

  strcpy(key, "0000000000"); // Inicializo el string

  /*
   * Copiamos los valores ascii de las letras
   * El valor numérico desde la A hasta la Z es siempre de dos dígitos
  */
  for (i = 0, j = 4; j <= mat_len - 1; i = i + 2, j++) {
    // i: Recorre "key", como cada letra son dos dígitos, va de dos en dos
    // j: Recorre "matricula", de uno en uno ya que son las letras, no dígitos
    char letra[3]; // Dos dígitos + \0
    char_int_value(letra, matricula[j]); // Ahora tendríamos el "42\0" si fuese una "Z"

    key[i] = letra[0];
    key[i + 1] = letra[1];
  }
  // Copiamos los números
  // (No se convierte a ASCII para ahorrar memoria, solo necesitamos un INT al final)
  for (i = 6, j = 0; j <= 3; i++, j++) {
    // "key" ya tiene 3 letras, que son dos dígitos, por lo tanto 3*2=6 [6, 9]
    // Los números de la "matricula" empiezan en la posición 0 y son 4. [0, 3]
    key[i] = matricula[j];
  }
  key_final = strtoul(key, NULL, 0);
  return key_final;
};
