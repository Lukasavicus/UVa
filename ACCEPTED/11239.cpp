/* Lukasvicus - UVa - 11239 */

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

#define MAXP 100
#define MAXS 10000

typedef pair<string, string> SS;
typedef pair<string, int> SI;
typedef pair<int, string> IS;

typedef map<string, string> MSS;
typedef map<string, int> MSI;
typedef multimap<int, string> MIS;

int main(){
	
	string  aux, prjname;
	MSS pivot;
	MSS::iterator it;

	MSI partials;
	MSI::reverse_iterator its;

	MIS results;
	MIS::reverse_iterator iti;
	
	list<string> blacklist;
	list<string>::iterator itb;

	pair<MSS::iterator, bool> ret;
	int i;

	do{
		aux = "";

		do{
			getline(cin, aux);

			if(!aux.compare("1") || !aux.compare("0")){
				break;
			}
			/* User Name */
			if(islower(aux[0])){
				ret = pivot.insert(SS(aux,prjname));
				/*
				 *	Tentou inserir, não conseguiu e o nome de usuário
				 *	aparece associado a outro projeto
				*/ 
				itb = find (blacklist.begin(), blacklist.end(), aux);
				if((ret.second == false && ret.first->second != prjname) || itb != blacklist.end()) {
					/* cout << "Repeated: [usr]: " << aux << " [prj1]: " <<  ret.first->second << " [pr2]: " << prjname << "\n"; */
					it = pivot.find(aux);
					pivot.erase(it);
					if(itb == blacklist.end())
						blacklist.push_back(aux);
				}
			}
			/* Project Name */
			else if(isupper(aux[0])){
				prjname = aux;
				partials[prjname] = 0;
			}

		}while(1);

		for(it=pivot.begin(); it!=pivot.end(); ++it){
			/* cout << it->first << " " << it->second << '\n'; */
			partials[it->second]++;
		}

		/* cout << "1\n\n"; */

		for(its=partials.rbegin(); its!=partials.rend(); ++its){
			/* cout << its->first << " " << its->second << '\n'; */
			results.insert(IS(its->second, its->first));
		}
		
		/* cout << "2\n\n"; */

		for(iti=results.rbegin(); iti!=results.rend(); ++iti){
			cout << iti->second << " " << iti->first << '\n';
		}

		/* APAGA */
		pivot.clear();
		partials.clear();
		results.clear();

	}while(aux != "0");
	/*cout << "Saiu 0" << "\n";*/

	return 0;
}