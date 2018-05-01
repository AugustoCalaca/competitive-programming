#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void showLcs(string& str, string& str2, vector<vector<int> >& tb) {
	int sz = str.size();
	int sz2 = str2.size();
	stack<char> sta;

	while(sz != 0 && sz2 != 0) {
		if(str[sz - 1] == str2[sz2 - 1]) {
			sta.push(str[sz - 1]);
			sz--;
			sz2--;
		}
		else {
			if(tb[sz - 1][sz2] > tb[sz][sz2 - 1])
				sz--;
			else
				sz2--;
		}
	}

	cout << "Greater LCS: ";
	while(!sta.empty()) {
		cout << sta.top();
		sta.pop();
	}
	cout << endl;
}

int lcs(string& str, string& str2) {
	int sz = str.size(), sz2 = str2.size();
	vector<vector<int> > tb(sz + 1);

	for(int i = 0; i <= sz; i++)
		tb[i].resize(sz2 + 1);

	for(int i = 0; i <= sz; i++)
		tb[i][0] = 0;
	for(int i = 1; i <= sz2; i++)
		tb[0][i] = 0;

	for(int i = 1; i <= sz; i++) {
		for(int j = 1; j <= sz2; j++) {
			if(str[i - 1] == str2[j - 1])
				tb[i][j] = tb[i - 1][j - 1] + 1;
			else
				tb[i][j] = max(tb[i - 1][j], tb[i][j - 1]);
		}
	}

	showLcs(str, str2, tb);

	return tb[sz][sz2];
}

int main() {
	string str("abcdef"), str2("cdofhij");
	cout << "Size LCS: " << lcs(str, str2) << endl;

	return 0;
}

