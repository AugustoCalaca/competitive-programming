#include <iostream>
#include <climits>

using namespace std;

int min(int a, int b) {
  return a < b ? a : b;
}

int coinChange(int coin[], int n, int total) {
  int dp[total + 1];

  for(int i = 1; i <= total; i++)
    dp[i] = INT_MAX - 10;
  dp[0] = 0;

  for(int i = 0; i < n; i++)
    for(int j = coin[i]; j <= total; j++)
      dp[j] = min(dp[j], dp[j - coin[i]] + 1);

  return dp[total];
}

// obs: store index of coin in a array aux for find values the coins
// starts at the end and jump for position (total - coin[aux[j]]) until aux[j] = -1