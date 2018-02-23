#include <iostream>
#include <string>
#include <vector>

#define pb push_back
using namespace std;

// accepted
int main() {
	int n, t, u;
	string str, strT;
	vector<string> vstr;

	for(cin >> n; n; n--) {
		cin >> t;
		for(int i = 0; i < t; i++) {
			cin >> str;
			vstr.pb(str);
		}

		for(cin >> u; u; u--) {
			cin >> strT;
			size_t ta = strT.size();
			int i = 0;
			for(; i < t; i++) {
				size_t fist = strT.find(vstr[i]);
				size_t sz = vstr[i].size();

				if(((fist != string:: npos) && (fist + sz <= ta)) &&
				   (strT[fist + sz] < 97 || strT[fist + sz] > 122) &&
				   (strT[fist + sz] < 48 || strT[fist + sz] > 57)) {
					cout << "Abortar\n";
					break;
				}
			}
			if(i == t)
				cout << "Prossiga\n";
		}
		if(n > 1)
			cout << "\n";

		vstr.clear();
	}

	return 0;
}
