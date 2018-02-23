#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int n, m;

	cin >> n;

	while(n) {
		cin >> m;
		v.push_back(m);
		n--;
	}

	int i = 2;
	for(vector<int>::iterator it = v.begin(); it != v.end() - 1; it++, i++) {
		if(*(it + 1) < *it) {
			cout << i << endl;
			return 0;
		}
	}

	i = 0;
	cout << i << endl;

	return 0;
}
