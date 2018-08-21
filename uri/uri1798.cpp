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

  int n, t, prizes[1010], rod[1010], pd[1010][2010];
  cin >> n >> t;
  for(int i = 0; i < n; i++) cin >> rod[i] >> prizes[i];

  for(int i = 0; i <= n; i++) pd[i][0] = 0;
  for(int i = 0; i <= t; i++) pd[0][i] = 0;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= t; j++) {
      if(rod[i - 1] <= j)
        pd[i][j] = max(prizes[i - 1] + pd[i][j - rod[i - 1]], pd[i - 1][j]);
      else
        pd[i][j] = pd[i - 1][j];
    }

  cout << pd[n][t] << "\n";
  return 0;
}
