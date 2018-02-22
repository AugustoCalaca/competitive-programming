#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// correct
int main() {
  ll p[1010], e[1010], t, l, c = 1;

  for(cin >> t; t--;) {
    cin >> l;
    for(ll i = 0; i < l; i++)
      cin >> p[i] >> e[i];

    for(ll i = 0; i < l - 1; i++) {
      p[i] -= (p[i + 1] * e[i + 1]);
      if(p[i] > 0) p[i + 1] += p[i];
    }

    cout << "Case #" << c++ << ": "
       << max(p[l - 1], e[l - 1] + 1) << "\n";

  }

  return 0;
}
