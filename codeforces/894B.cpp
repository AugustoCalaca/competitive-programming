#include <iostream>

using namespace std;

// accepted
typedef long long ll;
const ll M = (ll)1e9 + 7;

ll fastExp(ll b, ull e) {
  ll ans = 1;
  for(; e; e >>= 1) {
    if(e & 1) ans = (ans * b) % M;
    b = (b * b) % M;
  }

  return ans;
}

int main() {
  ll n, m;
  int k;

  cin >> n >> m >> k;

  if(k == -1 && ((n & 1) != (m & 1))) {
    cout << "0\n";
    return 0;
  }

  ll ans = 1;
  if(n > 1 && m > 1)
    ans = fastExp(fastExp(2, n - 1), m - 1);

  cout << ans << "\n";
  return 0;
}
