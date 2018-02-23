#include <iostream>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

// accepted
int main() {
	int n, cod, s, lim;

	for(cin >> n; n; n--) {
		cin >> cod;

		set<int> div;
		vector<int> v;
		vector<int> v2;

		lim = int (sqrt(cod));
		for(int i = 2; cod > 1 && i <= lim; ) {
			if(cod % i == 0) {
				v.push_back(i);
				cod /= i;
			}
			else
				i++;
		}
		if(cod > 1)
			v.push_back(cod);

		v2.push_back(1);
		for(auto it = v.begin(); it != v.end(); it++) {
			int sz = v2.size();
			for(int i = 0; i < sz; i++)
				v2.push_back((*it) * v2[i]);
		}

		div.insert(v2.begin(), v2.end());
		s = 0;
		for(auto it = div.begin(); it != div.end(); it++)
			s += *it;

		cout << s << endl;
	}

	return 0;
}
