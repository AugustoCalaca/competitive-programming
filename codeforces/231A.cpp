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

// ac
int main() {
  fast();

  int n, v[5], ans;
  cin >> n;
  ans = 0;
  while(n--) {
    for(int i = 0; i < 3; i++)
      cin >> v[i];

    if(count(v, v + 3, 1) > 1) ans++;
  }

  cout << ans << "\n";
  return 0;
}
