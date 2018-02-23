#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

// accepted
int main() {
  float a, d, teta;
  float side;

  cout.precision(4);
  cout << fixed;
  while(cin >> a >> d >> teta) {
    side = d / tan(teta * M_PI / 180);
    cout << a - side << "\n";
  }

  return 0;
}