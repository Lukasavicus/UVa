/* Lukasavicus - UVa - 11364 */

#include <stdio.h>

int main(){

	int TC, n, sum, aux;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d", &n);
		sum = 0;
		while(n--){
			scanf("%d", &aux);
			sum += aux;
		}
		printf("%d\n", sum);
	}


	return 0;
}