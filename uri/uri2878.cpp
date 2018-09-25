#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 1000100
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

vector<pii> v1, v2;
ll bit[MAX];

void update(int idx, int val, int n) {
  for(; idx <= n; idx += idx & (-idx))
    bit[idx] += val;
}

ll query(int idx) {
  ll sum = 0;
  for(; idx > 0; idx -= idx & (-idx))
    sum += bit[idx];

  return sum;
}

ll invcount(vector<pii>& v, int n) {
  ll inv = 0;
  int temp[MAX];

  for(int i = 0; i < n; i++)
    temp[i] = v[i].s, bit[i + 1] = 0;

  sort(temp, temp + n);
  for(int i = 0; i < n; i++)
    v[i].s = (lower_bound(temp, temp + n, v[i].s) - temp) + 1;

  for(int i = n - 1; i >= 0; i--) {
    inv += query(v[i].s - 1);
    update(v[i].s, 1, n);
  }

  return inv;
}

int main() {
  FAST;

  int x, y, h, v, a, b;

  cin >> x >> y >> h >> v;

  for(int i = 0; i < h; i++) {
    cin >> a >> b;
    v1.pb({ a, b });
  }

  for(int i = 0; i < v; i++) {
    cin >> a >> b;
    v2.pb({ a, b });
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  ll ans = (h + 1ll) * (v + 1);
  ans += invcount(v1, h);
  ans += invcount(v2, v);

  cout << ans << "\n";
  return 0;
}
