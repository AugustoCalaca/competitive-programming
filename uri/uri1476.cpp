#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define LOG 18
#define MAX 200020
#define W 100000
#define pil pair<int, int>
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Edge {
  int a, b, w;
};

bool comp(Edge& a, Edge& b) {
  return a.w > b.w;
}

int subset[MAX];

int find(int i) {
  if(subset[i] == - 1)
    return i;
  return find(subset[i]);
}

void merge(int u, int v) {
  int a = find(u);
  int b = find(v);
  subset[a] = b;
}

vector<Edge> graph;
vector<pil> tree[MAX];
int depth[MAX];
int st[MAX][LOG];
int mini[MAX][LOG];
int logN[MAX];

void dfs(vector<pil> tree[], int node, int parent, int d = 0, int w = -1) {
  depth[node] = d;
  st[node][0] = parent;

  if(w != -1) mini[node][0] = w;

  for(int i = 0; i < (int)tree[node].size(); i++) {
    pil neighbor = tree[node][i];
    if(depth[neighbor.f] == -1)
      dfs(tree, neighbor.f, node, d + 1, neighbor.s);
  }
}

int lca(int u, int v) {
  if(depth[u] < depth[v]) swap(u, v);

  for(int i = LOG - 1; i >= 0; i--)
    if(depth[u] - (1 << i) >= depth[v])
      u = st[u][i];

  if(u == v) return u;

  for(int i = LOG - 1; i >= 0; i--)
    if(st[u][i] != st[v][i] && st[u][i] != -1)
      u = st[u][i], v = st[v][i];

  return st[u][0];
}

int query(int u, int lc) {
  int min1 = W;
  for(int i = logN[depth[u]]; i >= 0; i--)
    if(depth[u] - (1 << i) >= depth[lc])
      min1 = min(min1, mini[u][i]), u = st[u][i];

  return min1;
}

void complog() {
  logN[1] = 1;
  for(int i = 2; i < MAX; i++)
    logN[i] = logN[i / 2] + 1;
}

int main() {
  FAST;

  complog();

  int n, m, s, a, b, w;
  while(cin >> n >> m >> s) {

    graph.clear();
    for(int i = 0; i <= n; i++) {
      subset[i] = depth[i] = -1;
      tree[i].clear();
    }

    for(int i = 0; i < m; i++) {
      cin >> a >> b >> w;
      graph.pb({ a, b, w });
    }

    // construct mst
    sort(graph.begin(), graph.end(), comp);

    for(int i = 0; i < m; i++) {
      int u = find(graph[i].a);
      int v = find(graph[i].b);
      if(u != v) {
        tree[graph[i].a].pb({ graph[i].b, graph[i].w });
        tree[graph[i].b].pb({ graph[i].a, graph[i].w });
        merge(u, v);
      }
    }
    //

    // precomp
    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= LOG; j++)
        st[i][j] = -1, mini[i][j] = W;

    dfs(tree, 1, -1);
    for(int j = 1; j <= LOG; j++)
      for(int i = 0; i <= n; i++)
        if(st[i][j - 1] != -1) {
          st[i][j] = st[st[i][j - 1]][j - 1];
          mini[i][j] = min(mini[i][j - 1], mini[st[i][j - 1]][j - 1]);
        }
    //

    while(s--) {
      cin >> a >> b;

      int lc = lca(a, b);
      if(a == lc)
        cout << query(b, lc) << "\n";
      else if(b == lc)
        cout << query(a, lc) << "\n";
      else
        cout << min(query(a, lc), query(b, lc)) << "\n";
    }
  }

  return 0;
}
