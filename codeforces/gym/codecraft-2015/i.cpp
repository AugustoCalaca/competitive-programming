#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int t, n, dp[2][100010];
  string s;
  cin >> t;
  while(t--) {
    cin >> s;
    n = s.size();

    dp[0][0] = dp[1][0] = 0;
    for(int i = 1; i <= n; i++) {
      dp[0][i] = dp[0][i - 1];
      dp[1][i] = dp[1][i - 1];

      if(s[i - 1] == 'L')
        dp[0][i] = dp[0][i - 1] + 1;
      else if(s[i - 1] == 'O')
        dp[1][i] = dp[1][i - 1] + 1;
    }

    int tmp = 0;
    ll ans = 0;

    for(int i = 0; i <= n; tmp = dp[1][i]) {
      for(; tmp == dp[1][i]; i++);
      ans += (dp[0][n] - dp[0][i]) * dp[0][i];
    }

    cout << ans << "\n";
  }
  return 0;
}
