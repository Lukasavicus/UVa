/* Lukasavicus - UVa - 12478 */

#include <stdio.h>
#include <string.h>

#define N 9
#define P 8

void strrev(char *s){
	int size = strlen(s)-1, i;
	char c;

	for(i = 0; i <= (size/2); i++){
		c = s[size-i];
		s[size-i] = s[i];
		s[i] = c;
	}
}

int main(){

	const char grid[] = {
							'O', 'B', 'I', 'D', 'A', 'I', 'B', 'K', 'R',
							'R', 'K', 'A', 'U', 'L', 'H', 'I', 'S', 'P',
							'S', 'A', 'D', 'I', 'Y', 'A', 'N', 'N', 'O',
							'H', 'E', 'I', 'S', 'A', 'W', 'H', 'I', 'A',
							'I', 'R', 'A', 'K', 'I', 'B', 'U', 'L', 'S',
							'M', 'F', 'B', 'I', 'N', 'T', 'R', 'N', 'O',
							'U', 'T', 'O', 'Y', 'Z', 'I', 'F', 'A', 'H',
							'L', 'E', 'B', 'S', 'Y', 'N', 'U', 'N', 'E',
							'E', 'M', 'O', 'T', 'I', 'O', 'N', 'A', 'L',
						};

	int v[]={0, 0, 0, 0, 0, 0, 0, 0};

	char names[P][P];
	char name_aux[P];
	char name_aux2[P];

	strcpy(names[0], "RAKIBUL");
	strcpy(names[1], "ANINDYA");
	strcpy(names[2], "MOSHIUR");
	strcpy(names[3], "SHIPLU");
	strcpy(names[4], "KABIR");
	strcpy(names[5], "SUNNY");
	strcpy(names[6], "OBAIDA");
	strcpy(names[7], "WASI");

	int i, j, k, aux1, aux2;

	for(i = 0; i < P; i++){

		aux1 = strlen(names[i]);
		strcpy(name_aux, names[i]);
		strrev(name_aux);
		printf("%s %s %d\n", names[i], name_aux, aux1);

		for(j = 0; j < N; j++){
			for(k = 0; k <= N - aux1; k++){
				strncpy(name_aux2, &grid[j*N+k], aux1);
				name_aux2[strlen(name_aux2)] = '\0';
				printf("%d\n", strlen(name_aux2));
				//printf("%c\n", grid[j*N+k]);
				printf("[%d][%d] %s\n", j, k, name_aux2);
				if((strncmp(names[i], &grid[j*N+k], aux1) == 0) || (strncmp(name_aux, &grid[j*N+k], aux1) == 0)){
					printf("%s %s %s\n", names[i], name_aux, name_aux2);
					v[i]++;
				}
			}
		}
	}

	printf("%d %d %d %d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);

	for(i = 0; i < P; i++){

		aux1 = strlen(names[i]);
		strcpy(name_aux, names[i]);
		strrev(name_aux);
		printf("%s %s %d\n", names[i], name_aux, aux1);

		for(j = 0; j < N; j++){
			for(k = 0; k <= N - aux1; k++){
				strncpy(name_aux2, &grid[k*N+j], aux1);
				name_aux2[strlen(name_aux2)] = '\0';
				printf("%d\n", strlen(name_aux2));
				//printf("%c\n", grid[j*N+k]);
				printf("[%d][%d] %s\n", j, k, name_aux2);
				if((strncmp(names[i], &grid[k*N+j], aux1) == 0) || (strncmp(name_aux, &grid[k*N+j], aux1) == 0)){
					printf("%s %s %s\n", names[i], name_aux, name_aux2);
					v[i]++;
				}
			}
		}
	}

	printf("%d %d %d %d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);

	return 0;
}