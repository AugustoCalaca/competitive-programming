#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 1010
#define LOG 11
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int table[MAX][LOG];
int depth[MAX];

void dfs(vector<int> graph[], int node, int parent, int distance = 0) {
  depth[node] = distance;
  table[node][0] = parent;

  for(int i = 0; i < (int)graph[node].size(); i++) {
    int neighbor = graph[node][i];
    if(depth[neighbor] ==  -1)
      dfs(graph, neighbor, node, distance + 1);
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

  int n, q, t, child, u, v, k = 1;
  cin >> t;
  while(t--) {
    vector<int> graph[MAX];
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> child;
      for(int j = 0; j < child; j++) {
        cin >> u;
        graph[i + 1].pb(u);
        graph[u].pb(i + 1);
      }
      depth[i] =  -1;
    }
    depth[n] = -1;

    for(int j = 0; j <= LOG; j++)
      for(int i = 0; i <= n; i++)
        table[i][j] = -1;

    dfs(graph, 1, -1);

    for(int j = 1; j <= LOG; j++)
      for(int i = 0; i <= n; i++)
        if(table[i][j - 1] != -1)
          table[i][j] = table[table[i][j - 1]][j - 1];

    cout << "Case " << k++ << ":\n";
    cin >> q;
    while(q--) {
      cin >> u >> v;
      cout << lca(u, v) << "\n";
    }
  }

  return 0;
}
