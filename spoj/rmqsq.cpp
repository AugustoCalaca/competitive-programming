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
int table[M][(int)floor(log2(M)) + 1];

void build(int n) {
  for(int i = 0; i < n; i++)
    table[i][0] = v[i];

  for(int j = 1; (1 << j) <= n; j++)
    for(int i = 0; i + (1 << (j - 1)) <= n; i++)
      table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
  int h = r - l + 1;
  int k = (int)floor(log2(h));

  return min(table[l][k], table[l + h - (1 << k)][k]);
}

int main() {
  FAST;

  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  build(n);

  int q, l, r;
  cin >> q;
  while(q--) {
    cin >> l >> r;
    cout << query(l, r) << "\n";
  }

  return 0;
}
