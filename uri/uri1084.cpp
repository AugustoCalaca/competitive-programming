#include <iostream>
#include <string>

using namespace std;

// accepted
int main() {
	int dig, apa, cont;

	while(true) {
		cin >> dig >> apa;
		if(dig == 0 && apa == 0)
			break;

		size_t dif = dig - apa;
		string str;
		cin >> str;
		string lista;
		cont = 0;
		for(int i = 0; i < dig; i++) {
			if(lista.empty())
				lista.push_back(str[i]);
			else {
				if(str[i] > lista.back() && cont < apa) {
					while(str[i] > lista.back() && !lista.empty()) {
						lista.pop_back();
						cont++;
						if(cont == apa)
							break;
					}
					lista.push_back(str[i]);
				}
				else
					if(lista.size() < dif)
						lista.push_back(str[i]);
			}
		}

		cout << lista << endl;
	}

	return 0;
}
