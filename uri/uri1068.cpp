#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// accepted
int main() {
	int dir, esq;
	string str;
	vector<char> vec;

	while(cin >> str) {
		dir = esq = 0;
		for(auto i = str.begin(); i != str.end(); i++) {
			if(*i == '(')
				dir++;
			if(*i == ')')
				esq++;
			if(esq > dir)
				break;
			if(dir == esq)
				dir = esq = 0;
		}
		if(dir == esq) cout << "correct\n";
		else cout << "incorrect\n";
	}

	return 0;
}
