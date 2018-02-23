#include <iostream>
#include <algorithm>

using namespace std;

// accepted
int main(){

	int a, b, c;
	int v [3], sum[3];

	cin >> a >> b >> c;
	v[0] = a;
	v[1] = b;
	v[2] = c;

	sum[0] = (v[1] * 2) + (v[2] * 4);
	sum[1] = (v[0] * 4) + (v[1] * 2);
	sum[2] = (v[0] * 2) + (v[2] * 2);

	auto less = min_element(sum, sum + 3);

	cout << *less << endl;

	return 0;
}
