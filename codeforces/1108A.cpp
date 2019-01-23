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

  int q, l1, r1, l2, r2;
  for(cin >> q; q--; ) {
    cin >> l1 >> r1 >> l2 >> r2;
    if(l1 == l2) l1++;
    cout << l1 << " " << l2 << "\n";
  }

  return 0;
}
