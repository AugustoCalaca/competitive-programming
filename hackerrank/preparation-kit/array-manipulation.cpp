#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 10000100
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<ll> bit(M);

ll sum(ll a, ll b) { return a + b; }
ll mmax(ll a, ll b) { return a > b ? a : b; }

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

  int n, m, a, b, k;
  cin >> n >> m;
  while(m--) {
    cin >> a >> b >> k;
    up(n, a, k);
    up(n, b + 1, -k);
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++)
    ans = mmax(ans, query(i));

  cout << ans << "\n";
  return 0;
}
