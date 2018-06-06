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

  int n, a, z = 0, c = 0;
  cin >> n;
  while(n--) {
    cin >> a;
    a ? z++ : c++;
  }

  while(z % 9 != 0) z--;
  if(c) {
    if(z) {
      while(z--) cout << "5";
      while(c--) cout << "0";
    } else cout << "0";
  } else cout << "-1";
  cout << "\n";
  return 0;
}
