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

  int n, m, k, v[200010];
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) cin >> v[i];

  ll fit = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(fit + v[i] > k) m--, fit = v[i];
    else fit += v[i];
    if(m == 0) return cout << n - i - 1 << "\n", 0;
  }

  cout << n << "\n";
  return 0;
}
