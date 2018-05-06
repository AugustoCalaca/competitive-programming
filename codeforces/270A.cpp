#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cin.tie(NULL);
  cout.sync_with_stdio(false);
}

int main() {
  fast();

  int n, a;
  for(cin >> n; n--; ) {
    cin >> a;
    if(360 % (180 - a) == 0)
      cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
