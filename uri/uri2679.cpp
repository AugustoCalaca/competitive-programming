#include <iostream>

using namespace std;

int main() {
	unsigned int x;

	cin >> x;

	if(x % 2 == 0)
		cout << x + 2 << "\n";
	else
		cout << x + 1 << "\n";

	return 0;
}
