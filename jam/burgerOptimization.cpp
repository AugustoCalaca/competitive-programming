#include <iostream>
#include <algorithm>

#define sq(x) (x) * (x)
using namespace std;

// ac
int main() {
  int k, t;
  int v[110];
  int d[110];
  int n = 1;

  for(cin >> t; t--; ) {
    cin >> k;
    for(int i = 0; i < k; i++) {
      cin >> d[i];
      v[i] = min(i, k - i - 1);
    }

    sort(v, v + k);
    sort(d, d + k);
    int ans = 0;
    for(int i = 0; i < k; i++)
      ans += sq(d[i] - v[i]);
    cout << "Case #" << n++ << ": " << ans << "\n";
  }

  return 0;
}
