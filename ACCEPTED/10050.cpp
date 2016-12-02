// UVA - Lukasavicus - 10050

#include <stdio.h>
#include <iostream>
#include <set>

#define MAX 101

using namespace std;

typedef set<int> conjunto;

void inic_vetor(int *v){
	int i;
	for(i = 0; i < MAX; i++)
		v[i] = 0;
}

int calc(int *v, int tam, int dias){
	int i, j, aux;

	conjunto c;

	for(i = 0; i < tam; i++){
		aux = v[i];
		//printf("a:%d\n", aux);
		for (j = aux; j <= dias; j += aux){
			//printf("j:%d\n", j);
			if( !( ( (j % 7) == 6) || ( (j % 7) == 0) ) ){
				//printf("a:%d\tj:%d\n", aux, j);
				c.insert(j);
			}
		}
	}
	return c.size();
}

int main(){
	int v[101];
	int c, //cases
		n, //days
		p; //political parties

	int i, j;

	cin >> c;
	for(i = 0; i < c; i++){
		inic_vetor(v);
		cin >> n;
		cin >> p;
		for(j = 0; j < p; j++){
			cin >> v[j];
		}
		cout << calc(v, p, n) << "\n";
	}

}