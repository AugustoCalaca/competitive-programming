#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// accepted
int main(){
	int n;
	string str;

	for(cin >> n; n--;){
		cin >> str;

		if(str[0] == str[2])
			cout << (str[2] - '0') * (str[0] - '0')<< "\n";
		else{
			if(isupper(str[1]))
				cout << (str[2] - '0') - (str[0] - '0') << "\n";
			else
				cout << (str[2] - '0') + (str[0] - '0') << "\n";
		}
	}

	return 0;
}
