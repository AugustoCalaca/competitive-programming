#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// accepted
int main() {
	char pl;
	while(true) {
		string str;

		bool ok = false;
		getline(cin, str);

		if(str == "*")
			break;

		int tam = str.size();
		int i = 0;
		for(; i < tam - 1; i++) {
			if(str[i] != ' ' && !ok) {
				pl = tolower(str[i]);
				achou = true;
			}

			if(str[i] == ' ' && ok) {
				while(str[i + 1] == ' ')
					i++;
				if(tolower(str[i + 1]) != pl) {
					cout << "N\n";
					break;
				}
			}
		}

		if(i + 1 == tam)
			cout << "Y\n";
	}

	return 0;
}
