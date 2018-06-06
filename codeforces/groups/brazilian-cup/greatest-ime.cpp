#include <iostream>

#define M 1000000007
using namespace std;
typedef long long ll;

ll fastexp(ll b, ll e) {
  ll ans = 1;
  for(; e; e >>= 1) {
    if(e & 1) ans = (ans % M * b % M) % M;
    b = (b % M * b % M) % M;
  }

  return ans;
}

int main() {
  int n, c;
  ll f;
  cin >> n >> c;

  f = c - (2 * n);
  if(f > c - (3 * n)) {
    for(int i = f - 1; i > c - (3 * n); i--)
      f = (f % M * i % M) % M;
  } else f = 1;
  cout << (f * fastexp(6, n)) % M << "\n";
  return 0;
}