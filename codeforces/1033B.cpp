#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 1000000
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> primes;
vector<int> marked(M, true);

void sieve() {
  for(ll i = 2; i * i < M; i++)
    for(ll j = i * i; j < M; j += i)
      if(marked[j])
        marked[j] = false;

  for(int i = 2; i < M; i++)
    if(marked[i])
      primes.pb(i);
}

bool isprime(ll ans) {
  for(int i = 0; 1ll * primes[i] * primes[i] <= ans; i++)
      if(ans % primes[i] == 0)
        return false;
  return true;
}

int main() {
  FAST;

  sieve();

  int t;
  ll a, b;
  for(cin >> t; t--; ) {
    cin >> a >> b;

    if(a - b == 1 && isprime(a + b)) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
