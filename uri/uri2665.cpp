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

pii ancA;
pii ancB;
vector<pii> v;
vector<int> dp(110, 1);

bool comp(const pii a, const pii b) {
  return a.s < b.s;
}

int orientation(pii p, pii q, pii r) {
  int clock = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
  return clock > 0 ? 1 : 2;
}

bool intercept(pii p, pii q) {
  int or1 = orientation(ancA, p, q);
  int or2 = orientation(ancA, p, ancB);
  int or3 = orientation(ancB, q, ancA);
  int or4 = orientation(ancB, q, p);

  int or5 = orientation(ancA, q, p);
  int or6 = orientation(ancA, q, ancB);
  int or7 = orientation(ancB, p, ancA);
  int or8 = orientation(ancB, p, q);

  if((or1 != or2 && or3 != or4) || (or5 != or6 && or7 != or8)) return true;
  else return false;
}

int main() {
  fast();
  int n, a, b, x, y;

  cin >> n >> a >> b;
  ancA = { a, 0 };
  ancB = { b, 0 };
  for(int i = 0; i < n; i++) {
    cin >> x >> y;
    v.pb({ x, y });
  }

  sort(v.begin(), v.end(), comp);

  int ans = 0;
  for(int i = 1; i < n; i++) {
    for(int j = i - 1; j >= 0; j--)
      if(!intercept(v[i], v[j]))
        dp[i] = max(dp[i], dp[j] + 1);
    ans = max(dp[i], ans);
  }
  cout << ans << "\n";
  return 0;
}
