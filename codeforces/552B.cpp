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

  int n, a, dig, i = 2;

  cin >> n;
  a = n;
  for(dig = 0; a; a /= 10) { dig++; }

  if(n < 10) {
    cout << n << "\n";
    return 0;
  }

  ll lim = 10, ans = 9;
  for(; i < dig; i++) {
    a = lim * 10 - 1;
    ans += (a - lim + 1) * i;
    lim *= 10;
  }

  ans += (n - lim + 1) * i;

  cout << ans << "\n";

  return 0;
}
