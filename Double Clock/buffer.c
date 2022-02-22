#include "buffer.h"

void inserir(Buffer *buffer, Pagina pagina) {
  buffer->paginas[buffer->tamanho] = pagina;
  buffer->tamanho++;
}
