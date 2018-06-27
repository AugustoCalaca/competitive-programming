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

  int n, a, b, ans;
  cin >> n >> a >> b;
  ans = abs(((a + b) % n + n) % n);
  if(ans == 0) ans = n;
  cout << ans << "\n";

  return 0;
}
