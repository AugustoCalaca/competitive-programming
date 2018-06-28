#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pss pair<string, string>
#define pis pair<int, string>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

bool comp(pis& a, pis& b) {
  return a.f > b.f;
}

vector<pis> v [10010];
int main() {
  fast();

  int n, m, a, b;
  string str;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> str >> a >> b;
    v[a].pb({ b, str });
  }

  for(int i = 1; i <= m; i++) {
    sort(v[i].begin(), v[i].end(), comp);

    if(v[i].size() > 2 && v[i][1].f == v[i][2].f) cout << "?\n";
    else cout << v[i][0].s << " " << v[i][1].s << "\n";
  }

  return 0;
}
