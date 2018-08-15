#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>

#define f first
#define s second
#define pb push_back
#define pml pair<map<string, int>, ll>
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;
  int l, c, n;
  string str[110][110];
  vector<pml> v;
  map<string, int> ans;

  cin >> l >> c;
  for(int i = 0; i < l; i++) {
    map<string, int> m;
    for(int j = 0; j < c; j++) {
      cin >> str[i][j];
      m[str[i][j]]++;
    }
    cin >> n;
    if(m.size() == 1) ans.insert({ m.begin()->f, n / m.begin()->s });
    else v.pb({ m, n });
  }

  for(int j = 0; j < c; j++) {
    map<string, int> m;
    for(int i = 0; i < l; i++)
      m[str[i][j]]++;
    cin >> n;
    if(m.size() == 1) ans.insert({ m.begin()->f, n / m.begin()->s });
    else v.pb({ m, n });
  }

  while(v.size() > 0) {
    bool ok = false;
    for(auto it = v.begin(); it != v.end(); it++) {
      for(auto it2 = ans.begin(); it2 != ans.end(); it2++) {
        auto fnd = it->f.find(it2->f);
        if(fnd != it->f.end()) {
          it->s -= (fnd->s * it2->s);
          it->f.erase(fnd);
          if(it->f.size() == 1) {
            ans.insert({ it->f.begin()->f, it->s / it->f.begin()->s });
            v.erase(it);
            ok = true;
            break;
          }
        }
      }
      if(ok) break;
    }
  }

  for(auto i : ans) cout << i.f << " " << i.s << "\n";
  return 0;
}
