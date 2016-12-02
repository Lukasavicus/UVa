/* Lukasavicus - UVa - 100 */

#include <stdio.h>

int main(){

	long long int st, end, max, i, n, len, aux1, aux2;

	while(scanf("%lld %lld", &st, &end) != EOF){

		aux1 = st;
		aux2 = end;

		if(st > end){
			aux2 = st;
			aux1 = end;
		}

		max = 0;
		for(i = aux1; i <= aux2; i++){
			n = i;
			len = 1;
			while(n != 1){
				len++;
				/*printf("[%lld]:%lld\n", i, n);*/
				if(n % 2 != 0){
					n = 3 * n + 1;
				}
				else{
					n /= 2;
				}
			}
			/*printf("l:%lld - m:%lld\n", len, max);*/
			if(len > max){
				max = len;
			}
		}
		printf("%lld %lld %lld\n", st, end, max);
	}

	return 0;
}