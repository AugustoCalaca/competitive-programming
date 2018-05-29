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

int v[3 * (int)1e6 + 20];
int main() {
  fast();

  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> v[i];
    sort(v, v + n);
    for(int i = 0; i < n; i++) {
      cout << v[i];
      if(i + 1 < n ) cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
