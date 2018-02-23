#include <iostream>
#include <map>

using namespace std;

// accepted
int main() {
	int n, val;
	map<int, int> m;

	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 0;

	for(cin >> n; n; n--) {
		cin >> val;
		if(val % 2 == 0)
			m[2]++;
		if(valor % 3 == 0)
			m[3]++;
		if(valor % 4 == 0)
			m[4]++;
		if(valor % 5 == 0)
			m[5]++;

	}

	for(auto it = m.begin(); it != m.end(); it++)
		cout << it->second << " Multiplo(s) de " << it->first << endl;

	return 0;
}
