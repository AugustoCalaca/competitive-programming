#include <iostream>

using namespace std;

// accepted
int kadane(int v[], int tam) {
	int maxAtual = 0, maxTotal = -1;

	for(int i = 0; i < tam; i++) {
		maxAtual += v[i];

		if(maxAtual < 0)
			maxAtual = 0;
		if(maxAtual > maxTotal)
			maxTotal = maxAtual;
	}

	return maxTotal;
}

int main() {

	int tam, custo, valor, v[60];

	while(cin >> tam) {
		cin >> custo;
		for(int i = 0; i < tam; i++) {
			cin >> valor;
			v[i] = valor - custo;
		}

		cout << kadane(v, tam) << endl;
	}

	return 0;
}
