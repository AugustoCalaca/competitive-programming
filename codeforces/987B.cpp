#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define c 0.0000000
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

  ll x, y;
  cin >> x >> y;
  double a = x * log(y);
  double b = y * log(x);
  if(x == y || a - b == c) cout << "=\n";
  else {
    if(a - b > c) cout << "<\n";
    else cout << ">\n";
  }

  return 0;
}
