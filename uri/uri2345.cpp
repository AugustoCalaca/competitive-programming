#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define pb push_back
using namespace std;

// accepted
int main(){
	int a, b, c, d;
	vector<int> s;

	cin >> a >> b >> c >> d;
	s.pb(abs((c + d) - (a + b)));
	s.pb(abs((b + d) - (a + c)));
	s.pb(abs((a + d) - (b + c)));

	cout << *min_element(s.begin(), s.end()) << endl;

	return 0;
}
