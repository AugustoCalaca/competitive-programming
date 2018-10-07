#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 1115
#define C 110100
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

vector<int> psy;
bool ispsy(int n) {
  int even = 0, odd = 0;
  for(int i = 0; primes[i] * primes[i] <= n; i++) {
    int c = 0;
    for(; n % primes[i] == 0; n /= primes[i], c++) { }
    if(c > 0) {
      if(c & 1) odd++;
      else      even++;
    }
  }
  if(n > 1) odd++;
  return even > odd ? true : false;
}

int main() {
  FAST;

  sieve();
  for(int i = 4; i < MAX; i++)
    if(ispsy(i))
      psy.pb(i);

  int t, n, v, k, sum;
  cin >> t;
  while(t--) {
    vector<int> vec;
    sum = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
      cin >> v;
      if(binary_search(psy.begin(), psy.end(), v))
        vec.pb(v), sum += v;
    }
    if(k > sum) {
      cout << "No\n";
      continue;
    }

    bool sub[C];
    for(int i = 0; i <= sum; i++)
      sub[i] = false;
    sub[0] = true;
    for(int i = 0; i < (int)vec.size(); i++)
      for(int j = sum; j >= vec[i]; j--)
        sub[j] |= sub[j - vec[i]];

    if(sub[k])
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}
