/* ======================================= */
/* ===== Estrutura de arvore binaria ===== */
/* ======================================= */

/* No
 * Estrutura que representa um no de uma arvore. Note que uma arvore
 * eh definida pelo conjunto de seus nos, a partir do no raiz.
 */
typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

/* p_no
 * Apontador para uma estrutura do tipo No.
 */
typedef No* p_no;

/* ================================== */
/* ===== Funcoes de manipulacao ===== */
/* ================================== */

/* cria_no
 * Cria um no com o valor dado pelo parametro, com filhos esquerdo e
 * direito vazios (no "isolado", que pode ser "ligado" a uma arvore
 * posteriormente).
 * 
 * valor: valor inteiro associado ao no que sera criado. 
 */
p_no cria_no(int valor);

/* pos_ordem
 * Impressao do conteudo de uma arvore em pos_ordem, de forma recursiva.
 *
 * no_atual: apontador para o no atualmente sob analise.
 */
void pos_ordem(p_no no_atual);

/* libera_arvore
 * Libera, recursivamente, toda memoria alocada de uma arvore.
 * 
 * no_atual: apontador para o no atualmente sob analise.
 */
void libera_arvore(p_no no_atual);