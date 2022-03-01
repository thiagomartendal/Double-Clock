#include "clock.h"

void iniciar(Clock *C1, Clock *C2, int tamanhoMoldura) {
  C1->ponteiro = 0;
  C1->totalPaginas = tamanhoMoldura;
  C1->paginasInseridas = 0;
  C1->paginas = malloc(tamanhoMoldura*sizeof(Pagina));
  C2->ponteiro = 0;
  C2->totalPaginas = tamanhoMoldura;
  C2->paginasInseridas = 0;
  C2->paginas = malloc(tamanhoMoldura*sizeof(Pagina));
}

void inserirPagina(Clock *C1, Clock *C2, Pagina pagina) {
  if (C1->paginasInseridas < C1->totalPaginas) { // Passo 1
    C1->paginas[C1->paginasInseridas] = pagina;
    C1->paginasInseridas++;
  } else { // Passo 2
    Pagina *paginaPonteiro = &C1->paginas[C1->ponteiro];
    int passo2ai = 0;
    if ((paginaPonteiro->bitR == 0) && (paginaPonteiro->bitM == 0)) { // Passo 2-a-i
      C1->paginas[C1->ponteiro] = pagina;
      avancarPonteiro(C1);
      passo2ai = 1;
    } else if ((paginaPonteiro->bitR == 1) && (paginaPonteiro->bitM == 0)) { // Passo 2-1-ii
      paginaPonteiro->bitR = 0;
      avancarPonteiro(C1);
      inserirPagina(C1, C2, pagina);
    } else if (paginaPonteiro->bitM == 1) { // Passo 2-a-iii
      if (paginaPonteiro->bitR == 1) {
        paginaPonteiro->bitR = 0;
      }
      C2->paginas[C2->paginasInseridas] = *paginaPonteiro;
      C2->paginasInseridas++;
      removerPagina(C1, C1->ponteiro);
      avancarPonteiro(C1);
      inserirPagina(C1, C2, pagina);
    }
    if (C1->ponteiro == C1->totalPaginas-1) { // Passo 2b
      if (passo2ai == 0) { // O passo 2b só é executado caso o passo 2-a-i não tenha sido executado
        clockClassico(C1, C2, pagina);
      } else {
        passo2ai = 0;
      }
    }
  }
}

void removerPagina(Clock *C1, int pos) { // Remove uma página da posição do array de páginas
  for(int i = pos; i < C1->paginasInseridas-1; i++) C1->paginas[i] = C1->paginas[i+1];
  C1->paginasInseridas--;
}

void clockClassico(Clock *clock1, Clock *clock2, Pagina pagina) { // Algoritmo clássico do relógio
  if (clock2->paginasInseridas < clock2->totalPaginas) { // Insere páginas enquanto o relógio tem espaço
    clock2->paginas[clock2->paginasInseridas] = pagina;
    clock2->paginasInseridas++;
  } else { // Quando o relógio não tem mais espaço
    Pagina *paginaPonteiro = &clock2->paginas[clock2->ponteiro]; // Avalia a página do ponteiro
    if (paginaPonteiro->bitR == 1) { // Se o bit R == 1 seta para 0
      paginaPonteiro->bitR = 0;
      avancarPonteiro(clock2);
      clockClassico(clock1, clock2, pagina);
    } else if (paginaPonteiro->bitR == 0) { // Se o bit R == 0 substitui a página do ponteiro
      clock2->paginas[clock2->ponteiro] = pagina;
      // Quando ocorre uma substituição de página no relógio 2, a nova página é inserida em uma posição após o ponteiro do relógio 1
      if (clock1->ponteiro == clock1->totalPaginas-1) {
        clock1->paginas[0] = pagina;
      } else {
        clock1->paginas[clock1->ponteiro+1] = pagina;
      }
      avancarPonteiro(clock2);
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
