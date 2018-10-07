#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int bit[M], v[M], temp[M];

void update(int n, int idx, int val) {
  for(; idx <= n; idx += idx & -idx)
    bit[idx] += val;
}

int query(int idx) {
  int sum = 0;
  for(; idx > 0; idx -= idx & -idx)
    sum += bit[idx];
  return sum;
}

int main() {
  FAST;

  // ajeitar a contagem da query
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    temp[i] = v[i];
  }

  sort(temp, temp + n);
  for(int i = 0; i < n; i++)
    v[i] = lower_bound(temp, temp + n, v[i]) - temp;

  int ans = 0, inv = 0;
  for(int i = n - 1, j = n - 1; i >= 0; i--) {
    for(; inv < k && j >= 0; j--) {
      inv += query(v[j]);
      update(n, v[j] + 1, 1);
    }
    ans += ;
    update(n, v[i] + 1, -1);
    inv -= query(v[i]);
  }

  cout << ans << "\n";
  return 0;
}
