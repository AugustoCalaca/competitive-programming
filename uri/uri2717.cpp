#include <iostream>

using namespace std;

// accepted
int main() {
	int fim, a, b;

	cin >> fim >> a >> b;

	if(a + b > fim)
		cout << "Deixa para amanha!\n";
	else
		cout << "Farei hoje!\n";

	return 0;
}
