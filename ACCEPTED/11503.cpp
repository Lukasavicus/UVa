
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>

#define MAX 112345

using namespace std;

/* Weighted_Quick_Union_and_Find_Algorithm */
template <class T>
class WQUFA{

	// Type of element will be T, and group of the element will be represented by an int number;
	map<T, int> hash;
	//unordered_map<T, int> hash;
	int sz[MAX];
	int id[MAX];
	int n_elements;

	private:
		int root(int e){
			while(e != id[e]){
				id[e] = id[id[e]];
				e = id[e];
			}
			return e;
		}

		bool insert_element(T e){ //insert element

			if(hash.insert(pair< T, int >(e,n_elements)).second == true){
				id[n_elements] = n_elements;
				sz[n_elements] = 1;

				n_elements++;
				return true;
			}
			return false;
		}

		//union of groups of each element
		void union_elements(T p, T q){
			// Maybe access the wrong position (outof bounds). In this case use try-catch structure
			int i = root(id[hash[p]]);
			int j = root(id[hash[q]]);

			if(!connected(p,q)){

				if(sz[i] < sz[j]){
					id[i] = j;
					sz[j] += sz[i];
				}
				else{
					id[j] = i;
					sz[i] += sz[j];
					if(sz[i] > sz[j])
						sz[j]++;
				}
			}
		}
	
	public:

		WQUFA(){
			n_elements = 0;
		}

		void insert_elements(T p, T q){
			bool ins_p = insert_element(p);
			bool ins_q = insert_element(q);
			union_elements(p, q);
		}


		//check if two elements are connect, verify if two elements are in the same group
		bool connected(T p, T q){
			return root(id[hash[p]]) == root(id[hash[q]]);
		}

		int number_connections(T p){
			int hp = hash[p];
			int idhp = id[hash[p]];
			int root_idhp = root(id[hash[p]]);
			int sz_root_idhp = sz[root(id[hash[p]])];

			//printf("hp:%d\thq:%d\tid[hp]:%d\tid[hq]:%d\troot(id[hp]):%d\troot(id[hq]):%d\tsz[root(id[hp])]:%d\tsz[root(id[hq])]:%d\n", hp, hq, idhp, idhq, root_idhp, root_idhq, sz_root_idhp, sz_root_idhq);
			
			return sz_root_idhp;
		}

		int find_group(T e){ //return the group of element
			return root(id[hash[e]]);
		}
};

main(){

	WQUFA<string> t;
	string s1, s2;
	int cases, friendship;
	int i, j;

	cin >> cases;
	for(i = 0; i < cases; i++){
		cin >> friendship;
		t = WQUFA<string>();
		for(j = 0; j < friendship; j++){
			cin >> s1;
			cin >> s2;
			t.insert_elements(s1, s2);
			printf("%d\n", t.number_connections(s1));
		}
		//t.print_ids();
	}
}