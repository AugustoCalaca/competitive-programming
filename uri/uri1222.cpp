#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, l, c, sz, cfl, lfp, ans;
  string str;

  while(cin >> n >> l >> c) {
    ans = cfl = 0;
    lfp = 1;
    for(int i = 0; i < n; i++) {
      cin >> str;
      sz = str.size();
      if(cfl + sz <= c) cfl += sz + 1;
      else {
        lfp++;
        cfl = sz + 1;
      }
      if(lfp == l) lfp = 0, ans++;
    }
    if(lfp > 0) ans++;
    cout << ans << "\n";
  }

  return 0;
}
