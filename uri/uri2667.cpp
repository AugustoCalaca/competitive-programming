#include <iostream>
#include <string>

#define MOD 3

using namespace std;

// accepted
int main(){
	int sum = 0;
	string numb;

	cin >> numb;

	for(size_t i = 0; i < numb.size() ; i++)
		sum += (numb[i] - '0');
	cout << sum % MOD << "\n";

	return 0;
}
