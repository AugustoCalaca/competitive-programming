#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
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
  ll v[100010];

  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n);
  cout << v[k - 1] << "\n";
  return 0;
}
