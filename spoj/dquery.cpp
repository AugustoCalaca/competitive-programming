#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 30010
#define MAX2 1000010
#define MAX3 200010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

int bit[MAX], v[MAX], last[MAX2], ans[MAX3];

struct Query {
  int l, r, idx;
};

bool comp(Query& a, Query& b) {
  return a.r < b.r;
}

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

vector<Query> vq;

int main() {
  FAST;

  int n, q;

  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> v[i];

  cin >> q;
  int l, r;
  for(int i = 0; i < q; i++) {
    cin >> l >> r;
    vq.pb({ l - 1, r - 1, i });
  }

  sort(vq.begin(), vq.end(), comp);
  fill(last, last + MAX2, -1);

  int qc = 0;
  for(int i = 0; i < n; i++) {
    if(last[v[i]] != -1)
      update(n, last[v[i]] + 1, -1);
    last[v[i]] = i;
    update(n, i + 1, 1);

    for(; qc < q && vq[qc].r == i; qc++)
      ans[vq[qc].idx] = query(vq[qc].r + 1) - query(vq[qc].l);
  }

  for(int i = 0; i < q; i++) cout << ans[i] << "\n";
  return 0;
}
