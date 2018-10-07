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

ll bit[M], in[M];

void update(int n, int idx, int val) {
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

  int n, q, a, b, l, r;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> in[i];

  sort(in, in + n);

  for(int i = 0; i < n; i++)
    update(n, i + 1, in[i]);

  cin >> q;
  while(q--) {
    cin >> a >> b;

    l = lower_bound(in, in + n, a) - in;
    r = upper_bound(in, in + n, b) - in;

    cout << query(r) - query(l) << "\n";
  }
  return 0;
}
