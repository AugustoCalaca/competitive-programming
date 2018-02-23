#include <iostream>

using namespace std;

// accepted
int main() {
	int n, a = 0;

	while(cin >> n) {
		if(n > a) a = n;
		else break;
	}

	if(a < n) a = n;
	cout << a + 1 << endl;

	return 0;
}
