#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int val[2010], item[2010], dp[2010][2010];

int main() {
  FAST;
  int s, n;
  cin >> s >> n;
  for(int i = 0; i < n; i++)
    cin >> item[i] >> val[i];

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= s; j++) {
      if(item[i - 1] <= j) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i - 1]] + val[i - 1]);
      }
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  cout << dp[n][s] << "\n";
  return 0;
}
