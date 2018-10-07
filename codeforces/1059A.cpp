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

  int n, l, a, t = 0, r = 0, last = 0, ans = 0;
  cin >> n >> l >> a;
  for(int i = 0; i < n; i++) {
    cin >> t >> r;
    ans += (t - last) / a;
    last = t + r;
  }
  ans += (l - last) / a;
  cout << ans << "\n";
  return 0;
}
