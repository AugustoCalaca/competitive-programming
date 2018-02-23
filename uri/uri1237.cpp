
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// accepted
int subCont(string& str, string& str2) {
	int sz = str.size(), sz2 = str2.size();
	int gre = 0, count;

	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < sz2; j++) {
			count = 0;
			if(str[i] == str2[j]) {
				int k = 0;
				for(; (k + i < sz2), (k + j < sz2); k++ ) {
					if(str[k + i] != str2[k + j])
						break;
					count++;
				}
				j = k + j;
				if(count > gre)
					gre = count;
			}
		}
	}

	return gre;
}

int main() {
	string str, str2;

	while(getline(cin, str), getline(cin, str2))
		cout << subCont(str, str2) << endl;

	return 0;
}
