#include <stdio.h>
#include <stdlib.h>

#define K 6

typedef int data_type;
typedef int bool;

typedef struct _combination{
	data_type data;
	bool flag;
}Combination;

int compare(const void *a, const void *b){
	Combination * pa, * pb;
	pa = (Combination * )a;
	pb = (Combination * )b;
	return pa->data - pb->data;
}

void print_debug(Combination c[], int n, int mode){
	int i;
	if(mode == 0){
		for(i = 0; i < n; i++){
			printf("i:%d d:%d f:%d\n", i, c[i].data, c[i].flag);
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
		c[i].flag = 0;
	}
}

void print_combination(Combination c[], int n){
	int i;
	int printabled_characters;
	for(i = 0, printabled_characters = 0; i < n; i++){
		if(c[i].flag){
			printf("%d ", c[i].data);
			printabled_characters++;
		}
		if(printabled_characters == K-1)
			break;
	}
	for(i = i + 1; i < n; i++){
		if(c[i].flag){
			printf("%d\n", c[i].data);
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

void recursive_search(Combination c[], int n, int level, int start_index){
	/*printf("rs:([");*/
	/*print_debug(c, n, 1);*/
	/*printf("], %d, %d) ", level, start_index);*/
	if(level == K){
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
		for(i = start_index, j = 0; j <= n-K && i <= n; i++, j++){
			/*printf("I:%d\n", i);*/
			c[i].flag = 1;
			recursive_search(c, n, level+1, i+1);
			c[i].flag = 0;
		}
	}
}

int main(){
	int n;
	Combination *c;
	int i;
	int flag = 0;

	do{
		scanf("%d", &n);
		if(n == 0)
			break;
		if(flag == 0){
			flag = 1;
		}
		else{
			printf("\n");
		}

		c = (Combination *) malloc (n * sizeof(Combination));

		for(i = 0; i < n; i++){
			scanf("%d", &c[i].data);
		}
		clear_combination(c, n);
		qsort(c, n, sizeof(Combination), compare);
		recursive_search(c, n, 0, 0);
		free(c);
	}while(1);
	return 0;
}