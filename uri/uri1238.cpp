#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// accepted
int main() {
	string str1, str2, ans;
	int t, sz1, sz2;

	for(cin >> t; t; t--) {
		cin >> str1 >> str2;
		sz1 = str1.size();
		sz2 = str2.size();

		int sz = max(sz1, sz2);
		ans = "";
		for(int i = 0; i < sz; i++) {
			if(i < sz1)
				ans += str1[i];
			if(i < sz2)
				ans += str2[i];
		}
		cout << ans << endl;
	}

	return 0;
}
