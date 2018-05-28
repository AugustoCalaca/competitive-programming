#include <iostream>

#define l 1e18
using namespace std;
typedef long long ll;

ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }

// ac
int main() {
  int n, m;
  ll a[60], b[60];

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  for(int i = 0; i < m; i++)
    cin >> b[i];

  ll ans = l;
  for(int i = 0; i < n; i++) {
    ll actual = -l;
    for(int j = 0; j < m; j++)
      for(int k = 0; k < n; k++) {
        if(k != i)
          actual = max(actual, a[k] * b[j]);
      }
    ans = min(ans, actual);
  }

  cout << ans << "\n";
  return 0;
}
