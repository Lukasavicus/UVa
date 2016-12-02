#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 15

typedef char * data_type;
typedef int bool;

typedef struct _combination{
	data_type data;
	bool flag;
}Combination;

int compare(const void *a, const void *b){
	Combination * pa, * pb;
	pa = (Combination * )a;
	pb = (Combination * )b;
	if(strlen(pa->data) < strlen(pb->data))
		return 1;
	else if(strlen(pa->data) > strlen(pb->data))
		return -1;
	else
		return strcmp(pa->data, pb->data);
}

void print_debug(Combination c[], int n, int mode){
	int i;
	if(mode == 0){
		for(i = 0; i < n; i++){
			printf("i:%d d:%s f:%d\n", i, c[i].data, c[i].flag);
		}
	}
	else if(mode == 1){
		for(i = 0; i < n; i++){
			printf("%d ", c[i].flag);
		}
	}
}

void clear_combination(Combination c[], int n){
	int i;
	for(i = 0; i < n; i++){
		c[i].data = (char *) malloc(MAX * sizeof(char));
		c[i].flag = 0;
	}
}

void print_combination(Combination c[], int n){
	int i;
	int printabled_characters;
	for(i = 0, printabled_characters = 0; i < n; i++){
		if(c[i].flag){
			printf("%s ", c[i].data);
			printabled_characters++;
		}
		if(printabled_characters == K-1)
			break;
	}
	for(i = i + 1; i < n; i++){
		if(c[i].flag){
			printf("%s\n", c[i].data);
			break;
		}
	}
}

int evaluate_combination(Combination c[], int n){
	int i = 0;
	int count;
	for(i = 0, count = 0; i < n; i++)
		if(c[i].flag)
			count++;

	return count == K;

}

void recursive_search(Combination c[], int n, int number_of_levels){
	recursive_search_aux(c, n, 0, 0, number_of_levels);
}

void recursive_search_aux(Combination c[], int n, int level, int start_index, int number_of_levels){
	/*printf("rs:([");*/
	/*print_debug(c, n, 1);*/
	/*printf("], %d, %d) ", level, start_index);*/
	if(level == number_of_levels){
		/*printf("\n");*/
		if(evaluate_combination(c, n)){
			print_combination(c, n);
		}
		/*print_debug(c, n, 1);*/
	}
	else{
		int i;
		int j;
		/*n-K*/
		for(i = start_index, j = 0; j <= n-number_of_levels && i <= n; i++, j++){
			/*printf("I:%d\n", i);*/
			c[i].flag = 1;
			recursive_search_aux(c, n, level+1, i+1, number_of_levels);
			c[i].flag = 0;
		}
	}
}

int main(){
	int n,
		p,
		s;
	Combination *c;
	Combination *prohibited;
	int i;
	int flag = 0;

	do{
		scanf("%d %d %d", &n, &p, &s);
		if(n == 0)
			break;
		if(flag == 0){
			flag = 1;
		}
		else{
			printf("\n");
		}

		c = (Combination *) malloc (n * sizeof(Combination));
		prohibited = (Combination *) malloc ((p*2) * sizeof(Combination));
		clear_combination(c, n);
		clear_combination(prohibited, p*2);

		for(i = 0; i < n; i++){
			scanf("%s", c[i].data);
		}
		
		for(i = 0; i < p*2; i++){
			scanf("%s", prohibited[i].data);
		}

		qsort(c, n, sizeof(Combination), compare);
		
		for(i = 0; i < n; i++){
			printf("%s\n", c[i].data);
		}

		recursive_search(c, n, s);

		free(c);
	}while(1);
	return 0;
}