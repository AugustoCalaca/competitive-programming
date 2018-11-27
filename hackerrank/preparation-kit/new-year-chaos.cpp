#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string.h>

#define M 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int bit[M];

void up(int n, int idx, int val) {
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

  int t, n, v[M];
  for(cin >> t; t--; ) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    int ans = 0;
    bool fuck = false;
    ll bribe;

    fill(bit, bit + n + 1, 0);

    for(int i = n - 1; i >= 0; i--) {
      up(n, v[i] + 1, 1);
      bribe = query(v[i]);
      if(bribe > 2) {
        fuck = true;
        break;
      }

      ans += bribe;
    }

    if(fuck) cout << "Too chaotic\n";
    else     cout << ans << "\n";
  }
  return 0;
}
