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

bool orientation(pii p, pii q, pii r) {
  return (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
}

int main() {
  fast();

  int n, x, y;
  vector<pii> v;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x >> y;
    v.pb({ x, y });
  }

  int ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
      for(int k = j + 1; k < n; k++)
        if(orientation(v[i], v[j], v[k])) ans++;

  cout << ans << "\n";
  return 0;
}
