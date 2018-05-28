#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define M (int)1e6 + 10
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

int primes[M];
bool p[M];

void sieve() {
  fill(p, p + M, true);
  for(int i = 2; i * i <= M; i++)
    if(p[i])
      for(int j = i * i; j <= M; j += i)
        p[j] = false;

  int j = 0;
  for(int i = 2; i <= M; i++)
    if(p[i]) {
      primes[j] = i;
      j++;
    }
}

int main() {
  fast();
  sieve();

  int n, k, d, f, c;
  cin >> n >> k;

  for(int i = 2; i < n; i++) {
    d = 1;
    f = i;
    for(int j = 0; primes[j] * primes[j] <= f; j++) {
      c = 0;
      while(f % primes[j] == 0) {
        f /= primes[j];
        c++;
      }

      d *= (c + 1);
    }

    if(f > 1) d *= 2;

    if(d == k) cout << i << " ";
  }

  cout << "\n";
  return 0;
}
