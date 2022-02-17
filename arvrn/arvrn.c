#include <stdio.h>
#include <stdlib.h>
#include "arvrn.h"

/**************DEFINIÇÃO DAS FUNÇÕES DO ARQUIVO arvrn.h**************/
/*essenciais para a manipulação da arvore rn*/
p_no inserir(p_no raiz, int chave){
  raiz = inserir_rec(raiz, chave);
  raiz->cor = PRETO;
  return raiz;
}

p_no inserir_rec(p_no raiz, int chave){
  p_no novo;

  if(raiz == NULL){
    novo = malloc(sizeof(No));
    novo->esq = novo->dir = NULL;
    novo->chave = chave;
    novo->cor = VERMELHO;
    return novo;
  }
  if(chave < raiz->chave)
    raiz->esq = inserir_rec(raiz->esq, chave);
  else
    raiz->dir = inserir_rec(raiz->dir, chave);

  /**CONSERTA ARVORE **/
  if(ehVermelho(raiz->dir) && ehPreto(raiz->esq))
    raiz = rotaciona_para_esquerda(raiz);
  if(ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
    raiz = rotaciona_para_direita(raiz);
  if(ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
    sobe_vermelho(raiz);
  return raiz;
}


void sobe_vermelho(p_no raiz){
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

p_no rotaciona_para_direita(p_no raiz){
  p_no x = raiz->esq;
  raiz->esq = x->dir;
  x->dir = raiz;
  x->cor = raiz->cor;
  raiz->cor = VERMELHO;
  return x;
}

p_no rotaciona_para_esquerda(p_no raiz){
  p_no x = raiz->dir;
  raiz->dir = x->esq;
  x->esq = raiz;
  x->cor = raiz->cor;
  raiz->cor = VERMELHO;
  return x;
}

int ehPreto(p_no x){
  if(x == NULL)
    return 1;
  return x->cor == PRETO;
}

int ehVermelho(p_no x){
  if(x == NULL)
    return 0;
  return x->cor == VERMELHO;
}

void destroi_arvore(p_no raiz){
  if ( raiz != NULL ) {
    destroi_arvore(raiz->esq);
    destroi_arvore(raiz->dir);
    free(raiz);
   }
 }

/****************PROPRIEDADES IMPLEMENTADAS********************/

//Profundidade negra
int profundidade(p_no raiz, int chave){
  if(chave == raiz->chave)
    return 0;
  if(chave < raiz->chave && raiz->cor == PRETO)
    return 1 + profundidade(raiz->esq, chave);
  if(chave > raiz->chave && raiz->cor == PRETO)
    return 1 + profundidade(raiz->dir, chave);
  else{
    if(chave < raiz->chave)
      return 0 + profundidade(raiz->esq, chave);
    else
      return 0 + profundidade(raiz->dir, chave);
  }
}

//Altura negra
int altura (p_no atual){
  if (atual == NULL)
    return 0;
  else{
    if (atual->cor == PRETO)
      return 1 + altura(atual->esq);
    else
      return 0 + altura(atual->esq);
  }
}

//Piso (floor)
void find_floor(p_no raiz, int key_floor_ceil, int *floor){
  if(raiz != NULL){
    if(raiz->chave > *floor && raiz->chave <= key_floor_ceil){
      *floor = raiz->chave;
    }
    find_floor(raiz->esq, key_floor_ceil, floor);
    find_floor(raiz->dir, key_floor_ceil, floor);
  }
}

/*encontra_maximo é função auxiliar para a função ceil (chamada na main), já que não foi
 definido um valor MAXIMO previamente, retorna a maior chave da arvorern*/
int encontra_maximo(p_no raiz) {
    int valor_raiz;
    int valor_esquerda;
    int valor_direita;

    if(raiz == NULL)
      return 0;

    valor_raiz = raiz->chave;
    valor_esquerda = encontra_maximo(raiz->esq);
    valor_direita = encontra_maximo(raiz->dir);
    if (valor_esquerda > valor_raiz)
      valor_raiz = valor_esquerda;
    if (valor_direita > valor_raiz)
      valor_raiz = valor_direita;
    return valor_raiz;
}

//Teto (ceil) --- se houver um ceil, ela encontra, correção em caso de não haver feita na main
void find_ceil(p_no raiz, int key_floor_ceil, int *ceil){
  if(raiz != NULL){
    if(raiz->chave < *ceil && raiz->chave >= key_floor_ceil)
      *ceil = raiz->chave;
    find_ceil(raiz->esq, key_floor_ceil, ceil);
    find_ceil(raiz->dir, key_floor_ceil, ceil);
  }
}
