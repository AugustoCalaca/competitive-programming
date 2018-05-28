#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

int main() {
  fast();

  int n, k;
  ll v[1010];

  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n);
  for(int i = 0; i < n; i++) cout << v[i] << " ";
  cout << "\n";

  return 0;
}
