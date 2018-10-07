#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 10000007
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
    if(e & 1) ans = (ans % M * b % M) % M;
    b = (b % M * b % M) % M;
  }

  return ans % M;
}

int main() {
  FAST;

  int n, k;
  while(true) {
    cin >> n >> k;
    if(n == 0 && k == 0) break;

    ll a = fexp(n, k);
    ll b = 2 * fexp(n - 1, k);
    ll c = 2 * fexp(n - 1, n - 1);
    ll d = fexp(n, n);
    cout << ((a + b) % M + (c + d) % M) % M << "\n";
  }
  return 0;
}
