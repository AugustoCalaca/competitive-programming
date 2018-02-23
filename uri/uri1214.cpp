#include <iostream>
#include <cstdio>
#include <vector>

#define pb push_back
#define C 100

// accepted
using namespace std;
int main() {
	int casos, alunos, nota;
	float soma, cont, media;
	vector<float> notas;

	cout.precision(3);
	cout << fixed;

	for(cin >> casos; casos--; ) {
		soma = 0, cont = 0, media = 0;
		for(cin >> alunos; alunos--;) {
			cin >> nota;
			soma += nota;
			notas.pb(nota);
		}

		media = soma / notas.size();
		for(auto it = notas.begin(); it != notas.end(); it++)
			if(*it > media)
				cont++;

		cout << (cont / notas.size()) * C;
		printf("%%\n");

		notas.clear();
	}

	return 0;
}
