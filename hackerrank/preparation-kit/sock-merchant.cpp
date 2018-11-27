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

  int n, m;
  map<int, int> mp;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> m;
    mp[m]++;
  }

  int ans = 0;
  for(auto it = mp.begin(); it != mp.end(); it++)
    ans += it->s / 2;

  cout << ans << "\n";
  return 0;
}
