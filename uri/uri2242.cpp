#include <iostream>
#include <string>
#include <vector>

using namespace std;

// accepted
int main(){
	string risada;
	vector<char> vogais;

	cin >> risada;

	for(auto its = risada.begin(); its != risada.end(); its++)
		if(*its == 'a' || *its == 'e' || *its == 'i' || *its == 'o' || *its == 'u' )
			vogais.push_back(*its);

	int tam = vogais.size();
	size_t metade = tam / 2;
	size_t i = 0;
	tam -= 1;
	for(; i < metade && vogais[i] == vogais[tam - i]; i++){}

	if(i >= metade) cout << "S";
	else cout << "N";
	cout << "\n";

	return 0;
}
