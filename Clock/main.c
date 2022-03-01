#include <stdio.h>
#include "clock.h"

void exibir(Clock c) {
  for (int i = 0; i < c.paginasInseridas; i++) {
    printf("Página: {%d, %d}\n", c.paginas[i].numero, c.paginas[i].bitR);
  }
}

void teste() {
  int totalMoldurasPagina = 8;
  Pagina pag5 = {5, 1};
  Pagina pag12 = {12, 1};
  Pagina pag97 = {97, 0};
  Pagina pag9 = {9, 1};
  Pagina pag31 = {31, 0};
  Pagina pag65 = {65, 0};
  Pagina pag49 = {49, 1};
  Pagina pag3 = {3, 1};
  Pagina pag58 = {58, 1};
  Clock c1;
  iniciar(&c1, totalMoldurasPagina);
  inserirPagina(&c1, pag5);
  inserirPagina(&c1, pag12);
  inserirPagina(&c1, pag97);
  inserirPagina(&c1, pag9);
  inserirPagina(&c1, pag31);
  inserirPagina(&c1, pag65);
  inserirPagina(&c1, pag49);
  inserirPagina(&c1, pag3);
  inserirPagina(&c1, pag58);
  exibir(c1);
  free(c1.paginas);
}

int main() {
  teste();
  return 0;
}
