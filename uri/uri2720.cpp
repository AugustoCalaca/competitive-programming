#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define pb push_back
typedef unsigned int ui;

using namespace std;

// accepted
bool compare(const pair<ui, ui > &a, const pair<ui, ui > &b) {
	if(a.first == b.first)
		return (a.second < b.second);
	else
		return
			a.first > b.first;
}

int main() {
	int t, n, k, a, b, c;
	ui vol, id;
	vector<pair<ui, ui> > v;
	vector<ui> v2;

	cin.tie(NULL);
	cout.sync_with_stdio(false);

	for(cin >> t; t; t--) {
		cin >> n >> k;

		for(int i = 0; i < n; i++) {
			cin >> id >> a >> b >> c;
			vol = a * b * c;
			v.pb(make_pair(vol, id));
		}

		sort(v.begin(), v.end(), compare);
		int i = 0;
		for(auto it = v.begin(); i < k; it++, i++) {
			v2.pb(it->second);
		}

		sort(v2.begin(), v2.end());
		i = 0;
		for(auto it = v2.begin(); it != v2.end(); it++, i++) {
			cout << *it;
			if(i + 1 != k)
				cout << " ";
		}

		cout << "\n";
		v.clear();
		v2.clear();
	}


	return 0;
}
