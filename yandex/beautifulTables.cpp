#include <iostream>

using namespace std;

// accepted
typedef long long ll;
const ll M = (ll)1e9 + 7;

ll fastExp(ll b, ll e) {
  ll ans = 1;
  for(; e; e >>= 1) {
    if(e & 1) ans = ans * b % M;
    b = b * b % M;
  }

  return ans;
}

int main() {
  ll n;

  cin >> n;
  cout << fastExp(n, fastExp(n - 1, 2)) << "\n";

  return 0;
}
