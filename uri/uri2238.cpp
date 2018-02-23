#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// accepted
int main(){
	int d, noD, mult, noMult;
	vector<int> divisors;

	cin >> d >> noD >> mult >> noMult;

	int sr = sqrt(mult);
	for(int i = 1; i <= sr; i++)
		if(mult % i == 0){
			divisors.push_back(i);
			divisors.push_back(mult / i);
		}

	sort(divisors.begin(), divisors.end());

	for(auto it = divisors.begin(); it != divisors.end(); it++){
		if(*it % d == 0 && *it % noD != 0 && mult % *it == 0 && noMult % *it != 0){
			cout << *it << "\n";
			return 0;
		}
	}

	cout << "-1\n";

	return 0;
}
