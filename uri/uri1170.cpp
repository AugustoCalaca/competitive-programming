#include <iostream>
#include <cmath>

using namespace std;

// accepted
int main() {
	int t;
	double n;

	for(cin >> t; t--;) {
		cin >> n;
		cout << ceil(log2(n)) << " dias\n";
	}

	return 0;
}
