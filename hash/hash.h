#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#define VAZIO -1
#define DUMMY -2
#define MAX_TABELA 1000
#define MAX_PALAVRA 20

typedef long long int tabela_hash;

/*
  Parâmetros:
  h: estrutura de hash em enderaçamento aberto
  m: tamanho da tabela de espalhamento (hash)

  Função: Inicializa a tabela valor VAZIO
*/
void inicializa_hash(tabela_hash *h, int m);

/*
  Parâmetros:
  h: estrutura de hash em enderaçamento aberto
  k: representação numérica da palavra
  int p: um primo maior que MAX
  int a: inteiro pertencente a {1,...,p}
  int b: inteiro pertencente a {0,...,p}

  Função: Insere um valor na tabela hash
*/
void inserir(tabela_hash h[], long long int k,int p, int a, int b, int m);

/*
  Parâmetros:
  h: estrutura de hash em enderaçamento aberto
  k: representação numérica da palavra a ser removida
  int p: um primo maior que m (tamanho da tabela)
  int a: inteiro pertencente a {1,...,p}
  int b: inteiro pertencente a {0,...,p}

  Função: Remove um valor da estrutura hash
*/
void remover_rehash(tabela_hash h[], long long int k, int p, int a, int b, int m);
void remover_dummy(tabela_hash h[], long long int k, int p, int a, int b, int m);

/*
  Parâmetros:
  char *chave: Uma das strings recebida como entrada

  Função: Obtém a representação númerica de uma palavra. Utilizada dentro da função func_hash()
*/
long long int converte_chave_para_llint(char *chave);
/*
  Parâmetros:
  k: representação numérica da palavra
  int p: um primo maior que m (tamanho da tabela)
  int a: inteiro pertencente a {1,...,p}
  int b: inteiro pertencente a {0,...,p}

  Função: Aplica a função hash sobre o elemento k (corresponde a uma posição na tabela hash)
*/
int func_hash(long long int k, int p, int a, int b, int m);

/*
  Parâmetros:
  h: estrutura de hash em enderaçamento aberto
  k: representação numérica da palavra
  int p: um primo maior m
  int a: inteiro pertencente a {1,...,p}
  int b: inteiro pertencente a {0,...,p}
  int m: tamanho da tabela de hash h

  Função: Procura por um valor da estrutura hash, se encontra devolve seu índice, caso contrário devolve -1
*/
int buscar(tabela_hash h[], long long int k, int p, int a, int b, int m);


/*
  ATENÇÃO: NÃO IMPLEMENTE ESTA FUNÇÃO!!!
  Parâmetros:
  h: hash com remoção por rehash
  g: hash com remoção por substituição por valor dummy
  m: tamanho do hash

  Função: imprime ambos hashs no formato adequado
*/
void imprimir_saida(tabela_hash h[], tabela_hash g[], int m);

#endif // HASH_H_INCLUDED
