#include <iostream>

#define MAX (int)1e5 + 10
using namespace std;

// ac
int main() {
  int n, m, a[MAX], b[MAX];

  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= m; i++) cin >> b[i];

  long int ans, a0, b0;
  ans = a0 = b0 = 0;
  int i = 0, j = 0;
  while(true) {
      if(a0 <= b0) a0 += a[++i];
      else b0 += b[++j];
      if(a0 == b0) ans++;
      if(i == n && j == m) break;
  }

  cout << ans << endl;
  return 0;
}
