#include <iostream>
#include <algorithm>
#include <cmath>

#define M 1000010
using namespace std;

typedef long long ll;

// ac
const ll l = (ll)ceil(sqrt(M)) + 10;
ll sum[M];
ll primes[l];
bool p[l];

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(NULL);
}

void sieve() {
  fill(p, p + l, true);

  for(ll i = 2; i * i <= l; i++)
    if(p[i])
      for(ll j = i * i; j <= l; j += i)
        p[j] = false;

  int j = 0;
  for(ll i = 2; i <= l; i++)
    if(p[i]) {
      primes[j] = i;
      j++;
    }
}

ll divSum(ll n) {
  ll a = 1;
  ll i = 0;
  for(; primes[i] * primes[i] <= n; i++) {
    int c = 0;
    while(n % primes[i] == 0) {
      c++;
      n /= primes[i];
    }

    if(c)
      a *= ((ll)pow(primes[i], c + 1) - 1) / (primes[i] - 1);
  }

  if(n > 1)
    a *= (n + 1);

  return a;
}

void solve() {
  sum[0] = 0;;
  sum[1] = 1;
  ll i = 2;
  for(; i <= M; i++)
    sum[i] = sum[i - 1] + divSum(i);
}

int main() {
  fast();
  sieve();
  solve();

  ll n;
  while(true) {
    cin >> n;
    if(n == 0) break;

    cout << sum[n] << "\n";
  }

  return 0;
}
