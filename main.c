#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashing.h"

#define TAM 16

int main(int argc, char *argv[]) {
  myreg myhash[TAM];
  myreg reg1, reg2, reg3, reg4, reg5, reg6, reg7, reg8;

  strcpy(reg1.matricula, "7360AAA");
  reg1.key = get_key(reg1.matricula);
  strcpy(reg1.marca, "Buick");
  strcpy(reg1.modelo, "Park Avenue");
  reg1.anyo = 1998;
  reg1.precio = 1901;

  strcpy(reg2.matricula, "9714WXS");
  reg2.key = get_key(reg2.matricula);
  strcpy(reg2.marca, "Cadillac");
  strcpy(reg2.modelo, "SRX");
  reg2.anyo = 2009;
  reg2.precio = 5965;

  strcpy(reg3.matricula, "7084HKY");
  reg3.key = get_key(reg3.matricula);
  strcpy(reg3.marca, "Dodge");
  strcpy(reg3.modelo, "Park Avenue");
  reg3.anyo = 1998;
  reg3.precio = 1901;

  strcpy(reg4.matricula, "4100LWH");
  reg4.key = get_key(reg4.matricula);
  strcpy(reg4.marca, "Cadillac");
  strcpy(reg4.modelo, "Park Avenue");
  reg4.anyo = 1998;
  reg4.precio = 1901;

  strcpy(reg5.matricula, "1450LJG");
  reg5.key = get_key(reg5.matricula);
  strcpy(reg5.marca, "Chrysler");
  strcpy(reg5.modelo, "Park Avenue");
  reg5.anyo = 1998;
  reg5.precio = 1901;

  strcpy(reg6.matricula, "5445TQI");
  reg6.key = get_key(reg6.matricula);
  strcpy(reg6.marca, "Chrysler");
  strcpy(reg6.modelo, "Park Avenue");
  reg6.anyo = 1998;
  reg6.precio = 1901;

  strcpy(reg7.matricula, "9173OMJ");
  reg7.key = get_key(reg7.matricula);
  strcpy(reg7.marca, "Chrysler");
  strcpy(reg7.modelo, "Park Avenue");
  reg7.anyo = 1998;
  reg7.precio = 1901;

  strcpy(reg8.matricula, "1493UZL");
  reg8.key = get_key(reg8.matricula);
  strcpy(reg8.marca, "Chrysler");
  strcpy(reg8.modelo, "Park Avenue");
  reg8.anyo = 1998;
  reg8.precio = 1901;


  printf("Matricula1 %s\n", reg1.matricula);
  printf("Matricula2 %s\n", reg2.matricula);
  printf("Matricula3 %s\n", reg3.matricula);
  printf("Matricula4 %s\n", reg4.matricula);
  printf("Matricula5 %s\n", reg5.matricula);
  printf("Matricula6 %s\n", reg6.matricula);
  printf("Matricula7 %s\n", reg7.matricula);
  printf("Matricula8 %s\n", reg8.matricula);

  h_init(myhash, TAM);
  h_insert(reg1, myhash, TAM, "clave");
  h_insert(reg2, myhash, TAM, "clave");
  h_insert(reg3, myhash, TAM, "clave");
  h_insert(reg4, myhash, TAM, "clave");
  h_insert(reg5, myhash, TAM, "clave");
  h_insert(reg6, myhash, TAM, "clave");
  h_insert(reg7, myhash, TAM, "clave");
  h_insert(reg8, myhash, TAM, "clave");

  h_show(myhash, TAM);
  printf("FACTOR: %f\n", h_loadfactor(myhash, TAM));

  system("PAUSE");
  return EXIT_SUCCESS;
}
