#include <iostream>
#include <string>
#include <set>

#define qtdPoke 151

using namespace std;

// accepted
int main(){

	int num;
	string str;
	set<string> conj;

	cin >> num;

	getline(cin, str);
	for(; num; num--){
		getline(cin, str);
		conj.insert(str);
	}

	cout << "Falta(m) " << qtdPoke - conj.size() << " pomekon(s).\n";
	return 0;
}
