#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <stack>

#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

// ac
ll v[200100];
ll ans[200100];

void lisconsecutive(ll n) {
  map<ll, ll> hash;
  ll len = 0;
  ll index = 0;

  for(int i = 0; i < n; i++) {
    cin >> v[i];
    hash[v[i]] = hash[v[i] - 1] + 1;
    if(hash[v[i]] > len) {
      len = hash[v[i]];
      index = i;
    }
  }

  cout << len << "\n";

  if(len == 1) {
    cout << "1\n";
    return ;
  }

  ll j = 1;
  ans[j - 1] = index;
  ll cor = v[index] - 1;
  for(ll i = index - 1; i >= 0; i--) {
    if(v[i] == cor) {
      ans[j++] = i;
      cor--;
    }
  }

  for(ll k = j - 1; k >= 0; k--) cout << ans[k] + 1 << " ";
  cout << "\n";
}

int main() {
  fast();
  ll n;

  cin >> n;
  lisconsecutive(n);

  return 0;
}
