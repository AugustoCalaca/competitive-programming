#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 998244353
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, m;
  string r, s;
  cin >> n >> m >> r >> s;

  if(n < m) {
    r = string(m - n, '0') + r;
    n = m;
  } else {
    s = string(n - m, '0') + s;
    m = n;
  }

  int pot = 0;
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '1') pot++;
    ans = ans * 2 % M;
    if(r[i] == '1')
      ans = (ans % M + pot % M) % M;
  }

  cout << ans << "\n";
  return 0;
}
