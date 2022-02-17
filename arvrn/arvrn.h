#ifndef ARVRN_H_INCLUDED
#define ARVRN_H_INCLUDED

#include <stdio.h>

enum Cor { VERMELHO , PRETO };

typedef struct No {
    int chave ;
    enum Cor cor ;
    struct No * esq , * dir ;
} No ;

typedef No * p_no ;

p_no inserir(p_no raiz, int chave);
p_no inserir_rec(p_no raiz, int chave);
void sobe_vermelho(p_no raiz);
p_no rotaciona_para_direita(p_no raiz);
p_no rotaciona_para_esquerda(p_no raiz);
int ehPreto(p_no x);
int ehVermelho(p_no x);
void destroi_arvore(p_no raiz);

#endif
