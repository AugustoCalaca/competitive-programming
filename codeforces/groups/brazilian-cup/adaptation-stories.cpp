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

// ac
int main() {
  fast();

  int n, v, m = 0, ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> v;
    m += v;
    if(m < 0) {
      ans += abs(m);
      m = 0;
    }
  }

  cout << ans << "\n";
  return 0;
}
