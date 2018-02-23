#include <iostream>
#include <cmath>

#define verOuFalso return true; else return false;
using namespace std;


// accepted
// sem formalidades kk
int ano[10000];

bool divTres(int soma) {
	if(soma % 3 == 0)
	verOuFalso
}

bool divQuatro(int n) {
	if(n % 4 == 0)
	verOuFalso
}

bool divCinco(int tam) {
	if(ano[tam - 1] == 0 || ano[tam - 1] == 5)
	verOuFalso
}

bool divOnze(int sp, int si) {
	if(abs(sp - si) % 11 == 0)
	verOuFalso
}

bool divQuinze(int soma, int tam) {
	if(divTres(soma) && divCinco(tam))
	verOuFalso
}

bool divCinqCinco(int sp, int si, int tam) {
	if(divCinco(tam) && divOnze(sp, si))
	verOuFalso
}

bool divCem(int tam) {
	if(ano[tam - 2] == 0 && ano[tam - 1] == 0)
	verOuFalso
}

bool divQuaCentos(int n) {
	return divQuatro(n);
}

int main() {
	string str, resp;
	int tam, sp, si, soma;

	resp = "";
	while(cin >> str) {
		tam = str.size();
		soma = sp = si = 0;

		for(int i = 0; i < tam; i++) {
			ano[i] = str[i] - '0';
			soma += ano[i];

			if(i % 2 == 0)
				sp += ano[i];
			else
				si += ano[i];
		}

		bool bissexto = ((divQuatro(ano[tam - 2] * 10 + ano[tam - 1]) && !divCem(tam)) ||
						((divQuatro(ano[tam - 2] * 10 + ano[tam - 1]) && divCem(tam)) &&
					   divQuaCentos(ano[tam - 4] * 10 + ano[tam - 3])));
		bool huluculu = divQuinze(soma, tam);
		bool bulukulu = (bissexto && divCinqCinco(sp, si, tam));

		if(bissexto) resp += "This is leap year.\n";
		if(huluculu) resp += "This is huluculu festival year.\n";
		if(bulukulu) resp += "This is bulukulu festival year.\n";
		if((!bissexto && !huluculu) && !bulukulu) resp += "This is an ordinary year.\n";
		resp += "\n";
	}

	// retira a ultima quebra de linha
	resp.erase(resp.size() - 1);
	cout << resp;

	return 0;
}
