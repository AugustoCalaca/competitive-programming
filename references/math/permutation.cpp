#include <iostream>
#include <algorithm>

using namespace std;

void permutation(int vector[], int bottom, int higher) {
	if(bottom + 1 == higher) {
		for(int i = 0; i < higher; i++)
			cout << " " << vector[i];
		cout << endl;
	}
	else {
		for(int i = bottom; i < higher; i++) {
			swap(vector[bottom], vector[i]);
			permutation(vector, bottom + 1, higher);
			swap(vector[bottom], vector[i]);
		}
	}
}



int main() {
	int sz;
	cin >> sz;
	int vector[sz];

	for(int i = 0; i < sz; i++)
		vector[i]= i + 1;

	permutation(vector, 0, sz);

	return 0;
}
