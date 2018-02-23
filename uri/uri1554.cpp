#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// accepted
double dist(int xb, int yb, int x, int y) {
	return sqrt(pow(abs(xb - x), 2) + pow(abs(yb - y), 2));
}

int main() {
	int t, balls, x, y, xb, yb;
	double v[55];

	for(cin >> t; t--;) {
		cin >> balls;
		cin >> xb >> yb;
		for(int i = 0; i < balls; i++) {
			cin >> x >> y;
			v[i] = dist(xb, yb, x, y);
		}

		cout << distance(v, min_element(v, v + bolas)) + 1 << endl;
	}

	return 0;
}
