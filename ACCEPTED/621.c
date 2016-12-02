/* Lukasavicus - UVa - 621 */

#include <stdio.h>
#include <string.h>

int main(){

	int TC, i, size;
	char s[112345];

	scanf("%d", &TC);
	while(TC--){
		scanf("%s", s);
		size = strlen(s);
		/* printf("%d\n", size); */
		if((size == 1 && (s[0] == '1' || s[0] == '4')) || (size == 2 && s[0] == '7' && s[1] == '8'))
			printf("+\n");
		else if(s[size-2] == '3' && s[size-1] == '5')
			printf("-\n");
		else if(s[0] == '9' && s[size-1] == '4')
			printf("*\n");
		else if(s[0] == '1' && s[1] == '9' && s[2] == '0')
			printf("?\n");
	}
	return 0;
}