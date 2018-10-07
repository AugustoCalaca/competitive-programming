#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define MAX 100010
#define LIM 1000010
#define LOG 17
#define f first
#define s second
#define pii pair<int, int>
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<pii> graph[MAX];
int table[MAX][LOG];
int mini[MAX][LOG];
int maxi[MAX][LOG];
int depth[MAX];
int logN[MAX];

void dfs(int node, int parent = -1, int dist = 0, int w = -1) {
  table[node][0] = parent;
  depth[node] = dist;

  if(w != -1) mini[node][0] = maxi[node][0] = w;

  for(int i = 0; i < (int)graph[node].size(); i++) {
    pii neighbor = graph[node][i];
    if(depth[neighbor.f] == -1)
      dfs(neighbor.f, node, dist + 1, neighbor.s);
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

void complog() {
  logN[1] = 1;
  for(int i = 2; i < MAX; i++)
    logN[i] = logN[i / 2] + 1;
}

void precomp(int n) {
  for(int j = 0; j <= LOG; j++)
    for(int i = 0; i <= n; i++) {
      table[i][j] = -1;
      mini[i][j] = LIM;
      maxi[i][j] = -LIM;
    }

  dfs(1);

  for(int j = 1; j <= LOG; j++)
    for(int i = 0; i <= n; i++)
      if(table[i][j - 1] != -1) {
        table[i][j] = table[table[i][j - 1]][j - 1];
        mini[i][j] = min(mini[i][j - 1], mini[table[i][j - 1]][j - 1]);
        maxi[i][j] = max(maxi[i][j - 1], maxi[table[i][j - 1]][j - 1]);
      }
}

pii query(int u, int v) {
  pii ans;
  ans.f = LIM;
  ans.s = -LIM;

  int lg = logN[depth[u]];

  for(int i = lg; i >= 0; i--)
    if(depth[u] - (1 << i) >= depth[v]) {
      ans.f = min(ans.f, mini[u][i]);
      ans.s = max(ans.s, maxi[u][i]);
      u = table[u][i];
    }

  return ans;
}

int main() {
  FAST;

  complog();

  int n, u, v, w;
  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    graph[u].pb({ v, w });
    graph[v].pb({ u, w });

    depth[i] = -1;
  }
  depth[n] = depth[n - 1] = -1;

  precomp(n);

  int q, a, b;
  pii ans;
  cin >> q;
  while(q--) {
    cin >> a >> b;
    int lc = lca(a, b);
    if(a == lc) {
      ans = query(b, lc);
      cout << ans.f << " " << ans.s << "\n";
    }
    else if(b == lc) {
      ans = query(a, lc);
      cout << ans.f << " " << ans.s << "\n";
    }
    else {
      pii tmp = query(a, lc);
      ans = query(b, lc);
      cout << min(tmp.f, ans.f) << " " << max(tmp.s, ans.s) << "\n";
    }
  }

  return 0;
}
