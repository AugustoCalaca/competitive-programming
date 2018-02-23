#include <iostream>
#include <vector>

#define pb push_back
using namespace std;

// accepted
typedef unsigned long long ul;
vector<ul> fat;

ul fatorial(int num) {
	int tam = fat.size();
	if(num >= tam) {
		for(int i = tam; i <= num; i++)
			fat.pb(fat[i - 1] * i);
	}

	return fat[num];
}

int main() {
	int m, n;
	ul  fm, fn;

	fat.pb(1);
	while(cin >> n >> m) {
		fm = fatorial(m);
		fn = fatorial(n);

		cout << fm + fn << "\n";
	}

	return 0;
}
