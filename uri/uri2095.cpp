#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int s, n, q[100010];
  multiset<int> noglo;
  cin >> s;
  for(int i = 0; i < s; i++) cin >> q[i];
  for(int i = 0; i < s; i++) { cin >> n; noglo.insert(n); }

  int ans = 0;
  for(int i = 0; i < s; i++) {
    auto fnd = noglo.upper_bound(q[i]);
    if(fnd != noglo.end()) {
      noglo.erase(fnd);
      ans++;
    }
  }

  cout << ans << "\n";
  return 0;
}
