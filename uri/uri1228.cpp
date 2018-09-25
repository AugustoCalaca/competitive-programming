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

int start[30], fini[30];
int search(int n, int k) {
  for(int i = 0; i < n; i++)
    if(fini[i] == k) return i;
}

int main() {
  FAST;

  int n;
  while(cin >> n) {
    for(int i = 0; i < n; i++)
      cin >> v[i];
    for(int i = 0; i < n; i++)
      cin >> fini[i];

    for(int i = 1; i < n; i++) {
      int f = find(n, start[i]);
      if(f < i) ans += (i - f);
    }

    cout << ans << "\n";
  }
  return 0;
}
