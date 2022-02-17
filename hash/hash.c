
#include <stdio.h>
#include <string.h>
#include "hash.h"


void inicializa_hash(tabela_hash *h, int m){
  int i;
  for (i = 0; i < m; i++)
    h[i] = VAZIO;
}

void inserir(tabela_hash h[], long long int k,int p, int a, int b, int m){
  int numero_hash;
  numero_hash = func_hash(k, p, a, b, m);
  if (h[numero_hash] == VAZIO)
    h[numero_hash] = k;
    else{
      while (h[numero_hash] != VAZIO && numero_hash < m){
        numero_hash++;
      }
      if(h[numero_hash] == VAZIO)
        h[numero_hash] = k;
      else{
        numero_hash = 0;
        while (h[numero_hash] != VAZIO && numero_hash < m){
          numero_hash++;
        }
        if(h[numero_hash] == VAZIO)
          h[numero_hash] = k;

      }
    }
  }

//auxiliar para remover_rehash
  void rehash (tabela_hash h[], int numero_busca, int p, int a, int b, int m){
    long long int hash_temp [m];
    int i = numero_busca+1, j=0;
    inicializa_hash(hash_temp, m);
    while (i < m && h[i] != VAZIO){
      hash_temp[j] = h[i];
      h[i] = VAZIO;
      if(i == m-1)
        i = -1;
      i++;
      j++;
    }
    for(i = 0; i < m; i++){
      inserir(h, hash_temp[i], p, a, b, m);
    }
  }

void remover_rehash(tabela_hash h[], long long int k, int p, int a, int b, int m){
  int numero_hash;
  numero_hash = buscar(h, k, p, a, b, m);
  if (numero_hash >= 0){
    h[numero_hash] = VAZIO;
    rehash(h, numero_hash, p, a, b, m);
  }
}

void remover_dummy(tabela_hash h[], long long int k, int p, int a, int b, int m){
  int numero_hash;
  numero_hash = buscar(h, k, p, a, b,m);
  if (numero_hash >= 0)
    h[numero_hash] = DUMMY;
}

long long int converte_chave_para_llint(char *chave){
  long long int x = 0;
  int i, tam;
  tam = strlen(chave);
  for (i = 0; i < tam; i++){
    x = 256 * x + chave[i];
  }
  return x;
}

int func_hash(long long int k, int p, int a, int b, int m){
  int numero_hash;
  numero_hash = ((a*k + b) % p) % m;
  return numero_hash;
}

int buscar(tabela_hash h[], long long int k, int p, int a, int b, int m){
  int numero_hash;
  numero_hash = func_hash(k, p, a, b, m);
  if (h[numero_hash] == k){
    return numero_hash;
  }else{
    while(h[numero_hash] != k && numero_hash < m){
      numero_hash++;
    }
    if (h[numero_hash] == k)
      return numero_hash;
    else{
      numero_hash = 0;
      while(h[numero_hash] != k && numero_hash < m){
        numero_hash++;
      }
      if (h[numero_hash] == k)
        return numero_hash;
      else
        return -1;
      }
    }
  }
