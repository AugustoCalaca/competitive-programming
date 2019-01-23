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

vector<int> v[M];
ll preS[M];

bool comp(int a, int b) { return a > b; }

int main() {
  FAST;

  int n, m, a, b, l = 0;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v[a - 1].pb(b);
    l = max(l, a);
  }

  for(int i = 0; i < l; i++) {
    sort(v[i].begin(), v[i].end(), comp);
    ll sum = 0;
    for(size_t j = 0; j < v[i].size(); j++) {
      sum += v[i][j];
      if(sum > 0)
        preS[j] += sum;
    }
  }

  ll ans = 0;
  for(int i = 0; i < n; i++)
    ans = max(ans, preS[i]);

  cout << ans << "\n";
  return 0;
}
