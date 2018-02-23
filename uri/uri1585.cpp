#include <iostream>

using namespace std;

// accepted
int main() {
 	int t, b, alt;

 	for(cin >> t; t; t--) {
 		cin >> b >> alt;
 		cout << b * alt / 2 << " cm2\n";
 	}

	return 0;
}
