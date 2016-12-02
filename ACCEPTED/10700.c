/* Lukasavicus - UVa - 10700 */

#include <stdio.h>

typedef long long int lli;

int main(){
	
	lli expression[12]; /* 12 numbers and 11 operations */
	lli response[12];
	char operations[11];

	int TC;
	int i, j, k, l;
	int size_expr, size_oper, size_factor;
	lli min,max, aux;

	char c;

	scanf("%d\n", &TC);

	while(TC--){
		size_expr = 0;
		size_oper = 0;
		while(1){
			scanf("%lld%1c", &aux, &c);
			expression[size_expr++] = aux;

			if(c == '\n')
				break;
			else
				operations[size_oper++] = c;
		}

		/* =============================================================================== */
		for(i = 0, size_factor = 1, j = 0, k = 0, aux = expression[j]; i < size_oper; i++){
			if(operations[i] == '+'){
				aux += expression[++j];
			}
			else{
				size_factor++;
				response[k++] = aux;
				aux = expression[++j];
			}
		}
		response[k++] = aux;
		for(i = 1, aux = response[0]; i < size_factor; i++){
			aux *= response[i];
		}

		max = aux;
		/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

		/* =============================================================================== */
		for(i = 0, size_factor = 1, j = 0, k = 0, aux = expression[j]; i < size_oper; i++){
			if(operations[i] == '*'){
				aux *= expression[++j];
			}
			else{
				size_factor++;
				response[k++] = aux;
				aux = expression[++j];
			}
		}
		response[k++] = aux;
		for(i = 1, aux = response[0]; i < size_factor; i++){
			aux += response[i];
		}

		min = aux;
		/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

		printf("The maximum and minimum are %lld and %lld.\n", max, min);

	}

	return 0;
}
/*
	1+2+3
	1+2

	1+2*3+4:
	[1][2][3][4] e
	[+][*][+]

*/