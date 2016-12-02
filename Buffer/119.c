/* Lukasavicus - UVa - 119 */

#include <stdio.h>
#include <string.h>

#define MAXP 10
#define MAXC 21

typedef struct _pessoa{
	char name[MAXC];
	int balance;
}Pessoa;

Pessoa p[MAXP];
int TC;

int hashPeople(const char *s){
	int i;
	for(i = 0; i < TC; i++){
		if(strcmp(s, p[i].name) == 0)
			return i;
	}
	return -1;
}

void initPeople(){
	int i = 0;
	for(i = 0; i < MAXP; i++){
		p[i].balance = 0;
	}
}

int main(){

	int i, aux_index1, aux_index2, given, ngiven, j;
	char aux_name[MAXC];

	while(scanf("%d", &TC) != EOF){
		initPeople();
		for(i = 0; i < TC; i++){
			scanf("%s", p[i].name);
		}
		for(i = 0; i < TC; i++){
			scanf("%s", aux_name);
			aux_index1 = hashPeople(aux_name);
			/*printf("D1:%d\n", aux_index1);*/
			scanf("%d", &given);
			p[aux_index1].balance -= given;
			scanf("%d", &ngiven);
			for(j = 0; j < ngiven; j++){
				scanf("%s", aux_name);
				aux_index2 = hashPeople(aux_name);
				/*printf("D2:%d\n", aux_index2);*/
				p[aux_index2].balance += (given/ngiven);
			}
		}
		for(i = 0; i < TC; i++){
			printf("%s %d\n", p[i].name, p[i].balance);
		}
		printf("\n");
	}

	return 0;
}