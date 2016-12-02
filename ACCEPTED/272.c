/* Lukasavicus - Uva - 272 */

#include <stdio.h>
#include <string.h>

#define MAX 1123456

int main(){

	char s[MAX], s_out[MAX];
	char caux;
	int i = 0, flag, t_str;


	while(scanf("%c", &caux) != EOF)
		s[i++] = caux;

	const int size = strlen(s);

	for(i = 0, flag = 0, t_str = 0; i < size; ++i){
		if(s[i] == '\"'){
			if(flag){
				s_out[t_str++] = '\'';
				s_out[t_str++] = '\'';
				flag = 0;
			}
			else{
				s_out[t_str++] = '`';
				s_out[t_str++] = '`';
				flag = 1;
			}
		}
		else{
			s_out[t_str++] = s[i];
		}
	}
	s_out[t_str] = '\0';

	printf("%s", s_out);

	return 0;
}