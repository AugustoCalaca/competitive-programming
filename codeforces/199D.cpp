#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>

#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main() {
  fast();

  int n, k;
  cin >> n >> k;
  string st[2];
  cin >> st[0] >> st[1];

  if(k >= n) {
    cout << "YES\n";
    return 0;
  }

  ll vis[400010][2];
  stack<pair<ll, ll> > last;

  vis[1][0] = 1;
  last.push({ 1, 0 });

  ll a, b;
  while(last.size()) {
    a = last.top().f;
    b = last.top().s;
    last.pop();

    if(a > n) {
      cout << "YES\n";
      return 0;
    }

    if(vis[a][b] > a) continue;

    if(a > 0 && vis[a - 1][b] == 0 && st[b][a - 2] == '-') {
      last.push({ a - 1, b });
      vis[a - 1][b] = vis[a][b] + 1;
    }

    if(a < n && vis[a + 1][b] == 0 && st[b][a] == '-') {
      last.push({ a + 1, b });
      vis[a + 1][b] = vis[a][b] + 1;
    }

    if(vis[a + k][1 - b] == 0 && (a + k > n || (st[1 - b][a + k - 1]) == '-')) {
      last.push({ a + k, 1 - b });
      vis[a + k][1 - b] = vis[a][b] + 1;
    }
  }

  cout << "NO\n";
  return 0;
}
