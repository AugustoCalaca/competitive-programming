#include <iostream>
#include <cmath>

#define D 12
using namespace std;

// accepted
int main() {
	double d, vf, vg;
	double dg, tg, tf;

	cout.precision(4);
	cout << fixed;

	while(cin >> d >> vf >> vg) {
		dg = sqrt(pow(D, 2) + pow(d, 2));
		tg = dg / vg;
		tf = D / vf;

		if(tg <= tf)
			cout << "S\n";
		else
			cout << "N\n";
	}

	return 0;
}
