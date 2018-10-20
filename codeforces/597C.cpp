#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll bit[MAX], arr[MAX], dp[MAX][12];

void update(ll val, int idx, int n) {
  for(; idx <= n; idx += idx & -idx)
    bit[idx] += val;
}

ll query(int idx) {
  ll sum = 0;
  for(; idx > 0; idx -= idx & -idx)
    sum += bit[idx];
  return sum;
}

int main() {
  FAST;

  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    dp[i][1] = 1;
  }

  if(k == 0) return cout << n << "\n", 0;

  for(int j = 2; j <= k + 1; j++) {
    for(int i = 0; i < n; i++)
      bit[i + 1] = 0;

    for(int i = 1; i < n; i++) {
      update(dp[i - 1][j - 1], arr[i - 1] + 1, n);
      dp[i][j] = query(arr[i]);
    }
  }

  ll ans = 0;
  for(int i = 0; i < n; i++)
    ans += dp[i][k + 1];

  cout << ans << "\n";
  return 0;
}
