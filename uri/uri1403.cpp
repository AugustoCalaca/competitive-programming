#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

// accepted
int main() {
	int n, l, valor;

	while(true) {
		cin >> n >> l;
		if(n == 0 && l == 0)
			break;

		map<int, int> m;
		vector<pair<int, int> > v;

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < l; j++) {
				cin >> valor;
				m[valor]++;
			}
		}

		for(auto it = m.begin(); it != m.end(); it++)
			v.push_back(make_pair(it->second, it->first));

		sort(v.begin(), v.end(), greater<pair<int, int> >());

		m.erase(m.find(v.begin()->second));
		v.erase(v.begin());

		int maior = v.begin()->first;

		for(auto it = m.begin(); it != m.end(); it++)
			if(it->second == maior)
				cout << it->first << " ";
		cout << endl;
	}

	return 0;
}
