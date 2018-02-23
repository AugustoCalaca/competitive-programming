#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// accepted
int main(){

	int num, cont;
	string str;

	cin >> num;

	getline(cin, str);
	for(; num; num--){
		getline(cin, str);

		auto fim = remove(str.begin(), str.end(), ' ');
		cont = 0;
		set<char> s(str.begin(), fim);

		for(auto it = s.begin(); it != s.end(); it++)
			if(*it > 96 && *it < 123)
				cont++;

		if(cont == 26)
			cout << "frase completa\n";
		else if(cont > 12)
				cout << "frase quase completa\n";
			else
				cout << "frase mal elaborada\n";
	}

	return 0;
}
