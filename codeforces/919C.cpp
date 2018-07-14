#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string str[2010];

int main() {
  FAST;
  int n, m, k, r = 0, ans = 0, v1, v2;
  cin >> n >> m >> k;

  char ch;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> ch;
      str[i].pb(ch);
    }
  }

  for(int i = 0; i < n; i++) {
    v1 = 0;
    for(int j = 0; j < m; j++) {
      if(str[i][j] == '.') v1++, r++;
      else { if(v1 >= k) ans += v1 - k + 1; v1 = 0; }
    }
    if(v1 >= k) ans += v1 - k + 1;
  }

  if(k == 1) { cout << r << "\n"; return 0; }

  for(int j = 0; j < m; j++) {
    v2 = 0;
    for(int i = 0; i < n; i++) {
      if(str[i][j] == '.') v2++;
      else { if(v2 >= k) ans += v2 - k + 1; v2 = 0; }
    }
    if(v2 >= k) ans += v2 - k + 1;
  }

  cout << ans << "\n";

  return 0;
}
