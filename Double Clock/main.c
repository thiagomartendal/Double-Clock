#include <stdio.h>
#include "clock.h"

void exibir(Clock c) {
  for (int i = 0; i < c.paginasInseridas; i++) {
    printf("Página: {%d, %d, %d}\n", c.paginas[i].numero, c.paginas[i].bitR, c.paginas[i].bitM);
  }
}

void teste() {
  int totalMoldurasPagina = 8;
  Pagina pag5 = {5, 1, 0};
  Pagina pag12 = {12, 1, 1};
  Pagina pag97 = {97, 1, 0};
  Pagina pag9 = {9, 0, 0};
  Pagina pag31 = {31, 1, 0};
  Pagina pag65 = {65, 1, 1};
  Pagina pag49 = {49, 0, 0};
  Pagina pag3 = {3, 0, 0};
  Pagina pag25 = {25, 0, 1};
  Pagina pag77 = {77, 1, 1};
  Pagina pag18 = {18, 0, 1};
  Pagina pag83 = {83, 0, 1};
  Clock c1;
  Clock c2;
  iniciar(&c1, &c2, totalMoldurasPagina);
  inserirPagina(&c1, &c2, pag5);
  inserirPagina(&c1, &c2, pag25);
  inserirPagina(&c1, &c2, pag97);
  inserirPagina(&c1, &c2, pag77);
  inserirPagina(&c1, &c2, pag31);
  inserirPagina(&c1, &c2, pag18);
  inserirPagina(&c1, &c2, pag49);
  inserirPagina(&c1, &c2, pag83);
  inserirPagina(&c1, &c2, pag12);
  inserirPagina(&c1, &c2, pag9);
  inserirPagina(&c1, &c2, pag65);
  inserirPagina(&c1, &c2, pag3);
  exibir(c1);
  printf("------------\n");
  exibir(c2);
  free(c1.paginas);
  free(c2.paginas);
}

int main() {
  teste();
  return 0;
}
