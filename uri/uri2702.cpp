#include <iostream>

using namespace std;

// accepted
int main() {

	int v[10], s1, s2 = 0;

	for(int i = 0; i < 6; i++)
		cin >> v[i];

	for(int i = 0; i < 3; i++) {
		s1 = v[i + 3] - v[i];
		if(s1 > 0)
			s2 += s1;
	}

	cout << s2 << endl;

	return 0;
}
