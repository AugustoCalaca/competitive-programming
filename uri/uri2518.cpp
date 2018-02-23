#include <iostream>
#include <cmath>

#define sq(a) ((a) * (a))
using namespace std;

// accepted
int main() {
  int n, h, c, l;

  cout.precision(4);
  cout.setf(ios::fixed);

  while(cin >> n >> h >> c >> l)
    cout << l * n * sqrt(sq(h) + sq(c)) * 1e-4 << "\n";

  return 0;
}
