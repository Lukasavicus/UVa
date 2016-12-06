/* Lukasvicus - UVa - 10475 */

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

#define MAX 16

typedef pair<string, string> SS;

// comparison, not case sensitive.
bool compare_nocase (const string& first, const string& second){
	int i = 0;

	if(first.length() != second.length())
		return( first.length() > second.length() );

	while ( (i<first.length()) && (i<second.length()) ){
	if (tolower(first[i])<tolower(second[i]))
		return true;
	else if(tolower(first[i])>tolower(second[i]))
		return false;

	i++;
	}
}

int TC, t, p, s;
	
string aux1, aux2;
list<string> topics;
list<SS> blacklist;
list< list<string> > covered;
list<string>::iterator it, it2;
list<SS>::iterator itaux;

bool top[MAX];

void start_top(){
	int i;
	for(i = 0; i < MAX; i++)
		top[i] = false;
}

void print_set(){
	int i, j, k, size;
	bool forbiden;
	string str_aux;
	for(it = topics.begin(), i = 0, forbiden = false; it != topics.end(); i++, ++it){
		for(it2 = it, j = i; it2 != topics.end(); j++, ++it2){

			if(it != it2 && top[i] && top[j]){
				/* cout << "[i] " << i << ": " << *it <<  " [j] " << j << ":>>" << *it2 << "<<\n"; */
				itaux = find(blacklist.begin(), blacklist.end(), SS(*it, *it2));
				if(itaux != blacklist.end())
					forbiden = true;
				itaux = find(blacklist.begin(), blacklist.end(), SS(*it2, *it));
				if(itaux != blacklist.end())
					forbiden = true;
			}

		}
	}
	
	if(!forbiden){
		for(it = topics.begin(), i = 0, j = 0; it != topics.end(); i++, ++it){
			if(top[i]){
				if(j)
					cout << " ";
				str_aux = (*it);
				size = str_aux.length();
				for(k = 0; k < size; k++)
					str_aux[k] = toupper(str_aux[k]);
				cout << str_aux;
				j++;
			}
		}
		cout << "\n";
	}
}

void mix(int level, int start){
	int i, j;

	if(level == s){
		print_set();
		return;
	}

	for(i = start; i < t; i++){
		top[i] = true;

		if(level != s)
			mix(level+1, i+1);

		top[i] = false;
	}
}

int main(){
	int i, j = 0;

	int k, size;

	cin >> TC;

	while(TC--){
		cin >> t >> p >> s;
		for(i = 0; i < t; i++){
			cin >> aux1;

			size = aux1.length();
			for(k = 0; k < size; k++)
				aux1[k] = toupper(aux1[k]);

			topics.push_back(aux1);
		}

		topics.sort(compare_nocase);

		for(i = 0; i < p; i++){
			cin >> aux1 >> aux2;

			size = aux1.length();
			for(k = 0; k < size; k++)
				aux1[k] = toupper(aux1[k]);

			size = aux2.length();
			for(k = 0; k < size; k++)
				aux2[k] = toupper(aux2[k]);

			blacklist.push_back(SS(aux1, aux2));
		}

		start_top();

		/* Current level, Quantity of forbiden words founded, Start position of analysis */
		cout << "Set " << ++j << ":\n";
		mix(0, 0);

		cout << "\n";

		topics.clear();
		blacklist.clear();
	}

	return 0;
}