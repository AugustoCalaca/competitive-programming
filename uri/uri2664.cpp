#include <iostream>

#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

// accepted
ull dp[100][100100];

ull steppingNumber(ull numExer, ull k) {
	if(numExer == 1)
		return k + 1;

	for(ull j = 0; j <= k; j++)
		dp[1][j] = 1;

	for(ull i = 2; i <= numExer; i++) {
		for(ull j = 0; j <= k; j++) {
			if(j == 0)
				dp[i][j] = dp[i - 1][j + 1] % MOD;
			else if(j == k)
				dp[i][j] = dp[i - 1][j - 1] % MOD;
			else
				dp[i][j] = ((dp[i - 1][j - 1] % MOD) + (dp[i - 1][j + 1] % MOD)) % MOD;
		}
	}

	ull sum = 0;
	for(ull j = 0; j <= k; j++)
		sum = ((sum % MOD) + (dp[numExer][j] % MOD)) % MOD;

	return sum;
}

int main() {
	ull numExer, beg, end;

	cin >> numExer >> beg >> end;
	cout << steppingNumber(numExer, end - beg) << endl;

	return 0;
}
