#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;
  int s, b, l, r;

  while(true) {
    cin >> s >> b;
    if(s == 0 && b == 0) break;

    vector<int> vec;
    for(int i = 0; i < s; i++) vec.pb(i + 1);

    while(b--) {
      cin >> l >> r;

      auto it = lower_bound(vec.begin(), vec.end(), l);
      auto it2 = lower_bound(vec.begin(), vec.end(), r);

      if(it == vec.begin()) cout << "*";
      else cout << *(it - 1);
      cout << " ";
      if((it2 + 1) == vec.end()) cout << "*";
      else cout << *(it2 + 1);
      cout << "\n";

      vec.erase(it, ++it2);
    }

    cout << "-\n";
  }

  return 0;
}
