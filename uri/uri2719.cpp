#include <iostream>

using namespace std;

// accepted
int v[10100];

int main() {
	int t, n, m, soma, peso, cont;

	for(cin >> t; t; t--) {
		cin >> n >> m;

		for(int i = 0; i < n; i++) {
			cin >> peso;
			v[i] = peso;
		}

		soma = cont = 0;
		for(int i = 0; i < n; i++) {
			soma += v[i];
			if(soma == m){
				cont++;
				soma = 0;
			}
			 else if(soma > m) {
				cont++;
				i--;
				soma = 0;
			}
			else if(i + 1 == n && soma < m)
				cont++;
		}

		if(cont == 0)
			cont++;

		cout << cont << "\n";
	}

	return 0;
}
