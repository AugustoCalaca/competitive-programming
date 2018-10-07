#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

#define M 1100
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll bit[M][M];

void update(int l, int r, int n, ll val) {
  for(; l <= n; l += l & -l)
    for(int j = r; j <= n; j += j & -j)
      bit[l][j] += val;
}

ll query(int l, int r) {
  ll sum = 0;
  for(; l > 0; l -= l & -l)
    for(int j = r; j > 0; j -= j & -j)
      sum += bit[l][j];
  return sum;
}

int main() {
  FAST;

  string str;
  int t, n, v, l, r, l1, r1, l2, r2;
  for(cin >> t; t--; ) {
    cin >> n;
    while(true) {
      cin >> str;
      if(str == "SET") {
        cin >> l >> r >> v;

        ll v1 = query(l + 1, r + 1);
        ll v2 = query(l, r + 1);
        ll v3 = query(l + 1, r);
        ll v4 = query(l, r);

        update(l + 1, r + 1, n, v - (v1 + v4 - v2 - v3));
      }
      else if(str == "SUM") {
        cin >> l1 >> r1 >> l2 >> r2;

        ll v1 = query(l2 + 1, r2 + 1);
        ll v2 = query(l1, r2 + 1);
        ll v3 = query(l2 + 1, r1);
        ll v4 = query(l1, r1);

        cout << v1 + v4 - v2 - v3 << "\n";
      }
      else break;
    }
    for(int i = 1; i < M; i++)
      for(int j = 1; j < M; j++)
        bit[i][j] = 0;
  }

  return 0;
}
