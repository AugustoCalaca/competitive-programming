#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000
#define LOG 17
#define pb push_back
using namespace std;

vector<int> graph[MAX];
int pa[MAX][LOG];
int depth[MAX]; // distance from the root node

void dfs(int node, int parent, int distance = 0) {
  depth[node] = distance;
  pa[node][0] = parent; // this node's parent node

  for(int i = 0; i < (int)graph[node].size(); i++) {
    int neighbor = graph[node][i];
    if(depth[neighbor] == -1)
      dfs(neighbor, node, distance + 1);
  }
}

int lca(int u, int v) {
  if(depth[u] < depth[v])
    swap(u, v);

  // search for a new v vertex
  for(int i = LOG - 1; i >= 0; i--)
    // if we have the opportunity to jump 2^i, we jump
    if(depth[u] - (1 << i) >= depth[v])
      u = pa[u][i];

  if(u == v)
    return u;

  for(int i = LOG - 1; i >= 0; i--) {
    if(pa[u][i] != pa[v][i] && pa[u][i] != -1)
      u = pa[u][i], v = pa[v][i];
  }

  return pa[u][0];
}

int main() {
  for(int i = 0; i < MAX; i++) depth[i] = -1;
  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < LOG; j++)
      pa[i][j] = -1;

  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].pb(b);
    graph[b].pb(a);
  }

  dfs(0, -1);

  for(int j = 1; j <= LOG; j++)
    for(int i = 1; i <= n; i++)
      if(pa[i][j - 1] != -1)
        pa[i][j] = pa[pa[i][j - 1]][j - 1];

  while(q--) {
    int u, v;
    cin >> u >> v;

    cout << "lca of " << u << " and " << v << " = " << lca(u, v) << "\n";
  }

  return 0;
}