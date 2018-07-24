#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 100010
#define LOG 17
#define f first
#define s second
#define pil pair<int, ll>
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int table[MAX][LOG];
pil depth[MAX]; // store level and distance from the root

void dfs(vector<pil> graph[], int node, int parent, int dist1 = 0, ll dist2 = 0) {
  depth[node].f = dist1;
  depth[node].s = dist2;
  table[node][0] = parent;

  for(int i = 0; i < (int)graph[node].size(); i++) {
    pil neighbor = graph[node][i];
    if(depth[neighbor.f].f == -1)
      dfs(graph, neighbor.f, node, dist1 + 1, dist2 + neighbor.s);
  }
}

int lca(int u, int v) {
  if(depth[u].f < depth[v].f) swap(u, v);

  for(int i = LOG - 1; i >= 0; i--)
    if(depth[u].f - (1 << i) >= depth[v].f)
      u = table[u][i];

  if(u == v) return u;

  for(int i = LOG - 1; i >= 0; i--)
    if(table[u][i] != table[v][i] && table[u][i] != -1)
      u = table[u][i], v = table[v][i];

  return table[u][0];
}

int main() {
  FAST;

  int n, u, v, dist;
  while(true) {
    vector<pil> graph[MAX];
    cin >> n;
    if(n == 0) break;
    for(int i = 0; i < n - 1; i++) {
      cin >> u >> dist;
      graph[u].pb({ i + 1, dist });
      graph[i + 1].pb({ u, dist });
      depth[i].f = -1;
    }
    depth[n].f = depth[n - 1].f = -1;

    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= LOG; j++)
        table[i][j] = -1;

    dfs(graph, 0, -1);

    for(int j = 1; j <= LOG; j++)
      for(int i = 0; i <= n; i++)
        if(table[i][j - 1] != -1)
          table[i][j] = table[table[i][j - 1]][j - 1];

    int q;
    for(cin >> q; q--; ) {
      cin >> u >> v;
      cout << (depth[u].s + depth[v].s - 2 * (depth[lca(u, v)]).s);
      if(q) cout << " ";
    }

    cout << "\n";
  }

  return 0;
}
