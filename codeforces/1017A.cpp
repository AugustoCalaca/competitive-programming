#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define pii pair<int, int>
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<pii> v;

bool comp(pii& a, pii& b) {
  if(a.f == b.f)
    return a.s < b.s;
  return a.f > b.f;
}

int main() {
  FAST;

  int n, sum, m;
  cin >> n;
  for(int i = 0; i < n; i++) {
    sum = 0;
    for(int j = 0; j < 4; j++) {
      cin >> m;
      sum += m;
    }
    v.pb({ sum, i + 1 });
  }

  sort(v.begin(), v.end(), comp);

  int j = 1;
  for(auto it = v.begin(); it != v.end(); it++, j++) {
    if(it->s == 1) {
      cout << j << "\n";
      break;
    }
  }
  return 0;
}
