#include <iostream>
#include <string>
#include <cmath>
#include <stack>

#define b 16
using namespace std;
typedef unsigned long long ll;


// codigo que nem eu entendo peeeense...
// accepted
ll hd(string s) {
	ll inteiro = 0;
	int aux, i = 0;

	for(auto it = s.rbegin(); it != s.rend(); it++, i++) {
		bool f = false;
		if(*it == 'a') {
			aux = 10;
			f = true;
		}
		else {
			if(*it == 'b') {
				aux = 11;
				f = true;
			}
			else  {
				if(*it == 'c') {
					aux = 12;
					f = true;
				}
				else {
					if(*it == 'd') {
						aux = 13;
						f = true;
					}
					else {
						if(*it == 'e') {
							aux = 14;
							f = true;
						}
						else
							if(*it == 'f') {
								aux = 15;
								f = true;
							}
					}
				}
			}
		}


		inteiro += (f ? aux : (*it - '0')) * pow(b, i);
	}

	return inteiro;
}

int main() {
	string s1, s2, s3;
	ll in1, in2, in3, acum, aux1, aux2;

	cin >> s1 >> s2 >> s3;

	in1 = hd(s1);
	in2 = hd(s2);
	in3 = hd(s3);

	aux1 = pow(int(in1 / in2), 2);
	acum = aux1 + 1;
	aux2 = pow(int(in2 / in3), 2);

	stack<char> pilha;
	ll resp = (aux1 * aux2) + acum;
	int resto;
	while(resp) {
		resto = resp % b;
		pilha.push(resto > 9 ? resto + 87 : resto + '0');
		resp /= b;
	}

	while(!pilha.empty()) {
		cout << pilha.top();
		pilha.pop();
	}

	cout << endl;

	return 0;
}
