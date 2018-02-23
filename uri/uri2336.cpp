#include <iostream>
#include <string>
#include <vector>

#define base 26
#define modul 1000000007
#define pb push_back
using namespace std;
typedef unsigned long long ll;


// accepted
vector<ll> v(1, 1);

ll mypow(int j) {
	int tam = v.size();
	if(j >= tam)
		for(int i = tam - 1; i < j; i++)
			v.pb(((v[i] % modul) * (base % modul)) % modul);

	return v[j];
}

int main() {
	ll ans;
	ll prod;
	int sz;
	string str;

	while(cin >> str) {
		sz = str.size();
		ans = 0;

		for(int i = sz - 1, j = 0; i >= 0; i--, j++) {
			prod = ((str[i] - 'A') * mypow(j)) % modul;
			ans = ((ans % modul) + prod) % modul;
		}

		cout << ans << endl;
	}

	return 0;
}
