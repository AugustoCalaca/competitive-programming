#include <iostream>

using namespace std;
typedef long long ll;

// ac
ll fexp(ll a, ll b, ll m) {
  ll ans = 1;
  for(; b; b >>= 1) {
    if(b & 1) ans = (ans % m * a % m) % m;
    a = (a % m * a % m) % m;
  }

  return ans;
}

int main() {
  ll n, k, q, pos, al, id, ans;
  cin >> n >> k >> q;

  ll inv = fexp(k, n - 2, n);
  for(int i = 0; i < q; i++) {
    cin >> al >> id;
    ans = 0;
    pos = ((id % n + k % n) % n * inv % n) % n;
    if(pos == 0) pos = n;
    ans = al / n;
    if(al % n >= pos) ans++;
    cout << ans << "\n";
  }

  return 0;
}
