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
  int n, v, ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> v;
    if(v == 0) ans++;
  }

  if(ans > n / 2) cout << "Y\n";
  else cout << "N\n";
  return 0;
}
