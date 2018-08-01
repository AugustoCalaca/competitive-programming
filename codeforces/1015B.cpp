#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>

#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  FAST;

  string r, t;
  int n;

  cin >> n;
  cin >> r >> t;

  vector<int> ans;
  for(int i = 0; i < n; i++) {
    if(r[i] != t[i]) {
      int find = -1;
      for(int j = i + 1; j < n; j++)
        if(t[i] == r[j]) {
          find = j;
          break;
        }

      if(find == -1) {
        cout << "-1\n";
        return 0;
      }

      for(int j = find; j > i; j--) {
        swap(r[j], r[j - 1]);
        ans.pb(j);
      }
    }
  }

  cout << ans.size() << "\n";
  for(auto i : ans)
    cout << i << " ";
  cout << "\n";

  return 0;
}
