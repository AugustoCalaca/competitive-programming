#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

// accepted
int main(){

	int teste, cont;
	string diamante;

	for(cin >> teste; teste--) {
		cin >> diamante;
		cont = 0;
		auto fim = remove(diamante.begin(), diamante.end(), '.');
		for(auto it = diamante.begin(); it != fim; it++) {
			if(*it == '<' && find(it, fim, '>') != fim) {
				diamante[distance(diamante.begin(), find(it, fim, '>'))] = 'a';
				cont++;
			}
		}
		cout << cont << "\n";
		diamante.clear();
	}

	return 0;
}
