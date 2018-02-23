#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lis(vector<int>& v) {
	int sz = v.size();
	vector<int> dp(sz + 5, 1);

	for(int i = 1; i < sz; i++)
		for(int j = 0; j < i; j++)
			if(v[j] < v[i])
				dp[i] = max(dp[i], dp[j] + 1);

	return *max_element(dp.begin(), dp.end());
}

int main() {
	vector<int> v = { 1, 2, 1, 2 };

	cout << "Lis: " << lis(v) << endl;

	return 0;
}
