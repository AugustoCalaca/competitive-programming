#include <iostream>
#include <vector>

#define MAX 1000000010
#define pb push_back
using namespace std;
typedef unsigned long long ll;

// falta terminar, ta bugado
vector<ll> balls;

void solve() {
  balls.pb(0);
  for(ll j = 1; j < MAX; j++) {
    ll cont = 0;
    for(ll i = 1; i * i <= j; i++){
      if(j % i == 0) {
        if(j / i == i) cont++;
        else cont += 2;
      }
    }
    ll ans = !(cont & 1) ? balls[j - 1] + 1: balls[j - 1];
    balls.pb(ans);
  }
}

ll query(ll n) {
  return balls[n];
}

int main() {
  ll t, n;

  cin >> t;
  solve();

  for(ll i = 1; i < MAX; i++) cout << " " << balls[i];
  cout << "\n";

  cout << "SZ: " << balls.size() << "\n";
  while(t--) {
    cin >> n;
    // cout << query(n) << "\n";
  }

  return 0;
}