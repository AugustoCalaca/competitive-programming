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

  int n;
  while(true) {
    cin >> n;
    if(!n) break;

    int ans = 0;
    for(; n; n--)
      ans += n * n;
    cout << ans << "\n";
  }
  return 0;
}
