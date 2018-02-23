#include <iostream>

using namespace std;
typedef long long int ll;

// accepted
// x*a = 1 (mod b)
ll extEuclides(ll a, ll b) {
  ll q, b0 = b;
  ll x = 1, y = 0;

  while(b > 0) {
    q = a / b;
    x = x - y * q;
    x ^= y;
    y ^= x;
    x ^= y;

    a %= b;
    a ^= b;
    b ^= a;
    a ^= b;
  }

  if(x < 0) x += b0;

  return x;
}

ll modInv(ll e, ll tot) {
  return (extEuclides(e, tot) % tot + tot) % tot;
}

ll fastExp(ll base, ll exp, ll modn) {
  ll ans = 1;

  for(; exp > 0; exp >>= 1) {
    if(exp & 1) ans = (ans * base) % modn;
    base = (base * base) % modn;
  }

  return ans;
}

int main() {
  ll n, e, c, d, p, q, totient;

  cin >> n >> e >> c;

  for(p = 3; ; p += 2)
    if((n % p) == 0) break;

  q = n / p;
  totient = (--p) * (--q);
  d = modInv(e, totient);
  cout << fastExp(c, d, n) << endl;

  return 0;
}
