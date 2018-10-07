#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e6 + 10;
vector<int> primes;
vector<bool> marked(MAX, true);

void sieve() {
  for(int i = 2; i * i <= MAX; i++)
    for(int j = i * i; j <= MAX; j += i)
      if(marked[j])
        marked[j] = false;

  for(int i = 2; i <= MAX; i++)
    if(marked[i])
      primes.pb(i);
}

int gcd(int a, int b) {
  while(b) {
    a %= b;
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return a;
}

ll ndiv(int n) {
  ll rep = 1;
  for(int i = 0; primes[i] * primes[i] <= n; i++) {
    int c = 0;
    for(; n % primes[i] == 0; n /= primes[i])
      c++;
    rep *= (c + 1);
  }

  if(n > 1) rep *= 2;
  return rep;
}

int main() {
  FAST;

  sieve();

  int t, a, b, g;
  cin >> t;
  while(t--) {
    cin >> a >> b;
    g = gcd(a, b);
    cout << ndiv(g) << "\n";
  }

  return 0;
}
