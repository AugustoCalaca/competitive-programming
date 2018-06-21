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

int main() {
  fast();

  int n;
  ll k, v[200020];
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  sort(v, v + n);

  int ans = n;
  for(int i = n - 1; i >= 1; i--) {
    if(v[i] > v[i - 1] && v[i] <= v[i - 1] + k) {
      ans--;
      for(int j = i - 2; j >= 0 && v[i - 1] == v[j]; j--)
        ans--;
    }
  }

  cout << ans << "\n";
  return 0;
}
