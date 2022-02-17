#include <stdio.h>
#include <stdlib.h>
#include "arvorebin.h"

p_no cria_no(int valor){
  p_no novo = malloc (sizeof(No));;

  if(novo){
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
  }
  return novo;
}

void pos_ordem(p_no no_atual){
  if (no_atual != NULL){
    pos_ordem(no_atual->esq);
    pos_ordem(no_atual->dir);
    printf("%d ", no_atual->valor);
  }
}

void libera_arvore(p_no no_atual){
  if (no_atual != NULL){
    libera_arvore(no_atual->esq);
    libera_arvore(no_atual->dir);
    free(no_atual);
  }
}
