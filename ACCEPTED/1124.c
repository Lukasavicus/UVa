/* Lukasavicus - UVa - 1124 */

#include <stdio.h>

int main(){

	char aux, s[1123456];
	int i, flag = 1;

	i = 0;
	while(1){
		if(scanf("%c", &aux) == EOF){
			break;
		}
		s[i++] = aux;
	}
	printf("%s", s);

	return 0;
}