#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 500010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

vector<pii> v;

bool comp(pii& a, pii& b) {
  if(a.f == b.f)
    return a.s < b.s;
  return a.f < b.f;
}

int main() {
  FAST;

  int n, l, r;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l >> r;
    v.pb({ r, l });
  }

  sort(v.begin(), v.end(), comp);

  int ans = 0;
  for(int i = 0, last = 0; i < n; i++)
    if(v[i].s > last)
      ans++, last = v[i].f;

  cout << ans << "\n";
  return 0;
}
