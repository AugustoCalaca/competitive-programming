#include <iostream>
#include <algorithm>

using namespace std;

// accepted
int gcd(int a, int b) {
	while(b > 0) {
		a %= b;

		a ^= b;
		b ^= a;
		a ^= b;
	}

	return a;
}

int main() {
	int n, lim, v;

	int lcmPar = 1;
	for(cin >> n >> lim; n--;) {
		cin >> v;
		lcmPar = (lcmPar * v) / gcd(max(lcmPar, v), min(lcmPar, v));

	}

	int lcm = lcmPar, maxTime, maxRange = 1;

	for(int i = 1; i <= lim; i++) {
		lcmPar = (lcm * i) / gcd(max(lcm, i), min(lcm, i));
		if(lcmPar <= lim && lcmPar > maxRange) {
			maxTime = i;
			maxRange = lcmPar;
		}
	}

	cout << maxTime << endl;
	return 0;
}
