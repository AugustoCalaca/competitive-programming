#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define MAX 30010
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<string, int> psi;

int arr[MAX], bit[MAX];

bool comp(psi& a, string b) {
  return a.f < b;
}

void update(int idx, int val, int n) {
  for(; idx <= n; idx += idx & -idx)
    bit[idx] += val;
}

int query(int idx) {
  int sum = 0;
  for(; idx > 0; idx -= idx & -idx)
    sum += bit[idx];
  return sum;
}

ll invcount(int n) {
  ll inv = 0;
  for(int i = n - 1; i >= 0; i--) {
    inv += query(arr[i] - 1);
    update(arr[i], 1, n);
  }

  return inv;
}

int main() {
  FAST;

  string str;
  int t, n;
  for(cin >> t; t--; ) {
    cin >> n;
    vector<psi> vs, temp;
    for(int i = 0; i < n; i++) {
      cin >> str;
      vs.pb({ str, i + 1});
    }

    for(int i = 0; i < n; i++) {
      cin >> str;
      temp.pb({ str, i + 1});
    }

    sort(temp.begin(), temp.end());
    for(int i = 0; i < n; i++) {
      arr[i] = lower_bound(temp.begin(), temp.end(), vs[i].f, comp)->s;
      bit[i + 1] = 0;
    }

    cout << invcount(n) << "\n";
  }

  return 0;
}
