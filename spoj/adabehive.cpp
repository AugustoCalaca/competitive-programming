#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 100010
#define MAX2 2010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int bit[MAX2][MAX2];
int in[MAX2][MAX2];

void update(int l, int r, int n, int m, int val) {
  for(; l <= n; l += l & -l)
    for(; r <= m; r += r & -r)
      bit[l][r] += val;
}

ll query(int l, int r) {
  ll sum = 0;
    for(int j = r; j > 0; j -= j & -j)
      sum += bit[l][j];

  return sum;
}

int main() {
  FAST;

  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 0; i < n; i++) {
    int j = 0;
    for(; j < m; j++) {
      cin >> in[i][j];
      update(i + 1, j + 1, n, m, in[i][j]);
    }
  }

  int k, l, r, v, l1, l2, r1, r2;
  while(q--) {
    cin >> k;
    if(k == 1) {
      cin >> l >> r >> v;
      update(l, r, n, m, v);
    }
    else {
      cin >> l1 >> r1 >> l2 >> r2;
      ll ans = 0;
      for(; l1 <= l2; l1++)
        ans += query(l1, r2) - query(l1, r1 - 1);
      cout << ans << "\n";
    }
  }

  return 0;
}
