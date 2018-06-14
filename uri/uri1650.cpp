#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  fast();

  int n, m, c;
  ll ans;
  while(true) {
    cin >> n >> m >> c;
    if(n == 0 && m == 0 && c == 0) break;
    if(c & 1) ans = ceil((float)(n - 7) * (m - 7) / 2);
    else ans = floor((n - 7) * (m - 7) / 2);
    cout << ans << "\n";
  }
  return 0;
}
