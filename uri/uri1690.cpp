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
  int t, n, v[10010];
  bool f = true;
  for(cin >> t; t--; ) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> v[i];
      if(v[i] == 1) f = false;
    }

    if(f) cout << "1\n";
    else {
      ll sum = 1;
      sort(v, v + n);
      for(int i = 0; i < n; i++) {
        if(v[i] <= sum) sum += v[i];
        else break;
      }
      cout << sum << "\n";
    }
  }
  return 0;
}
