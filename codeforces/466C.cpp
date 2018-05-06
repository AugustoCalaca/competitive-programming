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

ll arr[1000000];

ll countWays(int n, ll sum) {
  ll cnt[n] = { 0 };
  ll s = 0;
  for(int i = n - 1; i >= 0; i--) {
    s += arr[i];
    if(s == sum) cnt[i] = 1;
  }

  for(int i = n - 2; i >= 0; i--) cnt[i] += cnt[i + 1];

  ll ans;
  s = ans = 0;
  for(int i = 0; i + 2 < n; i++) {
    s += arr[i];
    if(s == sum) ans += cnt[i + 2];
  }

  return ans;
}

int main() {
  fast();

  int n;
  ll sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  if(sum % 3 == 0) cout << countWays(n, sum / 3) << "\n";
  else cout << "0\n";

  return 0;
}
