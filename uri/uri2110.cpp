#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

#define M 5.33333333333
using namespace std;

// accepted
int h[110];

double toDegree(double rad) {
  return rad * 180 / M_PI;
}

int main() {
  int n, l, d, gardem;
  double tg, right, left;

  cout.precision(2);
  cout << fixed;

  while(cin >> n >> l >> d) {
    for(int i = 0; i < n; i++) {
      cin >> h[i];
      if(h[i] == 0) gardem = i;
    }

    right = left = 0.;
    for(int i = 0; i < gardem; i++) {
      tg = toDegree(atan(h[i] * 1. / ((gardem - i) * (l + d))));
      if(tg > right) right = tg;
    }
    for(int i = gardem + 1; i < n; i++) {
      tg = toDegree(atan(h[i] * 1. / ((i - gardem) * (l + d))));
      if(tg > left) left = tg;
    }

    double ans = (180. - right - left) * M;
    cout << ans << "\n";
  }

  return 0;
}
