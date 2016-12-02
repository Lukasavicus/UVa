#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _result{
	int r;
	float dist;
}result;

main(){

	int time, cdx, cdy, i = 0;
	double dist;
	result *res;

	scanf("%d", &time);
	res = (result *) malloc (time * sizeof(result));	

	for(i = 0; i < time; i++){
		scanf("%d", &cdx);
		scanf("%d", &cdy);
		scanf("%d", &res[i].r);

		dist = pow(cdx,2) + pow(cdy,2);
		dist = pow(dist, 0.5);
		res[i].dist = dist;
	}

	for(i = 0; i < time; i++){
		printf("%0.2f %0.2f\n", (res[i].r - res[i].dist), ((2 * res[i].r) - (res[i].r - res[i].dist)));
	}

}
	/*
		Problem 12704 - Consiste em determinar as distâncias mínima e máxima de 
	um ponto p(x,y) em relação a circunferência de um círculo de raio r; 
	Obs: O ponto pertence a reta que descreve o diâmetro da circunferência;
		
		Método de resolução: Pitágoras;

	*/

	//Vetor respostas						-	res[]
	//numero de vezes						-	time
	//coordenada x							-	cdx
	//coordenada y							-	cdy
	//iterador								-	i
	//m - menor distancia => m = r - dist
	//d - diametro => d= 2 * r
	//M - maior distancai => M = d - m

//	Lucas Lukasavicus Silva - 25/06/2014
