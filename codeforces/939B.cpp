#include <iostream>
#include <utility>
#include <climits>

#define f first
#define s second
using namespace std;
typedef long long ll;

// ac
int main() {
  int k;
  ll v[100010], n, min = LLONG_MAX;
  pair<ll, ll> pll;

  cin >> n >> k;
  for(int i = 0; i < k; i++) {
    cin >> v[i];
    if(n % v[i] < min) {
      pll.f = n / v[i];
      pll.s = i + 1;
      min = n % v[i];
    }
  }

  cout << pll.s << " " << pll.f << "\n";

  return 0;
}
