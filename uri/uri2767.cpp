#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

#define M 100010
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

// ac
int main() {
  fast();
  int n, m, k, hm, hw;
  while(cin >> n >> m >> k) {
    map<int, ll> mp;
    for(int i = 0; i < n; i++) {
      cin >> hm;
      mp[hm % k]++;
    }

    ll max = 0;
    for(int j = 0; j < m; j++) {
      cin >> hw;
      hw %= k;
      auto it = mp.find((k - hw) % k);
      if(it != mp.end()) max += it->second;
    }

    cout << max << "\n";
  }

  return 0;
}
