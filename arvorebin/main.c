#include <stdio.h>
#include <stdlib.h>
#include "arvorebin.h"

p_no build (int *v_preordem, int *v_inordem, int *indice_preordem, int inicio_limite_inordem, int fim_limite_inordem);

int main() {
  
  int indice_preordem, tam, i, temp, inicio_limite_inordem, fim_limite_inordem;
	int *v_inordem, *v_preordem;
	p_no bintree;

  indice_preordem = 0;

  scanf("%d ", &tam);
  //se for 0 nao entra no processamento
  if (tam != 0 ){
    v_preordem = malloc(tam * sizeof(int));
    v_inordem = malloc(tam * sizeof(int));
    if (v_preordem && v_inordem){
      for (i = 0; i < tam; i++){
        scanf("%d", &temp);
        v_preordem[i] = temp;
      }
      for (i = 0; i < tam; i++){
        scanf("%d", &temp);
        v_inordem[i] = temp;
      }

      //inicializa os contadores pelo primeiro e pelo ultimo indices do vetor
      inicio_limite_inordem = 0;
      fim_limite_inordem = tam - 1;
      
      bintree = build (v_inordem, v_preordem, &indice_preordem, inicio_limite_inordem, fim_limite_inordem);

      pos_ordem(bintree);
      printf("\n");

      libera_arvore(bintree);
      free(v_inordem);
      free(v_preordem);
    }
  }
  return 0;
}

//funcao "build" constroi a arvore
p_no build(int *v_inordem, int *v_preordem, int *indice_preordem, int inicio_limite_inordem, int final_limite_inordem){
  int valor, i;
  p_no novo;

  if(inicio_limite_inordem > final_limite_inordem){
    return NULL;
  }

  valor = v_preordem[*indice_preordem];
  *indice_preordem = *indice_preordem + 1;
  novo = cria_no(valor);
  i = inicio_limite_inordem;
  while(v_inordem[i] != valor)
    i++;
  
  novo->esq = build(v_inordem,v_preordem,indice_preordem,inicio_limite_inordem, i-1);
  novo->dir = build(v_inordem,v_preordem,indice_preordem,i+1,final_limite_inordem);

  return novo;
}



