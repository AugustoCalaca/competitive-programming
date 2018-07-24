#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define null -1
#define MAX 50010
#define LOG 17
#define f first
#define s second
#define pii pair<int, int>
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<pii> mp;
vector<int> graph[MAX];
int table[MAX][LOG];
int depth[MAX];

void dfs(int node, int parent, int distance = 0) {
  depth[node] = distance;
  table[node][0] = parent;

  for(int i = 0; i < (int)graph[node].size(); i++) {
    int neighbor = graph[node][i];
    if(depth[neighbor] == null)
      dfs(neighbor, node, distance + 1);
  }
}

int lca(int u, int v) {
  if(depth[u] < depth[v]) swap(u, v);

  for(int i = LOG - 1; i >= 0; i--)
    if(depth[u] - (1 << i) >= depth[v])
      u = table[u][i];

  if(u == v) return u;

  for(int i = LOG - 1; i >= 0; i--)
    if(table[u][i] != table[v][i] && table[u][i] != -1)
      u = table[u][i], v = table[v][i];

  return table[u][0];
}

int main() {
  FAST;
  int n, card;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> card;
    mp.pb({ card, i });
    depth[i] = null;
  }

  sort(mp.begin(), mp.end());

  int u, v;
  for(int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    graph[u].pb(v);
    graph[v].pb(u);
  }

  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= LOG; j++)
      table[i][j] = null;

  dfs(0, -1);

  for(int j = 1; j <= LOG; j++)
    for(int i = 1; i <= n; i++)
      if(table[i][j - 1] != null)
        table[i][j] = table[table[i][j - 1]][j - 1];

  int ans = 0;
  for(int i = 0; i < n; i += 2)
    ans += depth[mp[i].s] + depth[mp[i + 1].s] - 2 * depth[lca(mp[i].s, mp[i + 1].s)];

  cout << ans << "\n";
  return 0;
}
