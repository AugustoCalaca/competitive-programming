#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 500100
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  vector<int> primes;
  vector<bool> marked(MAX, true);

  for(int i = 2; i * i <= MAX; i++)
    for(int j = i * i; j <= MAX; j += i)
      if(marked[j])
        marked[j] = false;

  for(int i = 2; i <= MAX; i++)
    if(marked[i]) primes.pb(i);

  int t, n, n2;
  cin >> t;
  while(t--) {
    cin >> n;
    n2 = n;

    ll ans = 1;
    for(int i = 0; primes[i] * primes[i] <= n; i++) {
      int c = 0;
      for(; n % primes[i] == 0; n /= primes[i])
        c++;
      if(c)
        ans *= ((ll)pow(primes[i], c + 1) - 1) / (primes[i] - 1);
    }
    if(n > 1) ans *= (ll)(pow(n, 2) - 1) / (n - 1);

    cout << ans - n2 << "\n";
  }

  return 0;
}
