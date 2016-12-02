/**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/* It need to be Not So Big cause if was really big if you add one unit you finish the cycle and the turn negative */
#define BIG 214748
#define BIGGER 214748364
#define BIGGEST 2147483647

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

/* =========================================== Cabecalhos ==========================================

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
	Grafo transpor_grafo(Grafo g,int tam);
	Grafo CFC(Grafo g, int tam, int id_root, int * id_grupo);
	int numero_de_componentes(Grafo g, int tam);

	int Kosaraju_Sharir(Grafo g, int tam);

	void BEL(Grafo g, int tam, int id_root, int modo);
	void BEP_AUX(Grafo g, int id_root, int modo, int * tempo, int id_grupo);
	void BEP(Grafo g, int tam, int id_root, int modo, int * tempo);
	void ALL_BEP(Grafo g, int tam, int id_root, int modo, int * tempo);

	int BEP_IMPAR(Grafo g, int tam);
	int BEP_IMPAR_AUX(Grafo g, int id_root, int *coloracao, int ncor);

	int Tarjan(Grafo g, int tam);
	void BEP_CC(Grafo g, int tam, int v, int pre[], int low[], int stack[], int sc[], int *conta, int *k, int *N);

	void imprime_grafo(Grafo g, int tam, int modo_peso);
	void imprime_vertice(Grafo g, int id_root);
	void imprime_lista_adjacencias(Grafo g, int tam);
	void imprime_lista_adjacencias_vertice(Grafo g, int id_root);
	void imprime_caminho_raiz_vertice(Grafo g, int id_root);
	void imprime_em_largura(Grafo g, int tam, int id_root);
	void imprime_em_profundidade(Grafo g, int tam, int id_root); */
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

	/* Limpa todas as variaveis usadas nas buscas.
	 * Entrada:
	 * 		Grafo g (variavel);
	 * 		int tam (quantidade de vertices do grafo).
	 */
	void limpa_grafo(Grafo g, int tam){
		int i;
		if(!estaVazia(g))
			for(i = 0; i < tam; i++){
				g[i].cor = BRANCO;
				g[i].predecessor = RAIZ;
				g[i].distancia = INF;
				g[i].tempo_descoberta = TZERO;
				g[i].tempo_finalizacao = TZERO;
				g[i].id_grupo = SEM_GRUPO;
				g[i].peso = 0;
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



/* =================================== ARVORE DE CAMINHOS MINIMOS ================================== */

	/* Negative Cycle */
	int Floyd_Warshall(Grafo g, int tam){
		int ** minDist;
		int i, j, k;
		int l, m;

		minDist = (int **) malloc(tam * sizeof(int));

		for(i = 0; i < tam; i++){
			minDist[i] = (int *)malloc(tam * sizeof(int));
		}

		for(i = 0; i < tam; i++){
			for(j = 0; j < tam; j++){
				if(i != j)
					minDist[i][j] = BIGGER;
				else
					minDist[i][j] = 0;
			}
		}


		Vertice * p;
		if(!estaVazia(g)){
			for(i = 0; i < tam; i++){
				p = g[i].prox;
				while(p != NULL){
					minDist[i][p->info] = p->peso;
					p = p->prox;
				}
			}
		}


		for(k = 0; k < tam; k++){
			for(i = 0; i < tam; i++){
				for(j = 0; j < tam; j++){
					if(minDist[i][j] > minDist[i][k] + minDist[k][j]){
						minDist[i][j] = minDist[i][k] + minDist[k][j];
					}
					/*
						for(l = 0; l < tam; l++){
							for(m = 0; m < tam; m++){
								printf("%d ", minDist[l][m]);
							}
							printf("\n");
						}
						printf("\n>\n");
					*/
				}
			}
		}

		for(i = 0; i < tam; i++){
			if(minDist[i][i] < 0)
				return 1;
		}
		return 0;
	}

	/* Negative-Cycles (if have: 1, ow: 0); */
	int Bellman_Ford_Moore(Grafo g, int tam, int id_root){
		int i, j;
		int l,m;

		for(i = 0; i < tam; i++){
			g[i].predecessor = RAIZ;
			g[i].distancia = BIG;
		}
		g[id_root].distancia = 0;

		Vertice * p;
		if(!estaVazia(g)){
			for(i = 0; i < tam-1; i++){
				for(j = 0; j < tam; j++){
					p = g[j].prox;
					while(p != NULL){
						if((g[p->info].distancia + p->peso) < g[j].distancia){
							g[j].distancia = g[p->info].distancia + p->peso;
							g[j].predecessor = p->info;
						}
						p = p->prox;
					}
				}
				/*
				printf("Dist:\n");
				for(l = 0; l < tam; l++){
					printf("%d ", g[l].distancia);
				}
				printf("\nPred:\n");
				for(l = 0; l < tam; l++){
					printf("%d ", g[l].predecessor);	
				}
				printf("\n\n");
				*/
			}
		}

		if(!estaVazia(g)){
			for(i = 0; i < tam; i++){
				p = g[i].prox;
				while(p != NULL){
					if((g[p->info].distancia + p->peso) < g[i].distancia){
						return 1;
					}
					p = p->prox;
				}
			}
		}

		return 0;
	}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */




int main(){
	int n, m, a, b, c, TC = 0, i;
	int result;
	Grafo g;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d %d", &n, &m);
		inic_grafo(&g, n);
		for(i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &c);
			insere_inicio(g, a, b, c);
		}
		/*result = Floyd_Warshall(g, n); */
		result = Bellman_Ford_Moore(g, n, 0);
		if(result)
			printf("possible\n");
		else
			printf("not possible\n");
	}
	return 0;
}