#include <iostream>
#include <cmath>

using namespace std;

// accepted
int main() {
	int t, n;

	cout.precision(0);
	cout << fixed;

	for(cin >> t; t; t--) {
		cin >> n;
		if(n == 1)
			cout << "1\n";
		else
			cout <<  floor(pow(n + 1, 2) / 2) - 1 << endl;
	}

	return 0;
}
