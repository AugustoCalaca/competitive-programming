#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int depth[110];

void dfs(vector<int> graph[], int node) {
  depth[node] = 1;
  for(int i = 0; i < (int) graph[node].size(); i++)
    if(!depth[graph[node][i]])
      dfs(graph, graph[node][i]);
}

int main() {
  FAST;

  int e, l, a, b, k = 0;
  while(cin >> e >> l) {
    vector<int> graph[110];
    if(e == 0 && l == 0) break;

    for(int i = 0; i < e; )
      depth[i++] = 0;

    while(l--) {
      cin >> a >> b;
      graph[a - 1].pb(b - 1);
      graph[b - 1].pb(a - 1);
    }

    dfs(graph, 0);

    bool flag = true;
    for(int i = 0; i < e; i++)
      if(!depth[i]) {
        flag = false;
        break;
      }

    cout << "Teste " << ++k << "\n";
    if(flag)
      cout << "normal";
    else
      cout << "falha";
    cout << "\n\n";
  }

  return 0;
}
