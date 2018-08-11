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

  int n, l, h, v[100100], one[100100];
  cin >> n >> l >> h;
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) cin >> one[i];

  int ans = -1e9;
  for(int i = 0; i + l < n; i++) {
    int m = 0, co = 0;
    for(int j = i; j < n; j++) {
      if(one[j] == 1) co++;
      if(co > h) break;
      m += v[j];
      if(co >= l && co <= h)
        ans = max(ans, m);
    }
  }

  cout << ans << "\n";
  return 0;
}
