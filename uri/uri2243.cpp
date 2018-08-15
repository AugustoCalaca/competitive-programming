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

int v[50100], n;

bool check(int cl, int h) {
  for(int i = cl, j = 1; i - j >= 0 && i + j < n; j++)
    if(v[i - j] < h - j || v[i + j] < h - j)
      return false;
  return true;
}

int main() {
  FAST;

  int h, ans = 1;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 1; i + ans < n; i++) {
    h = min(ans + 1, v[i]);
    if(check(i, h))
      ans = max(ans, h);
  }

  cout << ans << "\n";
  return 0;
}
