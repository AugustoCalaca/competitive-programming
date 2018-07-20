#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <set>

#define sq(v) (v) * (v)
#define LIM (ll)floor(sqrt((1LL << 33) - 1))
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll ans1, ans2;

unordered_map<ll, int> st; // squares
vector<ll> primes;
ll marked[LIM + 10];

void sieve() {
  fill(marked, marked + LIM, true);
  for(ll i = 2; i * i <= LIM; i++)
    if(marked[i])
      for(ll j = i * i; j <= LIM; j += i)
        marked[j] = false;

  st[0] = 1;
  for(ll i = 2; i <= LIM; i++) {
    st[sq(i - 1)] = 1;
    if(marked[i])
      primes.pb(i);
  }
}

bool sumsquare(ll n) {
  ll m = n;
  for(ll i = 0, j = 0; primes[i] * primes[i] <= n && j * j <= m; i++, j++) {
    int c = 0;

    for(; n % primes[i] == 0; n /= primes[i], c++);
    if(primes[i] % 4 == 3 && c & 1) return false;

    ll sqr = m - j * j;
    if(st[sqr] != 0) {
      ans1 = j;
      ans2 = floor(sqrt(sqr));
      return true;
    }
  }

  return (n % 4 == 3) ? false : true;
}

int main() {
  FAST;

  sieve();
  ll n, p, q, k = 1;

  cin >> n;
  while(n--) {
    cin >> p >> q;
    cout << "Case " << k++ << ":\n";
    if(sumsquare(abs(p) + abs(q)))
      cout << ans1 << " " << ans2 << "\n";
    else
      cout << "Impossible.\n";
  }

  return 0;
}
