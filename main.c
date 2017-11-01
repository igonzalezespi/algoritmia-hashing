#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashing.h"

#define TAM 16

int main(int argc, char *argv[]) {
  int pos;
  myreg myhash[TAM];
  myreg reg1, reg2, reg3, reg4, reg5, reg6, reg7, reg8;

  strcpy(reg1.matricula, "0003AAA");
  strcpy(reg1.marca, "Buick");
  strcpy(reg1.modelo, "Park Avenue");
  reg1.anyo = 1998;
  reg1.precio = 1901;

  strcpy(reg2.matricula, "9714WXS");
  strcpy(reg2.marca, "Cadillac");
  strcpy(reg2.modelo, "SRX");
  reg2.anyo = 2009;
  reg2.precio = 5965;

  strcpy(reg3.matricula, "7084HKY");
  strcpy(reg3.marca, "Dodge");
  strcpy(reg3.modelo, "Park Avenue");
  reg3.anyo = 1998;
  reg3.precio = 1901;

  strcpy(reg4.matricula, "4100LWH");
  strcpy(reg4.marca, "Cadillac");
  strcpy(reg4.modelo, "Park Avenue");
  reg4.anyo = 1998;
  reg4.precio = 1901;

  strcpy(reg5.matricula, "1450LJG");
  strcpy(reg5.marca, "Chrysler");
  strcpy(reg5.modelo, "Park Avenue");
  reg5.anyo = 1998;
  reg5.precio = 1901;

  strcpy(reg6.matricula, "5445TQI");
  strcpy(reg6.marca, "Chrysler");
  strcpy(reg6.modelo, "Park Avenue");
  reg6.anyo = 1998;
  reg6.precio = 1901;

  strcpy(reg7.matricula, "9173OMJ");
  strcpy(reg7.marca, "Chrysler");
  strcpy(reg7.modelo, "Park Avenue");
  reg7.anyo = 1998;
  reg7.precio = 1901;

  strcpy(reg8.matricula, "1493UZL");
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
  if (h_insert(reg1, myhash, TAM, "lineal") < 0) {
    printf("No se pudo insertar el registro con matricula \"%s\"\n", reg1.matricula);
  } else {
    printf("Se ha insertado el registro con matricula \"%s\"\n", reg1.matricula);
  }
  if (h_insert(reg2, myhash, TAM, "lineal") < 0) {
    printf("No se pudo insertar el registro con matricula \"%s\"\n", reg2.matricula);
  } else {
    printf("Se ha insertado el registro con matricula \"%s\"\n", reg2.matricula);
  }
//  h_insert(reg2, myhash, TAM, "lineal");
//  h_insert(reg3, myhash, TAM, "lineal");
//  h_insert(reg4, myhash, TAM, "lineal");
//  h_insert(reg5, myhash, TAM, "lineal");
//  h_insert(reg6, myhash, TAM, "lineal");
//  h_insert(reg7, myhash, TAM, "lineal");
//  h_insert(reg8, myhash, TAM, "lineal");

  h_show(myhash, TAM);
  printf("FACTOR: %f\n", h_loadfactor(myhash, TAM));

  if (h_remove(reg2.matricula, myhash, TAM, "lineal") < 0) {
    printf("No se pudo borrar el registro con matricula \"%s\"\n", reg2.matricula);
  } else {
    printf("Se ha borrado el registro con matricula \"%s\"\n", reg2.matricula);
  }

  pos = h_search(reg1.matricula, myhash, TAM, "lineal");
  if (pos < 0) {
    printf("No se pudo encontrar el registro con matricula \"%s\"\n", reg1.matricula);
  } else {
    printf("El registro con matricula \"%s\" esta en la posicion: %d\n", reg1.matricula, pos + 1);
  }

  pos = h_search(reg2.matricula, myhash, TAM, "lineal");
  if (pos < 0) {
    printf("No se pudo encontrar el registro con matricula \"%s\"\n", reg2.matricula);
  } else {
    printf("El registro con matricula \"%s\" esta en la posicion: %d\n", reg2.matricula, pos + 1);
  }

  system("PAUSE");
  return EXIT_SUCCESS;
}
