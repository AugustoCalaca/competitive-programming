#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// complexity O(n * r)
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

// complexity O(r)
ll solveThree(ll n, ll r, ll p) {
  if(r > n - r) r = n - r;

  ll ans = 1;
  for(ll i = 0; i < r; i++) {
    ans *= (n - i);
    ans /= (i + 1);
  }

  return ans;
}

ll fexp(ll b, ll e, ll p) {
  ll ans = 1;
  for(; e > 0; e >>= 1) {
    if(e & 1) ans = (ans * b) % p;
    b = (b * b) % p;
  }

  return ans;
}

ll fermat(ll n, ll r, ll p) {
  if(r == 0) return 1;

  ll factorial[n + 1];
  factorial[0] = 1;
  for(int i = 0; i <= n; i++)
    factorial[i] = factorial[i - 1] * i % p;

  ll b1 = factorial[r];
  ll b2 = factorial[n - r];
  return (factorial[n] * fexp(b1, p - 2, p) % p * fexp(b2, p - 2, p) % p) % p;
}


// O(p^2 * log p, n)
ll lucas(ll n, ll r, ll p) {
  if(r == 0) return 1;

  ll ni = n % p, ri = r % p;

  return (lucas(n / p, r / p, p) * solveTwo(ni, ri, p) % p);
}
