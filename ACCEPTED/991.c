/* Lukasavicus - UVa - 991 */

/* Based on the Theory Numbers > Catalan Numbers */

#include <stdio.h>

typedef long long int lli;

lli fat(int n){
	if(n == 1)
		return 1;
	return n * fat(n - 1);
}

lli limited_fat(int n, int k){
	if(n == k)
		return 1;
	return n * limited_fat(n - 1, k);
}

lli fast_binomial(int n, int k){
	lli numerator, denominator;
	
	numerator = limited_fat(n, k);
	denominator = fat(k);
	/* printf(">%lld & %lld\n", numerator, denominator); */
	return ( numerator / denominator);
}

lli catalan_number(int n){
	lli result = fast_binomial(2*n, n);
	/* printf(">%lld\n", result); */
	return ( result / ( n + 1  ) );
}

int main(){
	int d, i = 0;
	while(scanf("%d", &d) != EOF){
		if(i == 1)
			printf("\n");
		printf("%lld\n\n", catalan_number(d));
		i = 1;
	}

	return 0;
}