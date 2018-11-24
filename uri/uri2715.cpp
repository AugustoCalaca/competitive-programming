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

  int n, v[1000100];
  ll preSum = 0, suffSum;
  while(cin >> n) {
    for(int i = 0; i < n; i++) {
      cin >> v[i];
      if(i + 1 < n)
        preSum += v[i];
    }

    if(n == 1) {
      cout << v[0] << "\n";
      continue;
    }

    suffSum = v[n - 1];
    ll diff, ans = 999999999999;
    for(int i = n - 2; i >= 0; i--) {
      diff = abs(preSum - suffSum);
      ans = min(ans, diff);
      preSum -= v[i];
      suffSum += v[i];
    }

    cout << ans << "\n";
  }

  return 0;
}
