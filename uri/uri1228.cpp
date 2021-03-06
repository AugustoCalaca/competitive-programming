#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int start[30], fini[30], u[30];

int main() {
  FAST;

  int n;
  while(cin >> n) {
    for(int i = 0; i < n; i++)
      cin >> start[i];
    for(int i = 0; i < n; i++)
      cin >> fini[i];

    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++)
        if(fini[j] == start[i]) {
          u[i] = j;
          break;
        }
      if(i < 1) continue;
      for(int j = 0; j < i; j++)
        if(u[j] > u[i]) ans++;
    }

    cout << ans << "\n";
  }
  return 0;
}
