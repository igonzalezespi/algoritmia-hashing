#include <stdio.h>
#include <stdlib.h>

#include "hashing.h"

#define TAM 10

int main(int argc, char *argv[]) {
  int pos;
  myreg myhash[TAM];
  myreg reg1, reg2, reg3, reg4, reg5;

  reg1.key = 10;
  reg2.key = 41;
  reg3.key = 30;
  reg4.key = 49;
  reg5.key = 50;



  h_init(myhash, TAM);
  h_insert(reg1, myhash, TAM, "lineal");
  h_insert(reg2, myhash, TAM, "lineal");
  h_insert(reg3, myhash, TAM, "lineal");
  h_insert(reg4, myhash, TAM, "lineal");
  h_insert(reg5, myhash, TAM, "lineal");

  h_show(myhash, TAM);

  h_remove(41, myhash, TAM, "lineal");

  h_show(myhash, TAM);

  pos = h_search(11, myhash, TAM, "lineal");
  printf("El valor 11 esta en la pos %d de la tabla\n",pos);




  system("PAUSE");
  return EXIT_SUCCESS;
}
