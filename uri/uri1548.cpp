#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

// accepted
int main() {
	int t, qtd, n;
	int notas[1110];
	int notasOrd[1110];

	for(cin >> t; t--;) {
		cin >> qtd;
		for(int i = 0; i < qtd; i++) {
			cin >> n;
			notas[i] = n;
			notasOrd[i] = n;
		}

		sort(notasOrd, notasOrd + qtd, greater<int>());

		int nMuda = 0;
		for(int i = 0; i < qtd; i++)
			if(notasOrd[i] == notas[i])
				nMuda++;

		cout << nMuda << endl;
	}

	return 0;
}
