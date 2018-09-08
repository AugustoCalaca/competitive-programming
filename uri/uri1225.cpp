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

  int n, sum, m, ans, v[100010];
  while(cin >> n) {
    sum = ans = 0;
    for(int i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }
    if(sum % n != 0) {
      cout << "-1\n";
      continue;
    }

    m = sum / n;
    for(int i = 0; v[i] < m; i++)
      ans += m - v[i];
    cout << ans + 1 << "\n";
  }
  return 0;
}
