#include <iostream>
#include <map>

using namespace std;

// accepted
int main() {
	map<int, string> m;
	m[0] = "Rudolph";
	m[1] = "Dasher";
	m[2] = "Dancer";
	m[3] = "Prancer";
	m[4] = "Vixen";
	m[5] = "Comet";
	m[6] = "Cupid";
	m[7] = "Donner";
	m[8] = "Blitzen";

	int v, soma = 0;

	for(int i = 0; i < 9; i++) {
		cin >> v;
		soma += v;
	}

	cout << m[soma % 9] << "\n";

	return 0;
}
