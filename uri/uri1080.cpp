#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// accepted
int main(){
	int random;
	vector<int> v;

	while(cin >> random)
		v.push_back(random);

	cout << *max_element(v.begin(), v.end()) << "\n";
	cout << distance(v.begin(), max_element(v.begin(), v.end())) + 1 << "\n";

	return 0;
}
