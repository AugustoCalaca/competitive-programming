#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  fast();
  vector<pair<int, pair<int, int> > > v;

  int k, n, a[200100];
  cin >> k;
  for(int t = 0; t < k; t++) {
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    for(int i = 0; i < n; i++)
      v.pb({ sum - a[i], { t + 1, i + 1} });
  }

  sort(v.begin(), v.end());
  auto it2 = v.begin();
  for(auto it = it2 + 1; it != v.end(); it++, it2++) {
    if(it->f == it2->f && it->s.f != it2->s.f) {
      cout << "YES\n";
      cout << it->s.f << " " << it->s.s << "\n";
      cout << it2->s.f << " " << it2->s.s << "\n";
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}
