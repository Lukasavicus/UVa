/* Lukasavicus - UVa - 11547 */

#include <stdio.h>

int main(){

	int TC, n, r;

	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &n);
		r = ( ( ( ( ( n * 63 ) + 7492 ) * 5 ) - 498 ) / 10 ) % 10;
		if(r < 0)
			r *= -1;
		printf("%d\n", r);
	}

	return 0;
}