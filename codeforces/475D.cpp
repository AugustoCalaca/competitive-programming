#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 100000
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int v[M];
int table[M][(int)floor(log2(M))];

int gcd(int a, int b) {
  while(b) {
    a %= b;

    a ^= b;
    b ^= a;
    a ^= b;
  }

  return a;
}

void build(int n) {
  for(int i = 0; i < n; i++)
    table[i][0] = v[i];

  for(int j = 1; (1 << j) <= n; j++)
    for(int i = 0; i + (1 << j) <= n; i++)
      table[i][j] = gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
  int h = r - l + 1;
  int k = (int)floor(log2(h));

  return gcd(table[l][k], table[l + h - (1 << k)][k]);
}

int main() {
  FAST;

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];

  build(n);

  int q, l;

  cin >> q;
  while(q--) {
    cin >> l;
    int ans = 0;
    for(int k = 0; k < n; k++) {
      int r = k, g = 0;
      for(int j = (int)floor(log2(n)); j >= 0; j--) {
        if(r + (1 << j) - 1 >= n) continue;
        if(gcd(g, table[r][j]) > l) {
          g = gcd(g, table[r][j]);
          r += (1 << j);
        }
      }
      ans += n - r;
    }

    cout << ans << "\n";
  }

  return 0;
}
