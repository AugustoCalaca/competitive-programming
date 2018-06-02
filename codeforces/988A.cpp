#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
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

// ac
int main() {
  fast();
  int n, k, v;
  map<int, int> m;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> v;
    m.insert({ v, i + 1 });
  }

  if(m.size() < k) {
    cout << "NO\n";
    return 0;
  }

  vector<int> vec;
  for(auto it = m.begin(); it != m.end(); it++) {
    vec.pb(it->second);
  }
  cout << "YES\n";
  sort(vec.begin(), vec.end());
  for(int i = 0; i < k; i++) cout << vec[i] << " ";
  cout << "\n";

  return 0;
}
