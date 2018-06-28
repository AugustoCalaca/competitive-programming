#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

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

  vector<int> t, ht;
  int n, m, a;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a;
    ht.pb(a);
  }

  sort(ht.begin(), ht.end());
  int sum = 0;
  for(int i = 1; ; i++) {
    if(!binary_search(ht.begin(), ht.end(), i)) {
      sum += i;
      if(sum <= m) t.pb(i);
      else break;
    }
  }

  cout << t.size() << "\n";
  for(auto i : t) cout << i << " ";
  cout << "\n";
  return 0;
}
