#include <iostream>
#include <vector>
#include <climits>

#define pb push_back
using namespace std;

// accepted
int main() {
	vector<int> tamBlocos, tabela;
	int blocoArtista, inst, numBlocos, tam;

	for(cin >> inst; inst--; ) {
		cin >> numBlocos >> blocoArtista;
		for(int i = 0; i < numBlocos; i++) {
			cin >> tam;
			tamBlocos.pb(tam);
		}

		tabela.pb(0);
		for(int i = 1; i <= blocoArtista; i++)
			tabela.pb(INT_MAX);

		for(int i = 1; i <= blocoArtista; i++) {
			for(int j = 0; j < numBlocos; j++) {
				if(tamBlocos[j] <= i) {
					int aux = tabela[i - tamBlocos[j]];
					if((aux != INT_MAX) && (aux + 1 < tabela[i]))
						tabela[i] = aux + 1;
				}
			}
		}

		cout << tabela[blocoArtista] << "\n";
		tamBlocos.clear();
		tabela.clear();
	}

	return 0;
}

