/* Lukasavicus - UVa - 679 */

#include <stdio.h>
#include <math.h>

#define MAX 20
/*
int drop_ball(int d, int h, int st){
	int e = d / pow(2, st-1);
	if(h == st)
		return 1;
	if(e % 2 == 0)
		return (2 * drop_ball(d/2, h, st + 1));
	else
		return (2 * drop_ball(d/2, h, st + 1)) + 1;
}
*/

int drop_ball(int d, int h){
	if(h == 2){
		if(d % 2 != 0)
			return 2;
		else
			return 3;
	}
	else{
		int e = pow(2, h-2);
		//if(d % 2 == 0)
		if(d < e)
			return (2 * drop_ball(d, h-1));
		else
			return (2 * drop_ball(d, h-1)) + 1;
	}

}

int main(){

	int n, h, d, i, r;

	while(1){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d %d", &h, &d);
			//r = drop_ball(d, h, 1);
			r = drop_ball(d % (int)(pow(2, h-1)), h);
			printf("%d\n", r);
		}
		if(n == -1)
			break;
	}



	return 0;
}