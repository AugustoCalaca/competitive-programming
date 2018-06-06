#include <iostream>

using namespace std;
typedef unsigned long long ll;
// algorithm for computer n! % p, if p is prime

ll fastExp(ll b, ll e, ll p) {
  ll ans = 1;
  for(; e; e >>= 1) {
    if(e & 1) ans = ((ans % p) * (b % p)) % p;
    b = ((b % p) * (b % p)) % p;
  }

  return ans;
}

// O((n - p) * log n)
ll modFact(ll n, ll p) {
  if(n >= p) return 0;
  ll ans = p - 1;
  for(ll i = n + 1; i < p; i++)
    ans = ((ans % p) * (fastExp(i, p - 2, p) % p) % p);

  return ans;
}
