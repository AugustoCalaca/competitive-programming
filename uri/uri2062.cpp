#include <iostream>
#include <string>

using namespace std;

// accepted
int main() {
	int n;
	string str;

	for(cin >> n; n--;) {
		cin >> str;
		if(str.size() != 3)
			cout << str;
		else {
			if(str[0] == 'U' && str[1] =='R') {
				str[2] = 'I';
				cout << str;
			}
			else if(str[0] == 'O' && str[1] =='B') {
				str[2] = 'I';
				cout << str;
			}
			else
				cout << str;
		}
		if(n > 1)
			cout << " ";
	}

	cout << endl;

	return 0;
}
