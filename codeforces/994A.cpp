#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

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
  int n, m, v;
  map<int, int> mp;

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> v;
    mp.insert({ v, i });
  }

  map<int, int> mp2;
  for(int i = 0; i < m; i++) {
    cin >> v;
    auto it = mp.find(v);
    if(it != mp.end())
      mp2.insert({ it->second, it->first });
  }

  for(auto it = mp2.begin(); it != mp2.end(); it++)
    cout << it->second << " ";
  cout << "\n";

  return 0;
}
