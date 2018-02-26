#include <iostream>
#include <cmath>

#define sq(a) ((a) * (a))
using namespace std;

// accepted
int main() {
  double r, x1, y1, x2, y2, xans, yans, rans;

  cout.precision(10);
  cout.setf(ios::fixed);

  cin >> r >> x1 >> y1 >> x2 >> y2;

  double d = sq(x2 - x1) + sq(y2 - y1);
  if(d >= r * r) {
    xans = x1;
    yans = y1;
    rans = r;
  } else if(x1 == x2 && y1 == y2) {
    r /= 2;
    xans = x1 + r;
    yans = y1;
    rans = r;
  } else {
    d = sqrt(d);
    double cos = (x1 - x2) / d;
    double sen = (y1 - y2) / d;

    rans = (d + r) / 2;
    xans = x2 + cos * rans;
    yans = y2 + sen * rans;
  }

  cout << xans << " " << yans << " " << rans << "\n";


  return 0;
}
