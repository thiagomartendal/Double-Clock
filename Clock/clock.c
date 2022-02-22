#include "clock.h"

// Prepara o relógio para receber as páginas de memória
void iniciar(Clock *clock, int totalPaginas) {
  clock->ponteiro = 0;
  clock->totalPaginas = totalPaginas;
  clock->buffer.paginas = malloc(totalPaginas*sizeof(Pagina));
  //new Pagina[totalPaginas];
  clock->buffer.tamanho = 0;
}

// Insere uma página no relógio
void inserirPagina(Clock *clock, Pagina pagina) {
  Buffer *buffer = &clock->buffer;
  if (buffer->tamanho == clock->totalPaginas) { // Se o buffer estiver cheio o relógio movimenta-rá o ponteiro para remover uma página com bit 0 e adicionar a nova página
    for (int i = 0; i < buffer->tamanho; i++) {
      Pagina *pag = &buffer->paginas[i];
      if (pag->bitR) { // Se o bit for 1 atualiza o bit para 0 e avança o ponteiro
        pag->bitR = false;
        avancarPonteiro(clock);
        if (i == clock->totalPaginas-1) { // Se a ultima página no relógio for 1, atualiza o indice i para percorrer o relógio novamente
          i = -1;
        }
      } else { // Se o bit for 0 remove a página antiga da posição e adiciona a página nova em seu lugar
        buffer->paginas[i] = pagina;
        avancarPonteiro(clock);
        break;
      }
    }
  } else { // Se o buffer ainda não está cheio adiciona a página
    inserir(buffer, pagina);
  }
}

// Método que controla o avanço do ponteiro
void avancarPonteiro(Clock *clock) {
  if (clock->ponteiro == clock->totalPaginas-1) { // Se o ponteiro for igual ao total de páginas-1 retorna para a posição inicial do relógio, realizando a circularidade
    clock->ponteiro = 0;
  } else { // Se não o ponteiro é incrementado
    clock->ponteiro++;
  }
}
