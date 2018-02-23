#include <iostream>
#include <climits>

#define pb push_back
using namespace std;

// accepted
int main() {
	int n;
	int fat[10];

	fat[0] = 1;
	cin >> n;

	int i = 1;
	for(; ; i++) {
		fat[i] = fat[i - 1] * i;
		if(fat[i] >= n)
			break;
	}

	i -= 1; // maior fatorial

	int tb[n];
	tb[0] = 0;
	for(int k = 1; k <= n; k++)
		tb[k] = INT_MAX;

	for(int k = 1; k <= n; k++) {
		for(int j = 1; j <= i; j++) {
			if(fat[j] <= k) {
				int aux = tb[k - fat[j]];
				if((aux != INT_MAX) && (aux + 1 < tb[k]))
					tb[k] = aux + 1;
			}
		}
	}

	cout << tb[n] << endl;

	return 0;
}
