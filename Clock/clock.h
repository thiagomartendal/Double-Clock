#ifndef CLOCK_H
#define CLOCK_H

#include <stdio.h>
#include <stdlib.h>
#include "pagina.h"

typedef struct Clock {
  int ponteiro;
  int totalPaginas;
  int paginasInseridas;
  Pagina *paginas;
} Clock;

void iniciar(Clock *clock, int tamanhoMoldura);
void inserirPagina(Clock *clock, Pagina pagina);
void avancarPonteiro(Clock *clock);

#endif
