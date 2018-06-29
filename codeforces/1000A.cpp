#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  fast();

  int n;
  string s;
  multimap<string, int> m;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s;
    m.insert({ s, 1 });
  }
  int ans = n;
  for(int i = 0; i < n; i++) {
    cin >> s;
    auto it = m.find(s);
    if(it != m.end()) {
      ans--;
      m.erase(it);
    }
  }

  cout << ans << "\n";
  return 0;
}
