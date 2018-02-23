#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

// accepted
int main() {
	int n, k;
	int v[1100];

	while(true) {
		cin >> n >> k;
		if(!n && !k)
			break;
		set<int> conj;
		for(int i = 0; i < n; i++) {
			cin >> v[i];
			conj.insert(v[i]);
		}

		int qtd = 0;
		for(auto it = conj.begin(); it != conj.end(); it++) {
			if(count(v, v + n, *it) >= k)
				qtd++;
		}

		cout << qtd << endl;
	}

	return 0;
}
