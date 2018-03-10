#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// ac
int main() {
  int l, r, a, dif;
  cin >> l >> r >> a;

  dif = abs(l - r);
  if(dif <= a) {
    a -= dif;
    cout << (max(l, r) + a / 2) * 2 << endl;
  } else
    cout << (min(l, r) + a) * 2 << endl;

  return 0;
}
