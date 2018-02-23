#include <iostream>
#include <cmath>
#include <set>

#define DENOM 2

using namespace std;
typedef unsigned long long ull;

int main(){

	ull num, radix, d = DENOM;
	set<ull> st;

	cin >> num;

	sr = sqrt(num);
	while(num > 1 && d <= sr){
		if(num % d == 0){
			st.insert(d);
			num /= d;
		} else
			d++;
	}

	if(num > 1)
		st.insert(num);

	cout << pow(2, st.size()) - st.size() - 1 << endl;

	return 0;
}
