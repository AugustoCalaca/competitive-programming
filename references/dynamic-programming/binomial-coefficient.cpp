#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solve(ll n, ll r, ll p) {
  ll dp[n + 1][r + 1];

  for(ll i = 0; i <= n; i++)
    dp[i][0] = 1;

  for(ll j = 1; j <= r; j++) {
    for(ll i = j; i <= n; i++) {
      if(j == i) dp[i][j] = 1;
      else
        dp[i][j] = (dp[i - 1][j - 1] % p + dp[i - 1][j] % p) % p;
    }
  }

  return dp[n][r];
}

// space optimal
ll solveTwo(ll n, ll r, ll p) {
  ll dp[r + 1];

  for(ll i = 1; i <= r; i++)
    dp[i] = 0;
  dp[0] = 1;

  for(ll i = 1; i <= n; i++) {
    for(ll j = min(i, r); j > 0; j--)
      dp[j] = (dp[j] % p + dp[j - 1] % p) % p;
  }

  return dp[r];
}

ll fext(ll b, ll e, ll p) {
  ll ans = 1;
  for(; e > 0; e >>= 1) {
    if(e & 1) ans = (ans * b) % p;
    b = (b * b) % p;
  }

  return ans;
}

// complexity rlog(p)
ll solveThree(ll n, ll r, ll p) {
  if(r > n - r) r = n - r;

  ll ans = 1;
  for(ll i = 0; i < r; i++) {
    ans = (ans % p * (n - i) % p) % p;
    ans = (ans % p * fext(i + 1, p - 2, p) % p) % p;
    // ans *= (n - i);
    // ans /= (i + 1);
  }

  return ans;
}

// O(p^2 * log p, n)
ll lucas(ll n, ll r, ll p) {
  if(r == 0) return 1;

  ll ni = n % p, ri = r % p;

  return (lucas(n / p, r / p, p) * solveThree(ni, ri, p) % p);
}
