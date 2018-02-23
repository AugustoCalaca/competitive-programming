#include <iostream>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

// accepted
int main() {
	int n, b, v;
	int vt[100];

	while(true) {
		cin >> n >> b;
		if(n == 0 && b == 0)
			break;

		set<int> conj;
		for(int i = 0; i < b; i++) {
			cin >> v;
			vt[i] =  v;
		}

		sort(vt, vt + b, greater<int>());

		conj.insert(vt[0] - vt[0]); // adiciona logo o 0
		for(int i = 0; i < b - 1; i++)
			for(int j = i + 1; j < b; j++)
				conj.insert(vt[i] - vt[j]);

		if(conj.size() == unsigned (n + 1))
			cout << "Y";
		else
			cout << "N";
		cout << "\n";
	}

	return 0;
}
