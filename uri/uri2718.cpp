#include <iostream>

using namespace std;

// accepted
int main() {
	int t, resto, cont, maior;
	unsigned long long int num;

	for(cin >> t; t; t--) {
		cin >> num;

		cont = maior = 0;
		while(num) {
			resto = num % 2;
			if(resto == 1)
				cont++;
			else {
				cont = 0;
			}
			if(cont > maior)
				maior = cont;
			num /= 2;
		}

		cout << maior << "\n";
	}

	return 0;
}
