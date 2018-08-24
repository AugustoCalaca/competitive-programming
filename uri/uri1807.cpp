#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  ll r;
  int b = 3;
  const ll MOD = 2147483648 - 1;
  cin >> r;

  ll ans = 1;
  for(; r; r >>= 1) {
    if(r & 1) ans = (ans % MOD * b % MOD) % MOD;
    b = (b % MOD * b % MOD) % MOD;
  }

  cout << ans << "\n";
  return 0;
}
