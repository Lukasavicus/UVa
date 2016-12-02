/* Lukasavicus - UVa - 11661 */

#include <stdio.h>

#define MAX 2123456

char string[MAX];

int compareDistances(int n){
	int i, min = MAX, i_d = -1, i_r = -1, aux;
	char c;
	for(i = 0; i < n; i++){
		/* printf("%c %d %d %d\n", string[i], i_d, i_r, min); */
		if(string[i] == 'Z')
			return 0;

		else if(string[i] == 'D'){
			i_d = i;
			if(i_d != -1 && i_r != -1){
				aux = (i_d > i_r) ? (i_d - i_r) : (i_r - i_d);
				if(aux < min)
					min = aux;
			}
		}

		else if(string[i] == 'R'){
			i_r = i;
			if(i_d != -1 && i_r != -1){
				aux = (i_d > i_r) ? (i_d - i_r) : (i_r - i_d);
				if(aux < min)
					min = aux;
			}
		}
	}
	return min;
}

int main(){

	int size;

	while(1){
		scanf("%d", &size);
		if(size == 0)
			break;
		scanf("%s", string);
		printf("%d\n", compareDistances(size));
	}

	return 0;
}