#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define ins insert
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll v[100030];

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

int main() {
  fast();

  ll n, m, k;

  cin >> n;
  ll i = 0;
  for(; i < n; i++)
    cin >> v[i];

  cin >> m;
  for(; i < n + m; i++)
    cin >> v[i];
  cin >> k;

  sort(v, v + n + m);
  for(ll z = 0; z < n + m; z++) cout << v[z] << " ";
  cout << "\n";

  ll diff;
  ll ans = 0;
  for(ll z = 1, j = 0; z < n + m; ) {
    diff = v[z] - v[j];
    if(diff <= k) {
      if(diff >= ans) ans = diff;
      z++;
    }
    else j++;
    if(z == j) z++;
    if(ans == k) break;
  }

  cout << ans << "\n";

  return 0;
}
