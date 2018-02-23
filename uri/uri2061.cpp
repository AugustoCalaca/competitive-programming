#include <iostream>
#include <string>

using namespace std;

// accepted
int main() {
	int inicial, qtd, fechou = 0, clicou = 0;
	string str;

	cin >> inicial >> qtd;

	for(; qtd; qtd--) {
		cin >> str;

		if(str == "fechou")
			fechou++;
		if(str == "clicou")
			clicou++;
	}

	cout << inicial + (fechou - clicou) << endl;


	return 0;
}
