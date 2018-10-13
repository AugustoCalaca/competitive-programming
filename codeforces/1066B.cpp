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

int v[2010];
int main() {
  FAST;

  int n, r;
  cin >> n >> r;
  for(int i = 1; i <= n; i++)
    cin >> v[i];

  int ans = 0, l;
  l = 1 - r;
  for(int i = 1; i <= n; i++) {
    int flag = 0;
    for(int j = max(i, l + 1); j <= n; j++)
      if(v[j] && l + r >= j - r + 1) flag = j;
    if(flag == 0) return cout << "-1\n", 0;
    l = flag;
    ans++;
    if(l + r > n) break;
  }

  cout << ans << "\n";
  return 0;
}
