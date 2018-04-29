#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define M int(1e6 + 10)
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// ac
void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

bool p[M];
int primes[M];
int twin[M];

int sieve() {
  fill(p, p + M, true);

  for(int i = 2; i * i <= M; i++)
    if(p[i])
      for(int j = i * i; j <= M; j += i)
        p[j] = false;

  twin[0] = primes[0] = 3;
  primes[1] = 5;
  int j = 2, k = 1;
  for(int i = 7; i <= M; i++)
    if(p[i]) {
      primes[j] = i;
      if(primes[j] - primes[j - 1] == 2) {
        twin[k++] = primes[j - 1];
        twin[k++] = primes[j];
      }

      j++;
    }

  return k;
}

int main() {
  fast();
  int k = sieve();

  int q, a, b;

  for(cin >> q; q--; ) {
    cin >> a >> b;
    if(a > b) swap(a, b);

    auto l = lower_bound(twin, twin + k, a);
    auto u = upper_bound(twin, twin + k, b);
    cout << (u - twin) - (l - twin) << "\n";
  }

  return 0;
}
