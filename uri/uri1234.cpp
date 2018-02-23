#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

// accepted
int main() {
	string str, prox;
	vector<string> v;
	int tam;
	bool f;

	while(getline(cin, str))
		v.push_back(str);

	for(auto it = v.begin(); it != v.end(); it++) {
		str = *it;
		tam = str.size();
		prox = "";

		f = true;
		for(int i = 0; i < tam; i++) {
			if(str[i] == ' ') {
				// f = false;
			}
			else {
				if(f) {
					str[i] = toupper(str[i]);
					f = false;
				}
				else {
					if(!f) {
						str[i] = tolower(str[i]);
						f = true;
					}
				}
			}
			prox += str[i];
		}
		cout << prox << endl;
	}


	return 0;
}
