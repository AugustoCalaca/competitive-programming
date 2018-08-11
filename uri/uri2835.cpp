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

  int n, v[10010];
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n);

  int d = 0;
  for(int i = 0; i < n; i++) {
    if(v[i] - d > 8) return cout << "N\n", 0;
    d = v[i];
  }
  cout << "S\n";
  return 0;
}
