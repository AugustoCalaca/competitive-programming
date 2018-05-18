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

  int n, k;
  int v[510];
  int ans[510];

  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  ans[0] = v[0];
  int min = 0;
  for(int i = 1; i < n; i++) {
    ans[i] = v[i] + max(0, k - v[i] - ans[i - 1]);
    min += (ans[i] - v[i]);
  }

  cout << min << "\n";

  for(int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";

  return 0;
}
