#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 1000010
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> ans;
vector<int> primes;
vector<bool> marked(MAX, true);

bool afraid(int n) {
  int p = n;
  for(int k = 1; p; p /= 10, k++)
    if(p % 10 == 0) return false;

  string pri = to_string(n);
  for(int i = 0; i + 1 < (int)pri.size(); i++) {
    pri[i] = '0';
    if(!binary_search(primes.begin(), primes.end(), stoi(pri)))
      return false;
  }

  return true;
}

void sieve() {
  for(int i = 2; i * i < MAX; i++)
    for(int j = i * i; j < MAX; j += i)
      if(marked[j])
        marked[j] = false;

  ans.pb(0);
  ans.pb(0);
  for(int i = 2; i < MAX; i++)
    if(marked[i]) {
      primes.pb(i);
      if(afraid(i))
        ans.pb(ans.back() + 1);
      else
        ans.pb(ans.back());
    }
    else
      ans.pb(ans.back());
}

int main() {
  FAST;

  sieve();

  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    cout << ans[n] << "\n";
  }
  return 0;
}
