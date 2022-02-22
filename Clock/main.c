#include <stdio.h>
#include "clock.h"

// Inserção das páginas no relógio
void inserirPaginas(Clock *clock) {
  Pagina pag0 = {0, false};
  Pagina pag1 = {1, false};
  Pagina pag2 = {2, true};
  Pagina pag3 = {3, false};
  Pagina pag4 = {4, true};
  Pagina pag5 = {5, true};
  inserirPagina(clock, pag0);
  inserirPagina(clock, pag1);
  inserirPagina(clock, pag2);
  inserirPagina(clock, pag3);
  inserirPagina(clock, pag4);
  inserirPagina(clock, pag5);
}

// Exibe as páginas no relógio
void exibir(Clock clock) {
  for (int i = 0; i < clock.buffer.tamanho; i++) {
    Pagina pag = clock.buffer.paginas[i];
    printf("Página: %d - Bit R: %d\n", pag.numero, pag.bitR);
  }
}

int main() {
  printf("Relógio com 6 páginas\n");
  Clock clock;
  iniciar(&clock, 6);
  inserirPaginas(&clock);
  exibir(clock);
  printf("----------------\n");
  // Insere uma página além da capacidade
  printf("Relógio com uma página a mais\n");
  Pagina pag6 = {6, true};
  inserirPagina(&clock, pag6);
  exibir(clock);
  return 0;
}
