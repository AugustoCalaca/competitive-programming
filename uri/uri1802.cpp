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
  int n, k, v;
  vector<int> vec[5];
  vector<int> vec2;

  for(int i = 0; i < 5; i++) {
    cin >> n;
    for(int pi = 0; pi < n; pi++) {
      cin >> v;
      vec[i].pb(v);
    }
  }

  cin >> k;

  for(int p = 0; p < (int)vec[0].size(); p++)
    for(int m = 0; m < (int)vec[1].size(); m++)
      for(int f = 0; f < (int)vec[2].size(); f++)
        for(int q = 0; q < (int)vec[3].size(); q++)
          for(int b = 0; b < (int)vec[4].size(); b++)
            vec2.pb(vec[0][p] + vec[1][m] + vec[2][f] + vec[3][q] + vec[4][b]);

  sort(vec2.begin(), vec2.end());
  int ans = 0;
  for(int i = vec2.size(); i >= (int)vec2.size() - k; i--)
    ans += vec2[i];

  cout << ans << "\n";
  return 0;
}
