// UVA - Lukasavicus - 12049

// Parece que tá certo, mas é necessário conferir com iteradores para verificar os
// elementos de cada um dos conjuntos intermediarios que fazem parte da resposta
// final: uniao, interseccao, diferenca

#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef multiset<int> mconjunto;

int main(){
	int c, n, m, aux;
	int i, j;
	mconjunto a, b, uniao, interseccao, diff;


	cin >> c;

	for(i = 0; i < c; i++){

		a.clear(); b.clear(); uniao.clear();interseccao.clear();

		cin >> n;
		cin >> m;

		for(j = 0; j < n; j++){
			cin >> aux;
			a.insert(aux);
		}

		for(j = 0; j < m; j++){
			cin >> aux;
			b.insert(aux);
		}	

		set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(uniao, uniao.begin()));

		set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(interseccao, interseccao.begin()));

		//set_difference(uniao.begin(), uniao.end(), interseccao.begin(), interseccao.end(), inserter(diff, diff.begin()));
		//cout << diff.size() << "\n";

		cout << (uniao.size() - interseccao.size()) << "\n";		

	}




}