/* Lukasavicus - UVa - 11764 */

#include <stdio.h>

int main(){
	
	int TC, n, aux1, aux2, hj,lj, i;

	scanf("%d", &TC);
	i = 1;
	while(TC--){
		hj = 0; lj = 0;
		scanf("%d", &n);
		scanf("%d", &aux1);
		n--;
		while(n--){
			scanf("%d", &aux2);
			(aux2 > aux1) ? hj++ : 1;
			(aux1 > aux2) ? lj++ : 1;
			aux1 = aux2;
		}
		printf("Case %d: %d %d\n", i++, hj, lj);
	}

	return 0;
}