#include <iostream>
#include <cmath>

using namespace std;

// accepted
// p = (1 - (q/p)^n1) / (1 - (q/p)^(n1+n2))
double gamblerRuin(int ev1, int ev2, int at) {
	if(at == 3)
		return (ev1 * 1.0)  / (ev1 + ev2);

	double p, q;
	p = at / 6.0;
	q = 1 - p;

	return ((1.0 - pow((q / p), ev1)) / (1.0 - pow((q / p), (ev1 + ev2))));
}

int main() {
	int ev1, ev2, at, d, aux;

	cout.precision(1);
	cout << fixed;

	while(true) {
		cin >> ev1 >> ev2 >> at >> d;
		if(ev1 == 0) break;

		aux = ev1;
		ev1 = 0;
		while(aux > 0) {
			aux -= d;
			ev1++;
		}

		aux = ev2;
		ev2 = 0;
		while(aux > 0) {
			aux -= d;
			ev2++;
		}

		cout << 100 * gamblerRuin(ev1, ev2, at) << "\n";
	}

	return 0;
}
