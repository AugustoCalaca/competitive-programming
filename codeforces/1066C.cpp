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

  char ch;
  map<int, int> m;
  int q, n, l = 0, r = 1;
  for(cin >> q; q--; ) {
    cin >> ch;
    if(ch == 'L') {
      cin >> n;
      m.insert({ n, l-- });
    } else if(ch == 'R') {
      cin >> n;
      m.insert({ n, r++ });
    } else {
      cin >> n;
      int d = m[n];
      cout << min(d - l, r - d) - 1 << "\n";
    }
  }

  return 0;
}
