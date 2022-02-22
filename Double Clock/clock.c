#include "clock.h"

// Prepara o relógio para receber as páginas de memória
void iniciarClock1(Clock1 *clock, int totalPaginas) {
  clock->ponteiro = 0;
  clock->totalPaginas = totalPaginas;
  clock->buffer.paginas = malloc(totalPaginas*sizeof(Pagina));
  clock->buffer.tamanho = 0;
}

void iniciarClock2(Clock2 *clock, int totalPaginas) {
  clock->ponteiro = 0;
  clock->totalPaginas = totalPaginas;
  clock->buffer.paginas = malloc(totalPaginas*sizeof(Pagina));
  clock->buffer.tamanho = 0;
}

// Insere uma página no relógio 1
// void inserirPaginaClock1(Clock1 *clock, Pagina pagina) {
//   Buffer *buffer = &clock->buffer;
//   if (buffer->tamanho == clock->totalPaginas) { // Se o buffer estiver cheio o relógio movimenta-rá o ponteiro para remover uma página com bit 0 e adicionar a nova página
//     for (int i = 0; i < buffer->tamanho; i++) {
//       Pagina *pag = &buffer->paginas[i];
//       if (pag->bitR) { // Se o bit for 1 atualiza o bit para 0 e avança o ponteiro
//         pag->bitR = false;
//         avancarPonteiro(clock);
//         if (i == clock->totalPaginas-1) { // Se a ultima página no relógio for 1, atualiza o indice i para percorrer o relógio novamente
//           i = -1;
//         }
//       } else { // Se o bit for 0 remove a página antiga da posição e adiciona a página nova em seu lugar
//         buffer->paginas[i] = pagina;
//         avancarPonteiro(clock);
//         break;
//       }
//     }
//   } else { // Se o buffer ainda não está cheio adiciona a página
//     inserir(buffer, pagina);
//   }
// }

// Insere uma página no relógio 2
void inserirPaginaClock2(Clock1 *clock1, Clock2 *clock2, Pagina pagina) {
  Buffer *buffer1 = &clock1->buffer;
  Buffer *buffer2 = &clock2->buffer;
  if (buffer2->tamanho == clock2->totalPaginas) { // Se o buffer estiver cheio o relógio movimenta-rá o ponteiro para remover uma página com bit 0 e adicionar a nova página
    for (int i = 0; i < buffer2->tamanho; i++) {
      Pagina *pag = &buffer2->paginas[i];
      if (pag->bitR) { // Se o bit for 1 atualiza o bit para 0 e avança o ponteiro
        pag->bitR = false;
        avancarPonteiro(clock2);
        if (i == clock2->totalPaginas-1) { // Se a ultima página no relógio for 1, atualiza o indice i para percorrer o relógio novamente
          i = -1;
        }
      } else { // Se o bit for 0 remove a página antiga da posição e adiciona a página nova em seu lugar
        buffer2->paginas[i] = pagina;
        int pos = 0;
        if (clock1->ponteiro == 0) {
          pos = buffer1->tamanho-1;
        } else {
          pos = clock1->ponteiro-1;
        }
        buffer1->paginas[pos] = pagina;
        avancarPonteiro(clock2);
        break;
      }
    }
  } else { // Se o buffer ainda não está cheio adiciona a página
    inserir(buffer2, pagina);
  }
}

void inserirPagina(Clock1 *clock1, Clock2 *clock2, Pagina pagina) {
  Buffer *buffer1 = &clock1->buffer;
  if (buffer1->tamanho == clock1->totalPaginas) { // Se o buffer estiver cheio o relógio movimenta-rá o ponteiro para remover uma página com bit 0 e adicionar a nova página
    for (int i = 0; i < buffer1->tamanho; i++) {
      Pagina *pag = &buffer1->paginas[i];
      if (!pag->bitR && !pag->bitM) {
        buffer1->paginas[i] = pagina;
        avancarPonteiro(clock1);
        break;
      } else if (pag->bitR && !pag->bitM) {
        pag->bitR = false;
        avancarPonteiro(clock1);
        if (i == clock1->totalPaginas-1) { // Se a ultima página no relógio for 1, atualiza o indice i para percorrer o relógio novamente
          i = -1;
        }
      } else if (pag->bitM) {
        Pagina p;
        p.paginaVazia = true;
        buffer1->paginas[i] = p;
        inserirPaginaClock2(clock1, clock2, *pag);
        // inserirPaginaClock2(clock1, clock2, pagina);
        avancarPonteiro(clock1);
        // break;
      }
      if (i == buffer1->tamanho-1) {
        inserirPaginaClock2(clock1, clock2, *pag);
      }
    }
  } else { // Se o buffer ainda não está cheio adiciona a página
    inserir(buffer1, pagina);
  }
}

// void inserirPagina(Clock1 *clock1, Clock2 *clock2, Pagina pagina) {
//   Buffer *buffer1 = &clock1->buffer;
//   if (buffer1->tamanho < clock1->totalPaginas) {
//     inserirPaginaClock1(clock1, pagina);
//   } else {
//     Pagina *pagClock1 = &buffer1->paginas[clock1->ponteiro];
//     if ((pagClock1->bitR == false) && (pagClock1->bitM == false)) {
//
//     } else if ((pagClock1->bitR == true) && (pagClock1->bitM == false)) {
//
//     } else if (pagClock1->bitM == true) {
//
//     }
//   }
// }

// Método que controla o avanço do ponteiro
void avancarPonteiro(Clock1 *clock) {
  if (clock->ponteiro == clock->totalPaginas-1) { // Se o ponteiro for igual ao total de páginas-1 retorna para a posição inicial do relógio, realizando a circularidade
    clock->ponteiro = 0;
  } else { // Se não o ponteiro é incrementado
    clock->ponteiro++;
  }
}
