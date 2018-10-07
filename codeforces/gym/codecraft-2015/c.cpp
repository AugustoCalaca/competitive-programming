#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int t, n, p, ans;
  string s;

  cin >> t;
  while(t--) {
    cin >> n >> s >> p;
    ans = 2 * p;
    if(s == "even") ans--;
    cout << ans << "\n";
  }

  return 0;
}
