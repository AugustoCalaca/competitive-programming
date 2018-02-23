#include <iostream>
#include <map>

#define M 4
using namespace std;
typedef unsigned int ui;

// accepted
int main() {
	ui t, n;
	map<ui, ui> m;

	m[0] = 1;
	m[1] = 7;
	m[2] = 9;
	m[3] = 3;

	cin.tie(NULL);
	cout.sync_with_stdio(false);

	// n % M = n & (M - 1)
	for(cin >> t; t; t--) {
		cin >> n;
		cout << m[n & 3] << "\n";
	}

	return 0;
}
