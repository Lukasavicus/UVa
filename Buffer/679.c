/* Lukasavicus - UVa - 679 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

#define FALSE 0
#define TRUE 1

/* 
 * This solution use as base a internet solution:
 * http://andrew-algorithm.blogspot.com.br/2014/10/uva-problem-679.html
 */

int drop_ball(int d, int h){

	int number, iter, init_pot, half, aux;
	int isBiggerThanAHalf = FALSE;
	int i, j;

	aux = iter = init_pot = (int)(pow(2, h-1));

	number = (init_pot * 2)-1;

	int * tree = (int *) malloc(number * sizeof(int));

	half = init_pot / 2;
	
	/* printf("::%d %d %d\n", d, half, number); */

	if(d > half){
		isBiggerThanAHalf = TRUE;
		d -= half;
	}

	/* printf("::%d %d %d\n", d, half, number); */

	for(i = 0; i < number; i++){
		tree[i] = FALSE;
	}

	for(i = 0; i < d; i++){
		for(j = 0, iter = 1; j < h - 1; j++){
			if(tree[iter - 1] == FALSE){
				tree[iter - 1] = TRUE;
				iter *= 2;
			}
			else{
				tree[iter - 1] = FALSE;
				iter *= 2;
				iter++;	
			}
		}
	}

	/* printf("> %d\n", iter); */

	if(isBiggerThanAHalf)
		iter++;

	free(tree);

	return iter;
}

int main(){

	int n, h, d, i, r, pot;

	while(1){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d %d", &h, &d);

			pot = (int)(pow(2, h-1));

			if((d % pot) != 0)
				d = (d % pot);

			r = drop_ball(d, h);

			printf("%d\n", r);
		}
		if(n == -1)
			break;
	}

	return 0;
}