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
	int val, ind, a, b;
	int v[5];

	for(int i = 0; cin >> val; i++) {
		if(i == 2)
		{
			v[i] = val;
			ind = distance(v, max_element(v, v + 3));

			if(ind == 0) {
				a = 1;
				b = 2;
			} else if(ind == 1) {
				a = 0;
				b = 2;
			} else if(ind == 2) {
				a = 0;
				b = 1;
			}

			if(v[ind] * v[ind] == v[a] * v[a] + v[b] * v[b]) {
				if(gcd(v[ind], gcd(max(v[a], v[b]), min(v[a], v[b]))) == 1)
					cout << "tripla pitagorica primitiva\n";
				else
					cout << "tripla pitagorica\n";

			} else cout << "tripla\n";

			i = -1;
		}
		else
			v[i] = val;
	}

	return 0;
}
