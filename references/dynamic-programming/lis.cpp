#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define f first
#define s second
#define pb push_back
using namespace std;

// lis in n^2
int lis(vector<int>& v) {
	int sz = v.size();
	vector<int> dp(sz + 5, 1);

	for(int i = 1; i < sz; i++)
		for(int j = 0; j < i; j++)
			if(v[j] < v[i])
				dp[i] = max(dp[i], dp[j] + 1);

	return *max_element(dp.begin(), dp.end());
}

// lis in nlogn
int lis2(vector<int>& v, int n) {
	vector<int>  temp;
	temp.pb(v[0]); // array increasing, first index, second value

	for(int i = 1; i < n; i++) {
		if(v[i] < temp[0])
			temp[0] = v[i];
		else if(v[i] > temp.back())
			temp.pb(v[i]);
		else {
			int pos = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
			temp[pos] = v[i];
		}
	}

	// the elements in vector no necessarily represent the elements of lis
	// but your size is equal of lis
	return temp.size();
}

int main() {
	vector<int> v = { 3, 4, -1, 5, 8, 11, 12, 7, 9, 10 };
	int n = v.size();
	cout << "Lis: " << lis2(v, n) << endl;

	return 0;
}
