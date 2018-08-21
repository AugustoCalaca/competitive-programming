#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;
  int q, e, v;
  set<int> s;

  cin >> q >> e;
  while(e--) {
    cin >> v;
    s.insert(v);
  }

  while(q--) {
    cin >> v;

    if(s.find(v) != s.end()) cout << "0\n";
    else cout << "1\n";
    s.insert(v);
  }
  return 0;
}
