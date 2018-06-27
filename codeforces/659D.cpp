#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define f first
#define s second
#define pii pair<int, int>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int orientation(pii& p, pii& q, pii& r) {
  int clock = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
  return clock < 0 ? true : false;
}

int main() {
  fast();

  int n, x, y, ans = 0;
  vector<pii> v;
  cin >> n;
  for(int i = 0; i <= n; i++) {
    cin >> x >> y;
    v.pb({ x, y });
  }

  for(int i = 2; i <= n; i++) {
    if(orientation(v[i - 2], v[i - 1], v[i])) ans++;
  }

  cout << ans << "\n";
  return 0;
}
