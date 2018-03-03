#include <iostream>
#include <algorithm>

#define M 1000000
using namespace std;

// ac
int main() {
  int n, v, ans = 0;

  for(cin >> n; n--; ) {
    cin >> v;
    ans = max(ans, min(v - 1, M - v));
  }

  cout << ans << "\n";
  return 0;
}
