#include "clock.h"

void iniciar(Clock *clock, int tamanhoMoldura) {
  clock->ponteiro = 0;
  clock->totalPaginas = tamanhoMoldura;
  clock->paginasInseridas = 0;
  clock->paginas = malloc(tamanhoMoldura*sizeof(Pagina));
}

void inserirPagina(Clock *clock, Pagina pagina) {
  if (clock->paginasInseridas < clock->totalPaginas) {
    clock->paginas[clock->paginasInseridas] = pagina;
    clock->paginasInseridas++;
  } else {
    Pagina *paginaPonteiro = &clock->paginas[clock->ponteiro];
    if (paginaPonteiro->bitR == 1) {
      paginaPonteiro->bitR = 0;
      avancarPonteiro(clock);
      inserirPagina(clock, pagina);
    } else if (paginaPonteiro->bitR == 0) {
      clock->paginas[clock->ponteiro] = pagina;
      avancarPonteiro(clock);
    }
  }
}

void avancarPonteiro(Clock *clock) {
  if (clock->ponteiro == clock->totalPaginas-1) { // Se o ponteiro for igual ao total de páginas-1 retorna para a posição inicial do relógio, realizando a circularidade
    clock->ponteiro = 0;
  } else { // Se não o ponteiro é incrementado
    clock->ponteiro++;
  }
}
