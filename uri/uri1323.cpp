#include <iostream>
#include <cmath>

using namespace std;

// accepted
int main(){
	unsigned int n, quad = 0;

	while(cin >> n && n != 0){
		while(n){
			quad += pow(n, 2);
			n--;
		}
		cout << quad << "\n";
		quad = 0;
	}

	return 0;
}
