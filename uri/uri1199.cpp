#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// accepted
int main() {
	string n;

	while(true) {
		cin >> n;

		if(n == "-1")
			break;
		if(n[1] == 'x') {
			long d = stol(n, nullptr, 16);
			printf("%ld\n", d);
		} else {
			long d2 = stol(n, nullptr, 10);
			printf("0x%X\n", d2);
		}
	}

	return 0;
}

