#include <stdio.h>
#include <stdlib.h>

#include "hashing.h"

#define TAM 8

int main(int argc, char *argv[]) {
  int pos;
  myreg myhash[TAM];
  myreg reg1, reg2, reg3, reg4, reg5;

  reg1.key = 10;
  strcpy(reg1.matricula, "7360ENO");
  strcpy(reg1.marca, "Buick");
  strcpy(reg1.modelo, "Park Avenue");
  reg1.anyo = 1998;
  reg1.precio = 1901;

  reg2.key = 41;
  strcpy(reg2.matricula, "9714WXS");
  strcpy(reg2.marca, "Cadillac");
  strcpy(reg2.modelo, "SRX");
  reg2.anyo = 2009;
  reg2.precio = 5965;

  reg3.key = 30;
  strcpy(reg3.matricula, "7084HKY");
  strcpy(reg3.marca, "Dodge");
  strcpy(reg3.modelo, "Park Avenue");
  reg3.anyo = 1998;
  reg3.precio = 1901;

  reg4.key = 49;
  strcpy(reg4.matricula, "4100LWH");
  strcpy(reg4.marca, "Cadillac");
  strcpy(reg4.modelo, "Park Avenue");
  reg4.anyo = 1998;
  reg4.precio = 1901;

  reg5.key = 50;
  strcpy(reg5.matricula, "1450LJG");
  strcpy(reg5.marca, "Chrysler");
  strcpy(reg5.modelo, "Park Avenue");
  reg5.anyo = 1998;
  reg5.precio = 1901;


  printf("Matricula1 %s\n", reg1.matricula);
  printf("Matricula2 %s\n", reg2.matricula);
  printf("Matricula3 %s\n", reg3.matricula);
  printf("Matricula4 %s\n", reg4.matricula);
  printf("Matricula5 %s\n", reg5.matricula);

  h_init(myhash, TAM);
  h_insert(reg1, myhash, TAM, "clave");
  h_insert(reg2, myhash, TAM, "clave");
  h_insert(reg3, myhash, TAM, "clave");
  h_insert(reg4, myhash, TAM, "clave");
  h_insert(reg5, myhash, TAM, "clave");

  h_show(myhash, TAM);

  h_remove(41, myhash, TAM, "clave");

  h_show(myhash, TAM);

  pos = h_search(11, myhash, TAM, "clave");
  printf("El valor 11 esta en la pos %d de la tabla\n",pos);
  pos = h_search(10, myhash, TAM, "clave");
  printf("El valor 10 esta en la pos %d de la tabla\n",pos);
  pos = h_search(49, myhash, TAM, "clave");
  printf("El valor 49 esta en la pos %d de la tabla\n",pos);




  system("PAUSE");
  return EXIT_SUCCESS;
}
