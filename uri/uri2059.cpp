#include <iostream>

using namespace std;

// accepted
int main() {
	int p, j1, j2, r, a, s, g;

	cin >> p >> j1 >> j2 >> r >> a;

	s = j1 + j2;
	if((s % 2 == 0 && p == 1) || (s % 2 != 0 && p == 0))
		g = 1;
	else
		g = 2;

	if(r == 1 && a == 1)
		g = 2;
	if(r != a)
		g = 1;

	cout << "Jogador " << g << " ganha!\n";

	return 0;
}
