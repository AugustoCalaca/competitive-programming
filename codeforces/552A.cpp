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

  int n, a, b, c, d, ans = 0;
  cin >> n;
  while(n--) {
    cin >> a >> b >> c >> d;
    ans += (c - a + 1) * (d - b + 1);
  }

  cout << ans << "\n";
  return 0;
}
