#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <map>
#include <vector>
#include <functional>
#include <cstdio>

using namespace std;

// accepted
int main(){
	int casos, max;
	string frase;
	map<char, int> mapa;

	cin >> casos;
		getline(cin, frase);
	for(; casos; casos--){
		getline(cin, frase);

		auto fim = frase.end();
		fim = remove(frase.begin(), fim, ' ');
		for(auto i = frase.begin(); i != fim; i++){
			if(*i > 64 && *i < 91)
				*i = tolower(*i);
		}

		for(auto i = frase.begin(); i != fim; i++){
			if(*i > 96 && *i < 123){
				max = count(frase.begin(), fim, *i);
				mapa[*i] = max;
			}
		}

		vector<int> v;
		for(auto it = mapa.begin(); it != mapa.end(); it++)
			v.push_back(it->second);

		auto maxm = max_element(v.begin(), v.end());

		for(auto it = mapa.begin(); it != mapa.end(); it++)
			if(it->second == *maxm)
				cout << it->first;
		cout << "\n";

		mapa.clear();
		frase.clear();
	}

	return 0;
}
