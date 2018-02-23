#include <iostream>
#include <string>
#include <vector>

using namespace std;

// accepted
int main() {
	int test, people;
	string strAtu;

	for(cin >> test; test--;) {
		bool flag = false;
		vector<string> idiom;

		for(cin >> people; people--;) {
			cin >> strAtu;
			idiom.push_back(strAtu);
		}

		auto it = idiom.begin() + 1;
		for(; it != idiom.end(); it++) {
			if(*it != *(it - 1)) {
				cout << "ingles\n";
				flag = true;
				break;
			}
		}

		if(!flag)
			cout << *(it - 1) << endl;
	}

	return 0;
}
