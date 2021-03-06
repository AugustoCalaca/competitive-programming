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
  int n, q, f, v[100010];
  cin >> n >> q;
  for(int i = 0; i < n; i++) cin >> v[i];
  while(q--) {
    cin >> f;
    if(binary_search(v, v + n, f))
      cout << lower_bound(v, v + n, f) - v << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
