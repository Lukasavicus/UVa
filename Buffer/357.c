#include<stdio.h>
#include<stdlib.h>

#define MAX 30000

typedef struct _resultado{

	long long int ent, ways;

}resultado;

main(){
	long long int aux;
	int mult_div [MAX];
	int i, j;
	resultado res[MAX];

	j = 0;

	do{

	scanf("%lld", &res[j].ent);

	aux = res[j].ent;	

	res[j].ways = 0;

	mult_div[0] = aux;

	i = 0;
	while(mult_div[i] > 5){
		res[j].ways++;
		mult_div[res[j].ways] = mult_div[res[j].ways - 1] - 5;
		i++;
	}


	i = 0;
	while(mult_div[i] > 10){
		res[j].ways++;
		i++;
	}


	i = 0;
	while(mult_div[i] > 25){
		res[j].ways++;
		i++;
	}


	i = 0;
	while(mult_div[i] > 50){
		res[j].ways++;
		i++;
	}


	j++;

	}while(!(res[j - 1].ent == 0));


	for(i = 0; i < j - 1; i++){
		printf("There are %lld ways to produce %lld cents change.\n", res[i].ways + 1, res[i].ent);
	}

}

//lld - ent
//mult_div - multiplas divisões que vão ocorrer em cima do valor de entrada
