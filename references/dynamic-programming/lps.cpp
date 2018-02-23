#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int lps(string& str) {
	int sz = str.size();
	int tb[sz][sz];

	// strings de tamanho 1 sao palindromos de tamanho 1, logo
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < sz; j++) {
			if(i == j)
				tb[i][j] = 1;
			else
				tb[i][j] = 0;
		}

	// se forem diferentes pega o max da celula da esquerda com a celula de baixo
	// se forem iguais pega o da diagonal de baixo mais 2
	for(int i = 0; i < sz; i++) {
		int k = 0;
		for(int j = i + 1; j < sz; j++) {
			if(str[k] == str[j])
				tb[k][j] = tb[k + 1][j - 1] + 2;
			else
				tb[k][j] = max(tb[k][j - 1], tb[k + 1][j]);
			k++;
		}
	}

	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < sz; j++)
			cout << " " << tb[i][j];
		cout << endl;
	}

	return tb[0][sz - 1];
}

int main() {
	string str("MARTRAM");

	cout << lps(str) << endl;

	return 0;
}
