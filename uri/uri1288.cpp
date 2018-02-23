#include <iostream>

using namespace std;

// accepted
int k(int valor[], int peso[], int e, int c) {
	int tabela[e + 1][c + 1];

	for(int i = 0; i <= e; i++)
		tabela[i][0] = 0;
	for(int j = 0; j <= c; j++)
		tabela[0][j] = 0;

	for(int i = 1; i <= e; i++) {
		for(int j = 1; j <= c; j++) {
			if(peso[i - 1] <= j) {
				if(valor[i - 1] + tabela[i - 1][j - peso[i - 1]] > tabela[i - 1][j])
					tabela[i][j] =  valor[i - 1] + tabela[i - 1][j - peso[i - 1]];
				else
					tabela[i][j] = tabela[i - 1][j];
			}
			else
				tabela[i][j] = tabela[i - 1][j];
		}
	}

	return tabela[e][c];
}

int main() {
	int tes, ele, valor, peso, cap, res;

	for(cin >> tes; tes--;) {
		cin >> ele;
		int vd[ele + 5], vp[ele + 5];
		for(int i = 0; i < ele; i++) {
			cin >> valor >> peso;
			vd[i] = valor;
			vp[i] = peso;
		}
		cin >> cap >> res;

		if(k(vd, vp, ele, cap) >= res)
			cout << "Missao completada com sucesso\n";
		else
			cout << "Falha na missao\n";
	}

	return 0;
}
