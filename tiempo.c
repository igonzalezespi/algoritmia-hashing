#include <time.h>

clock_t start, diff;

void empieza_tiempo() {
  start = clock();
}

void termina_tiempo() {
  diff = clock() - start;
  int msec = diff * 1000 / CLOCKS_PER_SEC;

  printf("Rendimiento CPU: %d segundos y %d milisegundos\n", msec/1000, msec%1000);
}
