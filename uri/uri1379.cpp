#include <iostream>

using namespace std;

// accepted
int main() {
	long long int a, b, c, mediana;
	long double media;

	while(true) {
		cin >> a >> b;
		if(a == 0 && b == 0)
			break;

		while(true) {
			mediana = a;
			c = 2 * mediana - b;
			media = (a + b + c) / 3;

			if(media == mediana) {
				cout << c << endl;
				break;
			}

			mediana = b;
			c = 2 * mediana - a;
			media = (a + b + c) / 3;

			if(media == mediana) {
				cout << c << endl;
				break;
			}

			mediana = (a + b) / 2;
			media = (a + b + c) / 3;
			if(media == mediana) {
				cout << mediana << endl;
				break;
			}
		}
	}

	return 0;
}
