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

  int t, v, L, l, r;
  for(cin >> t; t--; ) {
    cin >> L >> v >> l >> r;
    cout << (L / v) - ((r / v) - ((l - 1) / v)) << "\n";
  }
  return 0;
}
