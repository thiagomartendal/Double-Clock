#ifndef CLOCK_H
#define CLOCK_H

#include <stdlib.h>
#include "buffer.h"

// Estrutura que representa o relógio

typedef struct Clock {
  int ponteiro;
  int totalPaginas;
  Buffer buffer;
} Clock;

void iniciar(Clock *clock, int totalPaginas);
void inserirPagina(Clock *clock, Pagina pagina);
void avancarPonteiro(Clock *clock);

#endif
