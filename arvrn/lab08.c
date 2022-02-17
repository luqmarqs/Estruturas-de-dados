/*LAB08 - ALUNO: LUCAS MARQUES DE ALMEIDA, 137207*/
#include <stdio.h>
#include <stdlib.h>
#include "arvrn.h"

//impressão em pré-ordem definida no final desse arquivo
void pre_ordem ( p_no atual, p_no raiz );

///funções definidas no arquivo arvrn.c
int profundidade(p_no raiz, int chave);
int altura (p_no atual);
void find_floor(p_no raiz, int key_floor_ceil, int *floor);
void find_ceil(p_no raiz, int key_floor_ceil, int *ceil);
int encontra_maximo(p_no raiz);

/*******MAIN*******/
int main() {

  int i, tamanho, key_floor_ceil, key_temp, floor = -1, ceil;
  p_no arvrn = NULL, atual;

  scanf("%d", &tamanho);

  for(i = 0; i < tamanho; i++){
    scanf("%d", &key_temp);
    arvrn = inserir(arvrn, key_temp);
  }

  scanf("%d", &key_floor_ceil);

  atual = arvrn;
  pre_ordem(atual, arvrn);

  ceil = encontra_maximo(arvrn);

  find_floor(arvrn, key_floor_ceil, &floor);
  find_ceil(arvrn, key_floor_ceil, &ceil);

  //CORRIGE O CEIL
  if(ceil < key_floor_ceil)
    ceil = -1;

  printf("teto de %d = %d \n", key_floor_ceil, ceil);
  printf("piso de %d = %d \n", key_floor_ceil, floor);

  destroi_arvore(arvrn);

  return 0;
}

/****IMPRESSÃO EM PRÉ-ORDEM*****/
void pre_ordem (p_no atual, p_no raiz) {
  int no_prof, no_altura = 0;
  char cor[10];
  if ( atual != NULL ) {
    no_prof = profundidade(raiz, atual->chave);
    no_altura = altura(atual);
    if(atual->cor == PRETO){
      cor[0] = 'P';
      cor[1] = 'R';
      cor[2] = 'E';
      cor[3] = 'T';
      cor[4] = 'O';
      cor[5] = '\0';
    }
    if(atual->cor == VERMELHO){
      cor[0] = 'V';
      cor[1] = 'E';
      cor[2] = 'R';
      cor[3] = 'M';
      cor[4] = 'E';
      cor[5] = 'L';
      cor[6] = 'H';
      cor[7] = 'O';
      cor[8] = '\0';
    }
    printf("valor = %d ; cor = %s ; altura negra = %d; profundidade negra = %d;\n", atual->chave, cor, no_altura, no_prof);
    pre_ordem (atual->esq, raiz) ;
    pre_ordem (atual->dir, raiz) ;
  }
}
