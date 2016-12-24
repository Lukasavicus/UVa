/**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Outras Fontes razoaveis:
 * http:/*www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/digraphdatastructs.html#DIGRAPHlists-library
 * http:/*www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/digraphdatastructs.html#DIGRAPHmatrix-library
 *
 */

/* ========= CORES =========== */
#define BRANCO 0
#define CINZA 1
#define PRETO 2
/* +++++++++++++++++++++++++++ */

/* ========== INFOS ========== */
#define INF -1 			/* DISTANCIAS */
#define RAIZ -1 		/* PREDECESSORES */
#define TZERO -1 		/* TEMPOS */
#define SEM_GRUPO -1 	/* GRUPOS */
/* +++++++++++++++++++++++++++ */

/* ===== OPCOES - INSERE ===== */
#define INICIO 		0
#define FIM 		1

#define COM_REP 	0
#define SEM_REP 	1

#define SEM_PESO	0
#define COM_PESO	1
/* +++++++++++++++++++++++++++ */

#define BIG 2147483647

/* ==== ESTRUTURAS E TIPOS === */
typedef int tipo_info;
typedef int info_peso;

typedef struct _vertice{
	tipo_info info;
	info_peso peso;
	struct _vertice *prox;
}Vertice;

typedef struct _lista_adj{
	tipo_info info;
	int cor; /* Assumindo os possiveis valores: BRANCO, CINZA, PRETO; */
	int predecessor; /*Utiliza um id de que tipo? */
	int distancia;
	int tempo_descoberta;
	int tempo_finalizacao;
	Vertice *prox;
	int id_grupo;
	info_peso peso;
}Lista_adj;

typedef struct _no{
	tipo_info info;
	struct _no *prox;
}No;

typedef struct _heap{
	int id;
	int info;
}Heap;

typedef No * Lista;

/*typedef int ** Matriz_Inc; */
/*typedef int ** Matriz_Adj; */

typedef Lista_adj * Grafo;
/* +++++++++++++++++++++++++++ */

/* =========================================== Cabecalhos ========================================== */

	void insere(){
		while(1)
			break;
	}

	int estaVazia(Grafo g);
	void inic_grafo(Grafo * g, int tam);
	void limpa_grafo(Grafo g, int tam);

	void insere_s_rep(Grafo g, int id, tipo_info nova_info);

	void insere_rep_fim(Grafo g, int id, tipo_info nova_info, int modo_repeticao, int peso);

	void libera(Vertice * n);
	void desaloca(Grafo *g, int tam);
	
	int BEP_IMPAR(Grafo g, int tam);
	int BEP_IMPAR_AUX(Grafo g, int id_root, int *coloracao, int ncor);
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */


/* ========================================= Funcoes Uteis ========================================= */
	/* Verifica se um grafo esta vazio.
	 * Entrada:
	 * 		Grafo g (variavel, nao ponteiro);
	 * Saida:
	 * 		1 - Vazio;
	 * 		0 - C.C.;
	 */
	int estaVazia(Grafo g){
		return g == NULL;
	}

	/* Inicia o Grafo alocando espaco para 'tam' posicoes.
	 * Entrada:
	 *		Grafo *g (ponteiro, para poder apontar para o novo espaco alocado);
	 * 		int tam (quantidade de vertices do grafo).
	 */
	void inic_grafo(Grafo * g, int tam){
		int i;

		*g = (Lista_adj *)malloc(tam * sizeof(Lista_adj));

		for(i = 0; i < tam; i++){
			(*g)[i].info = i;
			(*g)[i].cor = BRANCO;
			(*g)[i].predecessor = RAIZ;
			(*g)[i].distancia = INF;
			(*g)[i].tempo_descoberta = TZERO;
			(*g)[i].tempo_finalizacao = TZERO;
			(*g)[i].prox = NULL;
			(*g)[i].id_grupo = SEM_GRUPO;
			(*g)[i].peso = 0;
		}
	}

	/* Insere um vertice com nova_info na lista de adjacencia do vertice identificado por id.
	 * Entrada:
	 * 		Grafo g;
	 * 		int nova_info;
	 * 		int id;
	 */
	void insere_rep_fim(Grafo g, int id, tipo_info nova_info, int modo_repeticao, int peso){
		Vertice * n;

		n = (Vertice *)malloc(sizeof(Vertice));
		n->info = nova_info;
		n->peso = peso;
		n->prox = NULL;

		Vertice * p;

		p = g[id].prox;

		if(estaVazia(g)){
			printf("Erro\n");
		}
		else if(p == NULL){
			/*printf("Vazio\n"); */
			g[id].prox = n;
		}
		else{
			if(modo_repeticao && p->info == nova_info) return;
			while(p->prox != NULL){
				/*printf(">%d< ", p->info); */
				if(modo_repeticao && p->info == nova_info) return;
				p = p->prox;
			}
			if(modo_repeticao && p->info == nova_info) return;
			p->prox = n;
			/*printf("\n"); */
		}
	}

	void insere_inicio(Grafo g, int id, tipo_info nova_info, int peso){
		Vertice * n;

		n = (Vertice *)malloc(sizeof(Vertice));
		n->info = nova_info;
		n->peso = peso;
		n->prox = NULL;

		 if(g[id].prox == NULL){
			g[id].prox = n;
		}
		else{
			n->prox = g[id].prox;
			g[id].prox = n;
		}
	}

	/* (Funcao Auxiliar) Remove recursivamente todos os elementos de uma lista ligada (do ultimo para o primeiro)
	 * Entrada:
	 * 		Vertice * n (Ponteiro que aponta para o primeiro elemento da lista ligada).
	 */
	void libera(Vertice * n){
		if(n != NULL){
			/*printf("%d, ", n->info); */
			if(n->prox != NULL)
				libera(n->prox);

			if(n->prox == NULL){
				free(n);
				n = NULL;
			}
		}
	}

	/* Desaloca o espaco usado para o vetor da lista de adjacencias que representa um grafo.
	 * Entrada:
	 *		Grafo *g (ponteiro, para poder liberar (free) o espaco alocado);
	 * 		int tam (quantidade de vertices do grafo).
	 */
	void desaloca(Grafo *g, int tam){
		int i;
		Vertice * p;
		for(i = 0; i < tam; i++){
			/*printf("%d: ", (*g)[i].info); */
			libera((*g)[i].prox);
			/*printf("\n"); */
		}
		free(*g);
		*g = NULL;
	}
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */





/* ============================================== Buscas =========================================== */
	int BEP_IMPAR(Grafo g, int tam){
		int *coloracao;
		int i;

		int j;

		coloracao = (int *) malloc(tam * sizeof(int));
		int ncor = 0;
		for(i = 0; i < tam; i++){
			coloracao[i] = -1;
		}

		for(i = 0; i < tam; i++){
			if(g[i].cor == BRANCO){
				if(BEP_IMPAR_AUX(g, i, coloracao, ncor)){
					/*imprime_grafo(g, tam, SEM_PESO); */
					/*for(j = 0; j < tam; ++j)	printf("c[%d]:%d ", j, coloracao[j]);	printf("\n"); */
					return 1;
				}
			}
		}

		/*imprime_grafo(g, tam, SEM_PESO); */
		/*for(j = 0; j < tam; ++j)	printf("c[%d]:%d ", j, coloracao[j]);	printf("\n"); */
		return 0;
	}

	int BEP_IMPAR_AUX(Grafo g, int id_root, int *coloracao, int ncor){
		/*printf("Visiting: %d\n", g[id_root].info); */
		g[id_root].cor = CINZA;
		coloracao[id_root] = ncor;

		Vertice * p;
		p = g[id_root].prox;
		int flag = 0;
		int retorno = 0;

		while(p != NULL){
			int aux = p->info;
			if(g[aux].cor == BRANCO){
				/*printf("To visit: %d\n", aux); */
				retorno = BEP_IMPAR_AUX(g, aux, coloracao, !ncor);
			}
			if(retorno){
				/*printf("Retorno 1\n"); */
				return 1;
			}
			if((g[aux].cor == PRETO || g[aux].cor == CINZA) && (coloracao[aux] == coloracao[id_root])){
				/*printf("Ciclo\n"); */
				return 1;
			}
			p = p->prox;
		}

		/*printf("Visited: %d\n", g[id_root].info); */
		g[id_root].cor = PRETO;
		return 0;
	}
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */


void Test10004(){
	int n, m, a, b, i;
	int result;
	Grafo g;

	while(1){
		scanf("%d", &n);

		if(n == 0)
			break;

		scanf("%d", &m);
		inic_grafo(&g, n);
		for(i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			/* insere_rep_fim(g, a, b, SEM_REP, 0); */
			/* insere_rep_fim(g, b, a, SEM_REP, 0); */
			insere_inicio(g, b, a, 0);
			insere_inicio(g, a, b, 0);
		}
		/*imprime_grafo(g, n, SEM_PESO); */
		result = BEP_IMPAR(g, n);
		if(result)
			printf("NOT BICOLORABLE.\n");
		else
			printf("BICOLORABLE.\n");

		desaloca(&g, n);
	}
}

int main(){
	Test10004();
	return 0;
}