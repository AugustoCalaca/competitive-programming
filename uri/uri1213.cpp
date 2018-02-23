#include <iostream>

using namespace std;

// accepted
typedef long long int ll;
int main() {
	ll n, c, l;

	while(cin >> n) {
		l = c = 1;
		while(l) {
			l = (10 * l + 1) % n;
			c++;
		}

		cout << c << "\n";
	}

	return 0;
}
