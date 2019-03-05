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

  int q, op, n;
  map<int, int> mp, mp2;
  
  for(cin >> q; q--; ) {
    cin >> op >> n;
    if(op == 1) {
      if(mp[n] > 0)
        mp2[mp[n]]--;
      mp[n]++;
      mp2[mp[n]]++;
    }
    else if(op == 2) {
      if(mp[n] > 0) {
        mp2[mp[n]]--;
        mp[n]--;
        mp2[mp[n]]++;
      }
    }
    else cout << (mp2[n] > 0 ? 1 : 0)  << "\n";
  }

  return 0;
}
