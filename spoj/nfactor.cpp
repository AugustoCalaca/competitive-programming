#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 1000010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> primes;
vector<bool> marked(MAX, true);
vector<vector<int> > dp(12);

void func() {
  dp[0].resize(MAX, 1);
  for(int i = 1; i <= 10; i++)
    dp[i].resize(MAX);
  for(int i = 1; i <= 10; i++)
    dp[i][0] = 0, dp[i][1] = 0;
  dp[0][0] = 0;
}

void update(int i, int j) {
  for(int k = 1; k <= 10; k++)
    if(k == j)
      dp[k][i] = dp[k][i - 1] + 1;
    else
      dp[k][i] = dp[k][i - 1];
}

int fact(int n) {
  int ans = 0;
  bool c;
  for(int i = 0; primes[i] * primes[i] <= n; i++) {
    c = false;
    for(; n % primes[i] == 0; n /= primes[i], c = true);
    if(c) ans++;
  }
  if(n > 1) ans++;

  return ans;
}

void sieve() {
  for(int i = 2; i * i < MAX; i++)
    for(int j = i * i; j < MAX; j += i)
      if(marked[j])
        marked[j] = false;


  for(int i = 2; i < MAX; i++) {
    if(marked[i]) {
      primes.pb(i);
      update(i, 1);
    }
    else
      update(i, fact(i));
  }
}


int main() {
  FAST;

  func();
  sieve();

  int t, a, b, n;

  for(cin >> t; t--; ) {
    cin >> a >> b >> n;

    int ans = dp[n][b] - dp[n][a - 1];
    cout << ans << "\n";
  }

  return 0;
}
