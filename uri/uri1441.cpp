#include <iostream>

using namespace std;

// accepted
int main() {
	int h, atual, max;
	while(true) {
		cin >> h;
		if(h == 0)
			break;

		max = 1;
		while(h != 1) {
			if(h > max)
				max = h;

			if(h % 2 == 0)
				atual = 0.5 * h;
			else
				atual = (3 * h) + 1;
			h = atual;
		}

		cout << max << endl;
	}

	return 0;
}
