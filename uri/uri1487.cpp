#include <iostream>

using namespace std;

// accepted
int maiorPnt(int tempo[], int pnt[], int n, int tempoLimite) {
	int tabela[tempoLimite + 1];

	for(int j = 0; j <= tempoLimite; j++)
		tabela[j] = 0;

	for(int i = 1; i <= tempoLimite; i++) {
		for(int j = 1; j <= n; j++) {
			if(tempo[j - 1] <= i)
				if(pnt[j - 1] + tabela[i - tempo[j - 1]] >= tabela[i])
					tabela[i] = pnt[j - 1] + tabela[i - tempo[j - 1]];
		}
	}

	return tabela[tempoLimite];
}

int main() {
	int n, tempoLimite, vt, vp, cont = 1;

	while(true) {
		cin >> n >> tempoLimite;

		if(!n)
			break;

		int pnt[n + 5];
		int tempo[n + 5];

		for(int i = 0; i < n; i++) {
			cin >> vt >> vp;
			tempo[i] = vt;
			pnt[i] = vp;
		}

		cout << "Instancia " << cont++ << endl
			 	 << maiorPnt(tempo, pnt, n, tempoLimite) << endl << endl;
	}

	return 0;
}
