#include <iostream>

using namespace std;

// accepted
int main() {
	int A, B, C;

	while(cin >> A >> B >> C) {
		if(A == B && B == C)
			cout << "*\n";
		else {
			if(A != B && B == C)
				cout << "A\n";
			else {
				if(A != B && A == C)
					cout << "B\n";
				else
					if(A == B && A != C)
					cout << "C\n";
			}
		}
	}

	return 0;
}
