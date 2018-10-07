#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 100000010
#define LIM 10010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> sum;
vector<int> primes;
vector<bool> marked(LIM, true);

void sieve() {
  for(int i = 2; i * i < LIM; i++)
    for(int j = i * i; j < LIM; j += i)
      if(marked[j])
        marked[j] = false;

  sum.pb(0);
  sum.pb(1);
  for(int i = 2; i < MAX; i++) {
    if(i < LIM) if(marked[i])
      primes.pb(i);
    if(sum.back() < MAX)
      sum.pb(i + sum[i - 1]);
  }
}

void segsieve() {
  sieve();
  int low = LIM;
  int high = 2 * LIM;
  int sz = primes.size();

  while(low < MAX) {
    if(high >= MAX) high = MAX;

    vector<bool> mark(LIM, true);
    for(int i = 0; i < sz; i++) {
      int loLIM = floor(low / primes[i]) * primes[i];
      if(loLIM < low) loLIM += primes[i];
      for(int j = loLIM; j < high; j += primes[i])
        mark[j - low] = false;
    }

    for(int i = low; i < high; i++)
      if(mark[i - low])
        primes.pb(i);

    low += LIM;
    high += LIM;
  }
}

int main() {
  FAST;

  segsieve();

  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    int idx = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
    if(primes[idx] != n) {
      cout << "-1\n";
      continue;
    }

    int it = lower_bound(sum.begin(), sum.end(), idx) - sum.begin();
    if(sum[it] != idx) it--;
    cout << (idx + sum[it]) / (it + 1) + 1 << " "
         << (idx + sum[it]) % (it + 1) + 1 << "\n";
  }

  return 0;
}
