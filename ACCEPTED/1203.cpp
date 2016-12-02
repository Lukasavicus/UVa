// UVA - Lukasavicus - 01203

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef pair< int, int > par;
typedef map<int, int> mapa;
typedef mapa::const_iterator iterador; 

int main(){
	mapa m;
	string command;
	int id, time;
	int k;
	int i, j;
	bool flag = false;

	while(!flag){
		cin >> command;

		if(command == "#"){
			//cout << "Ended\n";
			cin >> k;
			flag = true;
		}
		if (command == "Register"){
			//cout << "Register comming\n";
			cin >> id;
			cin >> time;
			m.insert(par(id, time));
		}
	}

	iterador it;
	int key;
	int value;

	for(i = 1, j = 0; i < 3000 && j < k; i++){
		for(it = m.begin(); it != m.end() && j < k; it++){
			key = it->first;
			value = it->second;
			//cout << value << "\n";
			if((i % value) == 0){
				//cout << i << "\t";
				cout << key << "\n";
				j++;
			}
		}
	}


}