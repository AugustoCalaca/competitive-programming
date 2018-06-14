#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

#define f first
#define s second
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

  int n, v;
  map<int, int> m;
  multimap<int, int> ind;

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> v;
    m[v]++;
    ind.insert({ v, i });
  }

  if(m.size() < 3) { cout << 0 << "\n"; return 0; }

  int mn = 100000;
  for(auto it = m.begin(); it != m.end(); it++)
    if(it->s < mn) mn = it->s;
  cout << mn << "\n";

  while(mn--) {
    auto i = ind.find(1);
    cout << i->s << " ";
    ind.erase(i);
    auto j = ind.find(2);
    cout << j->s << " ";
    ind.erase(j);
    auto k = ind.find(3);
    cout << k->s << "\n";
    ind.erase(k);
  }

  return 0;
}
