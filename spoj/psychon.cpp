#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 10000010
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> primes;
vector<bool> marked(MAX, true);
void sieve() {
  for(int i = 2; i * i < MAX; i++)
    for(int j = i * i; j < MAX; j += i)
      if(marked[j])
        marked[j] = false;

  for(int i = 2; i < MAX; i++)
    if(marked[i])
      primes.pb(i);
}

bool solve(int n) {
  int even = 0, odd = 0;
  for(int i = 0; primes[i] * primes[i] <= n; i++) {
    int c = 0;
    for(; n % primes[i] == 0; n /= primes[i], c++) { }
    if(c > 0) {
      if(c & 1) odd++;
      else even++;
    }
  }
  if(n > 1) odd++;
  return even > odd ? true : false;
}

int main() {
  FAST;
  sieve();

  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;

    if(solve(n)) cout << "Psycho Number\n";
    else         cout << "Ordinary Number\n";
  }
  return 0;
}
