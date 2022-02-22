#ifndef CLOCK_H
#define CLOCK_H

#include <stdlib.h>
#include "buffer.h"

// Estrutura que representa o relógio

typedef struct Clock {
  int ponteiro;
  int totalPaginas;
  Buffer buffer;
} Clock1, Clock2;

void iniciarClock1(Clock1 *clock, int totalPaginas);
void iniciarClock2(Clock2 *clock, int totalPaginas);
void inserirPaginaClock1(Clock1 *clock, Pagina pagina);
void inserirPaginaClock2(Clock1 *clock1, Clock2 *clock, Pagina pagina);
void inserirPagina(Clock1 *clock1, Clock2 *clock2, Pagina pagina);
void avancarPonteiro(Clock1 *clock);

#endif
