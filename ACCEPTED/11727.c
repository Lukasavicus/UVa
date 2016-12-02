/* Lukasavicus - UVa - 11727 */

#include <stdio.h>

int main(){

	int TC, a, b, c, aux, i;

	scanf("%d", &TC);

	i = 1;
	while(TC--){
		scanf("%d %d %d", &a, &b, &c);

		if(b > a){ aux = a; a = b; b = aux; }
		if(c > b){ aux = b; b = c; c = aux; }
		if(b > a){ aux = a; a = b; b = aux; }
		printf("Case %d: %d\n", i++, b);
	}

	return 0;
}