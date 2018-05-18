#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  fast();

  int n, m;
  ll v[2 * (int)1e5 + 100];

  cin >> n >> m;
  v[0] = 0;
  for(int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] += v[i - 1];
  }

  int ind;
  ll f;
  for(int i = 0; i < m; i++) {
    cin >> f;
    ind = lower_bound(v, v + n, f) - v;
    cout << ind << " " << f - v[ind - 1];
    cout << "\n";
  }

  return 0;
}
