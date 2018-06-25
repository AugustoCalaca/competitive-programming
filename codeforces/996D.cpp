#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define f first
#define s second
#define pii pair<int, int>
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

  int n, m;
  vector<int> arr;
  cin >> n;
  for(int i = 0; i < 2 * n; i++) {
    cin >> m;
    arr.pb(m);
  }

  int ans = 0;
  for(int i = 1; i < 2 * n; i += 2) {
    if(arr[i] != arr[i - 1]) {
      int j = i;
      for(; j < 2* n; j++)
        if(arr[j] == arr[i - 1]) break;
      ans += (j - i);

      for(int k = j; k > i; k--) {
        arr[k] ^= arr[k - 1];
        arr[k - 1] ^= arr[k];
        arr[k] ^= arr[k - 1];
      }
    }
  }

  cout << ans << "\n";
  return 0;
}
