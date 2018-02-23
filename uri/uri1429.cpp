#include <iostream>

using namespace std;

// accepted
int main() {
	int acm, vt[10];

	while(true) {
		cin >> acm;
		if(acm == 0)
			break;

		int i = 0;
		for(; acm; i++) {
			vt[i] = acm % 10;
			acm /= 10;
		}

		int fat[8];
		fat[0] = 1;
		for(int j = 1; j <= i; j++)
			fat[j] = fat[j - 1] * j;

		int soma = 0;
		for(int k = 0; k < i; k++)
			soma += vt[k] * fat[k + 1];

		cout << soma << endl;
	}

	return 0;
}
