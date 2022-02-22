#ifndef PAGINA_H
#define PAGINA_H

#include <stdbool.h>

// Estrutura que representa uma página de memória

typedef struct Pagina {
  int numero;
  bool bitR;
  bool bitM;
  bool paginaVazia;
} Pagina;

#endif
