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

int fexp(int a, int b) {
  int ans = 1;
  for(; b; b >>= 1) {
    if(b & 1) ans = (ans % 10 * a % 10) % 10;
    a = (a % 10 * a % 10) % 10;
  }
  return ans;
}

int main() {
  FAST;

  int t, a, b;
  cin >> t;
  while(t--) {
    cin >> a >> b;
    cout << fexp(a, b) << "\n";
  }
  return 0;
}
