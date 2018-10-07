#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 100010
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int a[M], b[M], c[M];
ll memo[3][M];

int main() {
  FAST;

  int t, p, q, r;
  cin >> t;
  while(t--) {
    cin >> p;
    for(int i = 0; i < p; i++) cin >> a[i];
    cin >> q;
    for(int j = 0; j < q; j++) cin >> b[j];
    cin >> r;
    for(int k = 0; k < r; k++) cin >> c[k];

    for(int i = 0; i < p; i++) {
      if(i >= q)
        memo[0][i] = q;
      else
        memo[0][i] = (lower_bound(b + i, b + q, a[i]) - b);
    }

    for(int j = 0; j < q; j++) {
      if(j >= r)
        memo[1][j] = 0, memo[2][j] = 0;
      else
        memo[1][j] = r - (lower_bound(c + j, c + r, b[j]) - c);
    }

    int l = q < r ? q : r;
    memo[2][l] = 0;
    for(int j = l - 1; j >= 0; j--)
      memo[2][j] = memo[2][j + 1] + memo[1][j];

    ll ans = 0;
    for(int i = 0; i < p; i++)
      ans += memo[2][memo[0][i]];

    cout << ans << "\n";
  }
  return 0;
}
