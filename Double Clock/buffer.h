#ifndef BUFFER_H
#define BUFFER_H

#include "pagina.h"

// Estrutura que representa o buffer de dados

typedef struct Buffer {
  Pagina *paginas;
  int tamanho;
} Buffer;

void inserir(Buffer *buffer, Pagina pagina);

#endif
