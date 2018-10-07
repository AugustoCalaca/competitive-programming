#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int phi[MAX];
ll ans[MAX];

void precomp() {
  for(int i = 1; i < MAX; i++) phi[i] = i;
  for(int i = 2; i < MAX; i++)
    if(phi[i] == i) {
      phi[i] = i - 1;
      for(int j = (i << 1); j < MAX; j += i)
        phi[j] = (phi[j] / i) * (i - 1);
    }
}

void solve() {
  ans[1] = 0, ans[2] = 1;
  for(int i = 3; i < MAX; i++)
    ans[i] = ans[i - 1] + i - phi[i];
}

int main() {
  FAST;

  precomp();
  solve();

  int t, n, k = 1;
  cin >> t;
  while(t--) {
    cin >> n;
    cout << "Case " << k++ << ": " << ans[n] << "\n";
  }

  return 0;
}
