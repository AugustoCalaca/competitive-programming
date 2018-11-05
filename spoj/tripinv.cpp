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

ll bit[2][M];
int arr1[M], arr2[M];

void update(int id, int idx, int val, int n) {
  for(; idx <= n; idx += idx & -idx)
    bit[id][idx] += val;
}

ll query(int id, int idx) {
  ll sum = 0;
  for(; idx > 0; idx -= idx & -idx)
    sum += bit[id][idx];
  return sum;
}

int main() {
  FAST;

  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr1[i];

  for(int i = n - 1; i >= 0; i--) {
    arr2[i] = query(0, arr1[i]);
    update(0, arr1[i] + 1, 1, n);
  }

  ll ans = 0;
  for(int i = n - 1; i >= 0; i--) {
    ans += query(1, arr1[i]);
    update(1, arr1[i] + 1, arr2[i], n);
  }

  cout << ans << "\n";
  return 0;
}
