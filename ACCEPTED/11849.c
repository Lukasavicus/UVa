/* Lukasavicus - UVa - 11849 */

#include <stdio.h>

#define MAX 1123456

int v[MAX];
int S = -1;

int bs(int n){
	int st = 0;
	int end = S-1;
	int mid = (end + st) / 2;

	while(end >= st){
		if(v[mid] == n){
			return 1;
		}
		else if(n > v[mid]){
			st = (mid + 1);
		}
		else{
			end = (mid - 1);
		}
		mid = (end + st) / 2;
	}
	return 0;
}

int main(){
	int n, a, b, m, i, aux;

	while(1){
		m = 0;
		scanf("%d %d", &a, &b);

		if(a == 0 && b == 0)
			break;

		for(i = 0; i < a; i++)
			scanf("%d", &v[i]);

		/* printf("Reach1\n"); */

		S = a;

		for(i = 0; i < b; i++){
			scanf("%d", &aux);
			m += bs(aux);
		}

		/* printf("Reach2\n"); */

		printf("%d\n", m);
	}
	return 0;
}