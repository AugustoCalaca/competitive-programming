#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;

	cin >> N;
	string str[N], strTest;

	cin.ignore(256, '\n');
	for(int aux = 0; aux < N; aux++){
		getline(cin, strTest);
		for(string::iterator it = strTest.begin(); it != strTest.end(); it++){
			if((*it >= 65 && *it <= 90) || (*it >= 97 && *it <= 122))
				*it += 3;
		}

		reverse(strTest.begin(), strTest.end());
		for(string::iterator it = strTest.begin() + (strTest.size() / 2); it != strTest.end(); it++)
			*it -= 1;

		str[aux] = strTest;
	}

	for(int aux = 0; aux < N; aux++)
		cout << str[aux] << "\n";

	return 0;
}
