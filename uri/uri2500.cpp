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

int arr[1010], v[1010];


int main() {
  FAST;

  int n, m, k;
  while(cin >> n >> m >> k) {
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
      v[i + 1] = i;
    }
    v[1] = n;

    int ans = (v[k] + (n - 1) * (m - 1)) % n;
    if(ans == 0) ans = n - 1; else ans--;
    cout << arr[ans] << "\n";
  }

  return 0;
}
