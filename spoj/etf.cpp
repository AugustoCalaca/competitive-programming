#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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
        marked[j] =  false;

  for(int i = 2; i <= MAX; i++)
    if(marked[i])
      primes.pb(i);
}

int tot(int n) {
  int ans = n;
  for(int i = 0; primes[i] * primes[i] <= n; i++) {
    if(n % primes[i] == 0) {
      for(; n % primes[i] == 0; n /= primes[i]) {}
      ans -= ans / primes[i];
    }
  }

  if(n > 1) ans -= ans / n;
  return ans;
}

int main() {
  FAST;

  sieve();
  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    cout << tot(n) << "\n";
  }

  return 0;
}
