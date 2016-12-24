/* Lukasavicus - UVa - 10341 */

#include <stdio.h>
#include <math.h>

#define KNOB_PARAM 1000000000 	/* 8 */
#define KNOB_RESULT 10000000 	/* 7 */

int main(){

	int p, q, r, s, t, u;
	int flag;

	int intx, intx_old, intresult;

	double x = 0.5, x_old = 0, passo = 1;
	double result;

	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
		
		flag = 0;
		x = 0.5;
		x_old = 0;
		passo = 1;

		while(1){
			result = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x,2) + u;
			x_old = x;
			intx_old = x_old * KNOB_PARAM;
			passo /= 2;
			intresult = result * KNOB_RESULT;
			if(intresult == 0){
				flag = 1;
				break;
			}
			else if(result > 0){
				x += passo;
			}
			else{
				x -= passo;
			}

			intx = x * KNOB_PARAM;

			/* printf("IR: %d\t\tR: %.6lf\tx0:%.6lf\tX-1:%.6lf\n", intresult, result, x, x_old); */

			if((intx == intx_old) || intx > KNOB_PARAM || intx_old > KNOB_PARAM)
				break;

		}
		if(flag && x >= 0)
			printf("%.4lf\n", x);
		else
			printf("No solution\n");
	}
	
	return 0;
}