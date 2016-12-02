/* Lukasavicus - UVa 160 */

/* How Many Numbers are between 1 and 100 = 25; */

#include <stdio.h>

#define MAX 26

typedef struct _primes{
	int index_prime;
	int ocurrency;
}Primes;

Primes p[MAX];

void init(){
	int i;
	for(i = 0 ; i < MAX; i++){
		p[i].ocurrency = 0;
	}
}

int main(){
	
	p[0].index_prime = 		2;
	p[1].index_prime = 		3;
	p[2].index_prime = 		5;
	p[3].index_prime = 		7;
	p[4].index_prime = 		9;
	p[5].index_prime = 		11;
	p[6].index_prime = 		13;
	p[7].index_prime = 		17;
	p[8].index_prime = 		19;
	p[9].index_prime = 		23;
	p[10].index_prime = 	29;
	p[11].index_prime = 	31;
	p[12].index_prime = 	37;
	p[13].index_prime = 	41;
	p[14].index_prime = 	43;
	p[15].index_prime = 	47;
	p[16].index_prime = 	53;
	p[17].index_prime = 	59;
	p[18].index_prime = 	61;
	p[19].index_prime = 	67;
	p[20].index_prime = 	71;
	p[21].index_prime = 	73;
	p[22].index_prime = 	79;
	p[23].index_prime = 	83;
	p[24].index_prime = 	89;
	p[25].index_prime = 	97;

	int i, j, aux;
	int d;

	while(1){

		scanf("%d", &d);
		if(!d)
			break;

		for(i = d; i > 1; i--){
			aux = i;
			for(j = 0; j < MAX; j++){
				while(!(aux % p[j].index_prime)){
					p[j].ocurrency++;
					aux /= p[j].index_prime;
				}
			}
		}

		if(d == 100)
			printf("%d! =", d);
		else
			printf("% 3d! =", d);
		for(i =  0, j = 0; i < MAX; i++){
			if(p[i].ocurrency){
				j++;
			}
			if(j == 16){
				printf("\n      ");
				j = 0;
			}
			if(p[i].ocurrency){
				printf("% 3d", p[i].ocurrency);
			}
		}
		printf("\n");

		init();

	}

	return 0;
}