/* Lukasavicus - UVa - 12247 */

#include <stdio.h>

int main(){

	int a, b, c, x, y, aux, r;

	while(1){
		scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

		if(a == 0 && b == 0 && c == 0 && x == 0 && y == 0)
			break;

		if(a > b){ aux = a; a = b; b = aux; }
		if(b > c){ aux = b; b = c; c = aux; }
		if(a > b){ aux = a; a = b; b = aux; }

		if(x > y){ aux = x; x = y; y = aux; }

		/* printf(">%d %d %d %d %d<\n", a, b, c, x, y); */

		if(c > y && b > x){
			printf("-1\n");
		}
		else{
			if(x > c){
				r = 1;
			}
			else{
				if(x > b)
					r = b + 1;
				else{
					if(x < a)
						r = c + 1;
					else
						r = b + 1;

					if(r < c)
						r = c + 1; 
				}
			}

			while((r == a) || (r == b) || (r == c) || (r == x) || (r == y))
				r++;
			if(r > 52)
				printf("-1\n");
			else
				printf("%d\n", r);
		}
	}

	return 0;
}