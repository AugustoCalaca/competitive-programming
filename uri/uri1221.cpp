#include <iostream>
#include <cmath>

using namespace std;

// accepted
int main(){

	int t, sr, i;
	unsigned int num;

	for(cin >> t; t--;){
		cin >> num;

		sr = sqrt(num);
		for(i = 2; i <= sr; i++)
			if(!(num % i))
				break;
		if(i > sr) cout << "Prime\n";
		else cout << "Not Prime\n";
	}

	return 0;
}
