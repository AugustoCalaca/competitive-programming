#include <iostream>
#define _USE_MATH_DEFINES // macro M_PI
#include <cmath>

using namespace std;

// raio circ interna = 2 * areaTri / perimetro

// accepted
int main() {
	double a, b, c;
	double metadePer, areaTri, cirExt, cirInt, raio;

	cout.precision(4);
	cout << fixed;
	while(cin >> a >> b >> c) {
		metadePer = (a + b + c) / 2;

		areaTri = sqrt(metadePer * (metadePer - a)
					 * (metadePer - b) * (metadePer - c));

		raio = a * b * c /
				sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a));

		cirExt = M_PI * pow(raio, 2) - areaTri;

		raio = areaTri / metadePer;
		cirInt = M_PI * pow(raio, 2);

		areaTri -= cirInt;

		cout << cirExt << " " << areaTri << " " << cirInt << "\n";
	}

	return 0;
}
