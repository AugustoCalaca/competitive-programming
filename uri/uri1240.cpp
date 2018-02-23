#include <iostream>
#include <string>

using namespace std;

// accepted
int main() {
	int t;
	string str, str2;

	for(cin >> t; t--;) {
		cin >> str >> str2;

		int sz = str.size();
		int sz2 = str2.size();

		int i = sz - sz2;
		for(int j = 0; i < sz && j < sz2; ) {
			if(str[i] == str2[j]) {
				i++;
				j++;
			}
			else break;
		}

		if(i == sz)
			cout << "encaixa\n";
		else
			cout << "nao encaixa\n";
	}

	return 0;
}
