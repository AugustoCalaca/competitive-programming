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

ll fexp(ll b, ll e) {
  ll ans = 1;
  for(; e; e >>= 1) {
    if(e & 1) ans *= b;
    b *= b;
  }
  return ans;
}

int main() {
  FAST;

  int n;
  cin >> n;
  cout << 6ll * fexp(4, n - 2) + 9 * (n - 3) * fexp(4, n - 3) << "\n";
  return 0;
}
