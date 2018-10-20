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

  ll k, a, b, ans = 0;
  cin >> k >> a >> b;

  if(a > 0 && b > 0)
    ans = b / k - (a - 1) / k;
  else if(b == 0)
    ans = abs(a) / k + 1;
  else if(a == 0)
    ans = abs(b) / k + 1;
  else if(a < 0 && b > 0)
    ans = abs(a) / k + b / k + 1;
  else
    ans = abs(a) / k - (abs(b) - 1) / k;
  cout << ans << "\n";
  return 0;
}
