#include "hashing.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(int argc, char *argv[]) {
  myreg myhash[TAM];
  myreg reg1, reg2, reg3;

  reg1.key = 10;
  reg2.key = 20;
  reg3.key = 11;



  h_init(myhash, TAM);
  h_insert(reg1, myhash, TAM);
  h_insert(reg2, myhash, TAM);
  h_insert(reg3, myhash, TAM);

  h_show(myhash, TAM);

  h_remove(10, myhash, TAM);

  h_show(myhash, TAM);

  int pos = h_search(11, myhash, TAM);
  printf("El valor 11 esta en la pos %d de la tabla\n",pos);




  system("PAUSE");
  return EXIT_SUCCESS;
}
