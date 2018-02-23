#include <iostream>
#include <algorithm>

using namespace std;

// accepted
int main() {
	int t, alunos, magico, adivinha;
	int v[15];

	for(cin >> t; t; t--) {
		cin >> alunos >> magico;
		for(int i = 0; i < alunos; i++) {
			cin >> adivinha;
			v[i] = abs(magico - adivinha);
		}
		cout << distance(v, min_element(v, v + alunos)) + 1 << endl;
	}
}
