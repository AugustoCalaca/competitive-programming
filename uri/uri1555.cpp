#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

// accepted
int main() {
	int t, n1, n2;
	float v[5];
	map<int, string> m;

	m[0] = "Rafael";
	m[1] = "Beto";
	m[2] = "Carlos";

	for(cin >> t; t--;) {
		cin >> n1 >> n2;
		v[0] = 9 * pow(n1, 2) + pow(n2, 2);
		v[1] = 2 * pow(n1, 2) + 25 * pow(n2, 2);
		v[2] = (-100 * n1) + pow(n2, 3);
		cout << m[distance(v, max_element(v, v + 3))] << " ganhou\n";
	}

	return 0;
}
