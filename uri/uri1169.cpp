#include <iostream>
#include <cmath>

using namespace std;

// accepted
int main() {
	int t;
	unsigned long long n, resp;

	cout.precision(0);
	cout << fixed;

  for(cin >> t; t; t--) {
    cin >> n;
		cout << floor(pow(2, n) / 12000) << " kg\n";
	}

	return 0;
}
