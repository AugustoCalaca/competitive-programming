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

  int n, v[110];
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];

  int ans = 0;
  for(int i = 0; i + 1 < n; ans++) {
    if(!v[i + 2]) i += 2;
    else if(!v[i + 1]) i++;
  }

  cout << ans << "\n";
  return 0;
}
