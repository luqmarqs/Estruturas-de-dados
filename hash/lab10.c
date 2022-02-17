/* LAB10
** ALUNO: Lucas Marques de Almeida, RA: 137207 */
#include <stdio.h>
#include <string.h>
#include "hash.h"

int main(){
  int i, n, k, m, p, a, b;
  long long int hash1[MAX_TABELA], hash2[MAX_TABELA], numero_palavra;
  char palavra [MAX_PALAVRA];

  scanf("%d %d %d %d", &m, &p, &a, &b);
  scanf("%d ", &n);
  if(m > 0 && n>0){
    inicializa_hash(hash1, m);
    inicializa_hash(hash2, m);
    for (i = 0; i < n; i++){
      scanf("%s", palavra);
      numero_palavra = converte_chave_para_llint(palavra);
      inserir(hash1, numero_palavra, p, a, b, m);
      inserir(hash2, numero_palavra, p, a, b, m);
    }
  }

  scanf("%d ", &k);
  if(k > 0){
    for (i = 0; i < k; i++){
      scanf("%s", palavra);
      numero_palavra = converte_chave_para_llint(palavra);
      remover_rehash (hash1, numero_palavra, p, a, b, m);
      remover_dummy (hash2, numero_palavra, p, a, b, m);
    }
  }

  imprimir_saida(hash1, hash2, m);

  return 0;
}
