#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"


/*******FUNÇÕES AUXILIARES*******/
void troca (int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

//auxiliar para o heapsort
void desce_no_heap (int *heap, int n, int k, int *contador){
  int maior_filho;
  (*contador)++;
  if (F_ESQ(k) < n) {
    maior_filho = F_ESQ(k);
    (*contador) = (*contador) +2;
    if(F_DIR(k) < n && heap[F_ESQ(k)] < heap[F_DIR(k)])
      maior_filho = F_DIR(k);
    (*contador)++;
    if(heap[k] < heap[maior_filho]){
      troca(&heap[k], &heap[maior_filho]);
      desce_no_heap(heap, n, maior_filho, contador);
    }
  }
}

//auxiliar para o mergesort
void merge(int *v, int l, int m, int r, int *contador){
  int aux[MAX];
  int i = l, j = m + 1, k = 0;
  while( i <= m && j <= r){
    (*contador)++;
    (*contador)++;
    if(v[i] <= v[j])
      aux[k++] = v[i++];
    else
      aux[k++] = v[j++];
    }
  (*contador)++;
  while (i <= m){
    (*contador)++;
    aux[k++] = v[i++];
  }
  (*contador)++;
  while (j <= r){
    (*contador)++;
    aux[k++] = v[j++];
  }
  (*contador)++;
  for(i = l, k = 0; i <= r; i++, k++){
    (*contador)++;
    v[i] = aux[k];
  }
  (*contador)++;
}

//auxiliar para o quicksort
int partition (int *v, int l, int r, int *contador) {
  int i, pivo = v[l], pos = r+1;
  for(i = r; i >= l; i--){
    (*contador) = (*contador) + 2;
    if (v[i] >= pivo) {
      pos--;
      troca(&v[i], &v[pos]);
    }
  }
  (*contador)++;
  return pos;
}

/*******IMPLEMENTAÇÃO DOS ALGORITMOS DE ORDENAÇÃO*******/

void heapsort(int *v, int n, int *contador){
  int k;
  for (k = n/2; k >= 0; k--){
    (*contador)++;
    desce_no_heap(v, n, k, contador);
  }
  (*contador)++;
  while(n > 1){
    (*contador)++;
    troca(&v[0], &v[n - 1]);
    n--;
    desce_no_heap(v, n, 0, contador);
  }
  (*contador)++;
}

void mergesort(int *v, int l, int r, int *contador){
  int m = (l + r) / 2;
  (*contador)++;
  if(l < r){
    mergesort(v, l, m, contador);
    mergesort(v, m+1, r, contador);
    merge(v, l, m, r, contador);
  }
}

void quicksort(int *v, int l, int r, int *contador){
  int i;
  (*contador)++;
  if(r <= l) return;
  i = partition(v, l, r, contador);
  quicksort(v, l, i-1, contador);
  quicksort(v, i+1, r, contador);
}
