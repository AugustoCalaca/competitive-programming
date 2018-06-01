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
  int a, b, c;
  double one, two, three;
  cin >> a >> b >> c;

  one = sqrt(a * c / b);
  two = b * one / c;
  three = c / one;

  cout << 4 * (one + two + three) << "\n";
  return 0;
}
