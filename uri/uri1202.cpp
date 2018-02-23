#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

#define CICLO 1500
using namespace std;

// accepted
typedef unsigned long long int ll;

ll tabFib[1600];

ll binInt(string bin) {
	ll n = 0;
	int tam = bin.size();
	for(int i = 0; i < tam; i++) {
		n *= 2;
		n += (bin[i] - '0');
		n %= CICLO;
	}
	return n;
}

ll fib(ll nEsimo) {
	return tabFib[nEsimo];
}

int main() {
	int tst;
	string bin;
	ll n, nEsimoFib;

	tabFib[1] = tabFib[2] = 1;

	for(int i = 3; i < 1510; i++)
		tabFib[i] = (tabFib[i - 1] + tabFib[i - 2]) % 1000;

	for(cin >> tst; tst--;) {
		cin >> bin;

		n = binInt(bin);
		nEsimoFib = fib(n);
		cout << setfill('0') << setw(3) << nEsimoFib << "\n";
	}

	return 0;
}
