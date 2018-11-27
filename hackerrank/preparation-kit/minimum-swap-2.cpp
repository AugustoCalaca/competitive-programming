#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define M 100010
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

vector<pii> vec;

int main() {
  FAST;

  int n, v;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> v;
    vec.pb({ v, i });
  }

  sort(vec.begin(), vec.end());

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(vec[i].s == i) continue;
    else {
      swap(vec[i].f, vec[vec[i].s].f);
      swap(vec[i].s, vec[vec[i].s].s);
    }

    if(i != vec[i].s) i--;
    ans++;
  }

  cout << ans << "\n";
  return 0;
}
