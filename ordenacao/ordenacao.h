/*
 * Definicoes gerais
 */

#define MAX 10000
#define F_ESQ(i) (2*i+1)
#define F_DIR(i) (2*i+2)

/*
 * Algoritmos de busca
 *
 * Todos recebem, como parametro adicional aos tradicionais, um
 * apontador para um contador que deve ser utilizado para contar o
 * numero de comparacoes feitas durante o curso do algoritmo.
 */
void heapsort(int *v, int n, int *contador);
void mergesort(int *v, int l, int r, int *contador);
void quicksort(int *v, int l, int r, int *contador);

/*
 * Algoritmo de avaliacao
 *
 * vetorHeap, vetorMerge, vetorQuick: vetores ordenados utilizando o respectivo algoritmo;
 * contadorHeap, contadorMerge, contadorQuick: contadores de comparacoes referentes a execucao de cada algoritmo;
 * n: tamanho da entrada do problema.
 */
void avalia_ordenacao(int *vetorHeap, int *vetorMerge, int *vetorQuick,
        int contadorHeap, int contadorMerge, int contadorQuick, int n);
