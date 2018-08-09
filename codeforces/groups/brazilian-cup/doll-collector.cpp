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

  int q;
  ll n;
  for(cin >> q; q--; ) {
    cin >> n;
    cout << (ll)floor((sqrt(8 * n + 1) - 1) / 2) << "\n";
  }

  return 0;
}
