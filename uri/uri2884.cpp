#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 1010
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int dp[M][M];
vector<int> input[M];

int solve(int n, int m) {
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < m; j++)
      dp[j][i] = dp[j][i - 1];

    for(auto& j : input[i])
      dp[j][i] ^= 1;

    bool flag = true;
    for(int j = 0; j < m; j++)
      if(dp[j][i] == 1) {
        flag = false;
        break;
      }


    if(flag) return i;
  }

  for(int j = 0; j < m; j++)
    dp[j][0] = dp[j][n];

  return -1;
}

int main() {
  FAST;

  int n, m, l, k;
  cin >> n >> m >> l;
  while(l--) {
    cin >> k;
    dp[k - 1][0] = 1;
  }

  for(int i = 1; i <= n; i++) {
    cin >> l;
    for(int j = 0; j < l; j++) {
      cin >> k;
      input[i].pb(k - 1);
    }
  }

  int ans = solve(n, m);
  if(ans != -1) cout << ans << "\n";
  else {
    ans = solve(n, m);
    if(ans != -1) cout << ans + n << "\n";
    else          cout << ans << "\n";
  }
  return 0;
}
