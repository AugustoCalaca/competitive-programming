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

  int n, ans = 0, v[100010];
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    v[i] = v[i] - i <= 0 ? 0 : v[i] - i;
    if(!v[i]) { cout << i + 1 << "\n"; return 0; }
  }

  int b = 1000000010, c;
  for(int i = 0; i < n; i++) {
    c = v[i] / n;
    if(v[i] % n) c++;
    if(c < b) ans = i + 1, b = c;
  }

  cout << ans << "\n";
  return 0;
}
