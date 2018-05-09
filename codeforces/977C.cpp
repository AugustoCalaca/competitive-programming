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

ll v[1000000];
int main() {
  fast();
  int n, k;

  v[0] = 0;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> v[i];
  sort(v, v + n + 1);

  if(k == 0) {
    if(v[1] != 1) cout << "1\n";
    else cout << "-1\n";
    return 0;
  }

  if(v[k] != v[k + 1]) cout << v[k] << "\n";
  else cout << "-1\n";

  return 0;
}
