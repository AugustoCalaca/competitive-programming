#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 998244353
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, v[1010], dp[1010][1010];
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    dp[i][0] = 1;
  }

  dp[0][0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
      if(i == j) dp[i][j] = 1;
      else dp[i][j] = (dp[i - 1][j - 1] % M + dp[i - 1][j] % M) % M;
    }
  }

  ll dp2[1010];
  dp2[n] = 1;
  for(int i = n - 2; i >= 0; i--) {
    if(v[i] > 0) {
      for(int j = v[i] + i + 1; j <= n; j++)
        dp2[i] = (dp2[i] % M + (dp2[j] % M * dp[j - i - 1][v[i]] % M) % M) % M;
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) ans = (ans % M + dp2[i] % M) % M;

  cout << ans << "\n";
  return 0;
}
