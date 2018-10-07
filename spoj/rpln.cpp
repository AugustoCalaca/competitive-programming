#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 100100
#define LOG 18
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int table[MAX][LOG];
int v[MAX];

int min(int a, int b) {
  return a < b ? a : b;
}

void build(int n) {
  for(int j = 1; j <= LOG; j++)
    for(int i = 0; i + (1 << j) <= n; i++)
      table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
  int h = r - l + 1;
  int k = (int)floor(log2(h));

  return min(table[l][k], table[l + h - (1 << k)][k]);
}

int main() {
  FAST;

  int t, n, q, a, b, k = 1;
  for(cin >> t; t--; ) {
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
      cin >> v[i];
      table[i][0] = v[i];
    }

    build(n);

    cout << "Scenario #" << k++ << ":\n";
    while(q--) {
      cin >> a >> b;
      cout << query(--a, --b) << "\n";
    }
  }
  return 0;
}
