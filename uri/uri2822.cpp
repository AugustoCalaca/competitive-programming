#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 200100
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int gra[MAX][1];

int maxm(int a, int b) { return a > b ? a : b; }

int main() {
  FAST;

  int t, n, q, j, k, op;
  ll sum;

  for(cin >> t; t--; ) {
    cin >> n >> q;

    sum = 0;
    for(int i = 1; i < n; i++) {
      gra[i][0] = maxm(i - 1, n - i);
      sum += gra[i][0];
    }
    while(q--) {
      cin >> op;
      if(op == 1) {
        cin >> j >> k;

        sum -= gra[j][0];
        gra[j][0] = maxm(k - 1, n - k);
        sum += gra[j][0];
      }
      else {
        cout << sum << "\n";
      }
    }
  }

  return 0;
}
