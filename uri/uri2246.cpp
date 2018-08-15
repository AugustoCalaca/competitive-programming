#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <stack>

#define f first
#define s second
#define pb push
#define pii pair<int, int>
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int mos[210][210];
bool vis[210][210];
int ans = 40100;
int dist = 0;
stack<pii> sk;

void dfs(int root, int i, int j, int d = 0) {
  vis[i][j] = true;
  dist = max(d + 1, dist);

  if(mos[i][j + 1] == root && !vis[i][j + 1]) {
    sk.pb({ i, j });
    return dfs(root, i, j + 1, d + 1);
  }
  if(mos[i + 1][j] == root && !vis[i + 1][j]) {
    sk.pb({ i, j });
    return dfs(root, i + 1, j, d + 1);
  }
  if(mos[i][j - 1] == root && !vis[i][j - 1]) {
    sk.pb({ i, j });
    return dfs(root, i, j - 1, d + 1);
  }
  if(mos[i - 1][j] == root && !vis[i - 1][j]) {
    sk.pb({ i, j });
    return dfs(root, i - 1, j, d + 1);
  }

  if(sk.size() == 0) return ;
  pii p = sk.top();
  sk.pop();
  return dfs(root, p.f, p.s, d);
}

int main() {
  FAST;

  int h, l;
  cin >> h >> l;
  for(int i = 0; i <= h + 1; i++) {
    for(int j = 0; j <= l + 1; j++) {
      if(i == 0 || j == 0 || i == h + 1 || j == l + 1)
        mos[i][j] = -1, vis[i][j] = true;
      else
        cin >> mos[i][j];
    }
  }

  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= l; j++) {
      if(!vis[i][j]) {
        dfs(mos[i][j], i, j);
        ans = min(ans, dist);
        dist = 0;
      }
    }
  }

  cout << ans << "\n";
  return 0;
}
