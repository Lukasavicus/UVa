/* Lukasavicus - UVa - 10910 */

#include <stdio.h>

int main(){

	int TC, n, t, p, m, r;

	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d %d", &n, &t, &p);
		m = t - (p * n);
		r = 0;
		/*
		 * Some fancy DP Algorithm to generate all the
		 * possibilities to Sum of n natural numbers
		 * that equals to m.
		*/
		 printf("%d\n", r);
	}

	return 0;
}