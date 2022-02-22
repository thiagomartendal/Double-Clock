#include <stdio.h>
#include "clock.h"

// Inserção das páginas no relógio
void inserirPaginas(Clock1 *clock1, Clock2 *clock2) {
  Pagina pag0 = {0, false, true};
  Pagina pag1 = {1, false, true};
  Pagina pag2 = {2, true, false};
  Pagina pag3 = {3, false, true};
  Pagina pag4 = {4, true, true};
  Pagina pag5 = {5, true, false};
  inserirPagina(clock1, clock2, pag0);
  inserirPagina(clock1, clock2, pag1);
  inserirPagina(clock1, clock2, pag2);
  inserirPagina(clock1, clock2, pag3);
  inserirPagina(clock1, clock2, pag4);
  inserirPagina(clock1, clock2, pag5);
}

// Exibe as páginas no relógio
void exibir(Clock1 clock1, Clock2 clock2) {
  printf("Clock 1\n");
  for (int i = 0; i < clock1.buffer.tamanho; i++) {
    Pagina pag = clock1.buffer.paginas[i];
    if (pag.paginaVazia) {
      printf("Página: ? - Bit R: ? - Bit M: ?\n");
    } else {
      printf("Página: %d - Bit R: %d - Bit M: %d\n", pag.numero, pag.bitR, pag.bitM);
    }
  }
  printf("Clock 2\n");
  for (int i = 0; i < clock2.buffer.tamanho; i++) {
    Pagina pag = clock2.buffer.paginas[i];
    printf("Página: %d - Bit R: %d - Bit M: %d\n", pag.numero, pag.bitR, pag.bitM);
  }
}

int main() {
  printf("Relógio com 6 páginas\n");
  Clock1 clock1;
  Clock2 clock2;
  iniciarClock1(&clock1, 6);
  iniciarClock2(&clock2, 4);
  inserirPaginas(&clock1, &clock2);
  exibir(clock1, clock2);
  printf("----------------\n");
  // Insere uma página além da capacidade
  printf("Relógio com uma página a mais\n");
  Pagina pag6 = {6, true};
  inserirPagina(&clock1, &clock2, pag6);
  exibir(clock1, clock2);
  return 0;
}
