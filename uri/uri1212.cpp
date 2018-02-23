#include <iostream>

using namespace std;

// accepted
int main() {
	int a, b;
	string va, vb;
	while(true) {
		cin >> va >> vb;

		if(va == "0" && vb == "0") break;

		a = va.size() - 1;
		b = vb.size() - 1;

		string maior = a >= b ? va : vb;

		int cont = 0, carry = 0;
		for(; a >= 0 && b >= 0; a--, b--) {
			if(va[a] - '0' + vb[b] - '0' + carry > 9) {
				cont++;
				carry = 1;
			} else
				carry = 0;
		}

		int m = a >= 0 ? a : b;
		if(carry == 1) {
			for(; m >= 0; m--) {
				if(maior[m] - '0' + carry > 9) cont++;
				else break;
			}

		}

		if(cont == 0)
			cout << "No";
		else
			cout << cont;
		if(cont > 1)
			cout << " carry operations.\n";
		else
			cout << " carry operation.\n";
	}


	return 0;
}
