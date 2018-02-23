#include <iostream>
#include <cmath>

#define C 26
#define D 10
using namespace std;

// accepted
int main(){
	unsigned int n, c, d;

	cout.precision(0);
	cout << fixed;
	for(cin >> n; n--;){
		cin >> c >> d;

		if(c == 0 && d == 0)
			cout << "0\n";
		else{
			cout << pow(C, c) * pow(D, d) << "\n";
		}
	}

	return 0;
}
