#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define f first
#define s second
#define pii pair<int, int>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

vector<pii> v;

int main() {
  fast();

  int n, a, b;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.pb({ a, b });
  }

  sort(v.begin(), v.end());

  int ans = 0;
  for(int i = 0; i < n; i++) {
    int yu = 1000000000;
    int yl = -1000000000;
    for(int j = i + 1; j < n; j++) {
      if(v[j].s < v[i].s) {
        if(v[j].s > yl) {
          ans++;
          yl = v[j].s;
        }
      }
      else {
        if(v[j].s < yu) {
          ans++;
          yu = v[j].s;
        }
      }
    }
  }

  cout << ans << "\n";
  return 0;
}
