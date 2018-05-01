#include <iostream>

using namespace std;

bool subsetSum(int set[], int sz, int sum) {
	bool subset[sz + 1][sum + 1];

	for(int i = 0; i <= sz; i++)
		subset[i][0] = true;
	for(int j = 1; j <= sum; j++)
		subset[0][j] = false;

	for(int i = 1; i <= sz; i++) {
		for(int j = 1; j <= sum; j++) {
			if(j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if(j >= set[i - 1])
				subset[i][j] = subset[i - 1][j] ||
											 subset[i - 1][j - set[i - 1]];
		}
	}

	return subset[sz][sum];
}

int main() {
	int set [] = { 2, 3, 7, 8, 10 };
	int sz = sizeof(set) / sizeof(int);
	int sum = 0;

	for(int i = 0; i < sz; i++)
		sum += set[i];

	subsetSum(set, sz, sum);

	return 0;
}


