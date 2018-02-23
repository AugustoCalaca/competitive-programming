#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// accepted
string decBin(long long n) {
	string str;

	while(n > 0) {
		str.push_back(n % 2 + '0');
		n /= 2;
	}

	size_t tam = str.size();
	for(size_t i = 0; i < tam / 2; i++)
		swap(str[i], str[tam - i - 1]);

	return str;
}

int main() {
	int t;

	cin >> t;
	for(int k = 1; k <= t; k++) {
		string str, str2;
		cin >> str >> str2;

		cout << "Case " << k << ":\n";
		if(str2 == "bin") {
			long long n = stoll(str, nullptr, 2);
			cout << n << " dec\n";
			cout << hex << n << dec << " hex\n";
		} else if(str2 == "dec") {
			long long n = stoll(str, nullptr, 10);
			cout << hex << n << dec <<" hex\n";
			cout << decBin(n) << " bin\n";
		} else if(str2 == "hex") {
			long long n = stoll(str, nullptr, 16);
			cout << n << " dec\n";
			cout << decBin(n) << " bin\n";
		}

		cout << "\n";
	}

	return 0;
}
