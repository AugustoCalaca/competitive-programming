#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll bit[M];
int v[M], temp[M];

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

  int d, n;
  for(cin >> d; d--; ) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> v[i];
      temp[i] = v[i];
    }


    sort(temp, temp + n);
    for(int i = 0; i < n; i++) {
      v[i] = lower_bound(temp, temp + n, v[i]) - temp;
      bit[i + 1] = 0;
    }

    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
      up(n, v[i] + 1, 1);
      ans += query(v[i]);
    }

    cout << ans << "\n";
  }

  return 0;
}
