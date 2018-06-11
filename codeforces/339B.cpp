#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  int n, m, a, cur = 1;
  ll ans = 0;
  cin >> n >> m;
  while(m--) {
    cin >> a;
    if(a > cur) ans += (a - cur);
    else if(a < cur) ans += (n - cur + a);
    cur = a;
  }

  cout << ans << "\n";
  return 0;
}