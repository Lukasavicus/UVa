/* Lukasavicus - UVa - 10550 */

#include <stdio.h>


int main(){
	int r;
	int a, b, c, d;
	int aux;

	while(1){

		scanf("%d %d %d %d", &a, &b, &c, &d);

		if(a == b && c == d && b == c && a == 0)
			break;

		r = 120; /* One full Clockwise turn (40*2) = 80 
				 * +
				 * One full Counter-Clockwise turn (40*1) = 40 
				 */

		r += (b > a) ? (40 + (a - b)) : (a - b); /* Rotate clockwise from start position to first number */
		/*(b > a) ? printf("%d\n",(40 + (a - b))) : printf("%d\n",(a - b));*/
		r += (c > b) ? (c - b) : (40 - (b - c)); /* Difference between first position and second number */	
		/*(c > b) ? printf("%d\n",(c - b)) : printf("%d\n",(40 - (b - c)));*/
		r += (d > c) ? (40 + (c - d)) : (c - d); /* Difference between second position and third number */	
		/*(d > c) ? printf("%d\n",(40 + (c - d))) : printf("%d\n",(c - d));*/
		printf("%d\n", (r * 9));
	}

	return 0;
}