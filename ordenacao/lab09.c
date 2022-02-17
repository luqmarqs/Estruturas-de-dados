/*LAB 09
*Aluno: Lucas Marques
*RA: 137207
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"


int main(void) {
  int i, n, contador_heap = 0, contador_merge = 0, contador_quick = 0;
  int *v_heap, *v_merge, *v_quick;

  scanf("%d", &n);

  v_heap = malloc(n*sizeof(int));
  v_merge = malloc(n*sizeof(int));
  v_quick = malloc(n*sizeof(int));

  for (i = 0; i < n; i++){
    scanf("%d", &v_heap[i]);
    v_merge[i] = v_heap[i];
    v_quick[i] = v_heap[i];
  }

  heapsort(v_heap, n, &contador_heap);

  mergesort(v_merge, 0, n-1, &contador_merge);

  quicksort(v_quick, 0, n-1, &contador_quick);

  avalia_ordenacao(v_heap, v_merge, v_quick,
          contador_heap, contador_merge, contador_quick, n);

  free(v_heap);
  free(v_merge);
  free(v_quick);

  return 0;
}
