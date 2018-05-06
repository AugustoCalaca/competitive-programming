#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

int main() {
  fast();

  int vn[100010];
  int n, a;
  vn[0] = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a;
    vn[i] = vn[i - 1] + a;
  }

  int m, b;
  cin >> m;
  for(int  i = 0; i < m; i++) {
    cin >> b;
    cout << (lower_bound(vn, vn + n, b) - vn) << "\n";
  }

  return 0;
}
