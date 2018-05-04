#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define M (ll)1e6 + 50
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

vector<ll> primes;

void sieveEratostenes(ll n) {
  vector<bool> marked(M, true);

  for(ll i = 2; i * i <= n; i++)
    if(marked[i])
      for(ll j = i * 2; j <= n; j += i)
        marked[j] = false;

  for(ll i = 2; i <= n; i++)
    if(marked[i])
      primes.pb(i * i);
}

int main() {
  fast();
  sieveEratostenes(M);

  int n;
  ll q;
  for(cin >> n; n--; ) {
    cin >> q;

    if(binary_search(primes.begin(), primes.end(), q)) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
