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

void iniciar(Clock *C1, Clock *C2, int tamanhoMoldura);
void inserirPagina(Clock *C1, Clock *C2, Pagina pagina);
void removerPagina(Clock *C1, int pos);
void clockClassico(Clock *clock1, Clock *clock2, Pagina pagina);
void avancarPonteiro(Clock *clock);

#endif
