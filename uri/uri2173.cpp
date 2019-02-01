#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 10010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Edge {
  int a, b, c;
};

int subset[M];
vector<Edge> graph;

int find(int i) {
  if(subset[i] == -1) return i;
  return find(subset[i]);
}

bool isSameSet(int i, int j) {
  return find(i) == find(j);
}

void merge(int i, int j) {
  int u = find(i);
  int v = find(j);
  subset[u] = v;
}

int kruskal(int n) {
  for(int i = 0; i <= n; i++)
    subset[i] = -1;

  int cost = 0;
  for(Edge edg : graph) {
    if(!isSameSet(edg.a, edg.b)) {
      cost += edg.c;
      merge(edg.a, edg.b);
    }
  }

  return cost;
}

bool comp(Edge& a, Edge& b) {
  return a.c < b .c;
}

int main() {
  FAST;

  int m, n, a, b, c;
  while(cin >> n >> m) {
    if(m == 0 && n == 0) break;

    graph.clear();
    while(m--) {
      cin >> a >> b >> c;
      graph.pb({ a, b, c });
    }

    sort(graph.begin(), graph.end(), comp);
    int temp = kruskal(n);
    reverse(graph.begin(), graph.end());
    cout << kruskal(n) - temp << "\n";
  }

  return 0;
}
