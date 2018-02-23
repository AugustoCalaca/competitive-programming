#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

// accepted
int main() {
	int t, tam;
	string str, res1, res2;

	cin >> t;
	cin.ignore(128, '\n');

	for(; t; t--) {
		getline(cin, str);

		tam = str.size();
		res1 = res2 = "";
		for(int i = (tam / 2) - 1, j = tam - 1; i >= 0; i--, j--) {
			res1 += str[i];
			res2 += str[j];
		}

		cout << res1 + res2 << endl;
	}

	return 0;
}
