#include <iostream>
#include <string>

#define CALC (str[i] - jump)
using namespace std;

// accepted
int main(){

	int t, jump;
	string str;

	for(cin >> t; t--;){
		cin >> str >> jump;

		for(size_t i = 0; i < str.size(); i++)
			str[i] = CALC < 65 ? 91 - (65 - CALC) : str[i] = CALC;
		cout << str << "\n";
	}

	return 0;
}
