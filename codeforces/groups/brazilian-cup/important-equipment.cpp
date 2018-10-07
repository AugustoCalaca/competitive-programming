#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pii pair<int, int>
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<pii> wall[3];

int orientation(const pii& p, const pii& q, const pii& r) {
  return (r.s - p.s) * (q.f - p.f) - (r.f - p.f) * (q.s - p.s);
  // if(v == 0) return 0;
  // return v > 0 ? 1 : 2;
}

bool segbound(const pii& p, const pii& q, const pii& r) {
  if(r.f <= max(p.f, q.f) && r.f >= min(p.f, q.f) &&
     r.s <= max(p.s, q.f) && r.s >= min(p.s, q.s))
    return true;
  return false;
}

bool solve(const pii& p, int n, int k) {
  int o = 0, o2 = 0;
  for(int i = 0; i + 1 < n; i++) {
    o = orientation(wall[k][i], wall[k][(i + 1)], p);
    cout << o << " o\n";
    // if(segbound(wall[k][i], wall[k][(i + 1)], p))
    //   return true;
    if(o > 0) return false;
  }

  return true;
}

int main() {
  FAST;

  int s, r, m, u, v, n;
  cin >> s;
  for(int i = 0; i < s; i++) {
    cin >> u >> v;
    wall[0].pb({ u, v });
  }

  // for(int i = 0; i < r; i++) {
  //   cin >> u >> v;
  //   wall[1].pb({ u, v });
  // }

  // for(int i = 0; i < m; i++) {
  //   cin >> u >> v;
  //   wall[2].pb({ u, v });
  // }

  for(cin >> n; n--; ) {
    cin >> u >> v;
    pii query = { u, v };
    if     (solve(query, s, 0)) cout << "Sheena\n";
    // else if(solve(query, r, 1)) cout << "Rose\n";
    // else if(solve(query, m, 2)) cout << "Maria\n";
    else                        cout << "Outside\n";
  }

  return 0;
}
