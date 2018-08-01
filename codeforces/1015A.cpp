#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  int n, m, l, r, seg[110];
  set<int> st;

  cin >> n >> m;
  for(int i = 1; i <= m; i++) seg[i] = 1;

  for(int i = 0; i < n; i++) {
    cin >> l >> r;
    for(int j = l; j <= r; j++)
      seg[j] = 0;
  }

  cout << count(seg + 1, seg + m + 1, 1) << "\n";
  for(int i = 1; i <= m; i++)
    if(seg[i])
      cout << i << " ";
  cout << "\n";

  return 0;
}
