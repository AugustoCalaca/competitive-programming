#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  string a, b;
  int ans = 0;
  cin >> a >> b;

  for(size_t i = 0; i + b.size() - 1 < a.size(); i++) {
    bool f = true;
    for(size_t j = 0, k = i; j < b.size(); j++, k++)
      if(a[k] == b[j]) {
        f = false;
        break;
      }
    if(f) ans++;
  }

  cout << ans << "\n";
  return 0;
}
