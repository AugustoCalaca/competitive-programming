#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define f first
#define s second
#define sq(x) (x) * (x)
#define pii pair<int, int>
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

double dist(pii& p, int a, int b, int c) {
  return fabs(a * p.f + b * p.s + c) / sqrt(sq(a) + sq(b));
}

double dist(pii& a, pii& b) {
  return sqrt(sq(a.f - b.f) + sq(a.s - b.s));
}

double min(double a, double b) {
  return a < b ? a : b;
}

int main() {
  FAST;

  cout.precision(2);

  int n, l, h, yi;
  double xf, yf;

  while(cin >> n >> l >> h) {
    vector<pii> v;
    double ans = 10000, mini;

    for(int i = 0; i < n; i++) {
      cin >> yi >> xf >> yf;

      v.pb({ xf, yf });

      if(i) {
        if(i & 1) {
          double d;
          if(xf > v[i - 1].f)
            d = dist(v[i], v[i - 1]);
          else {
            d = dist(v[i - 1], yi - yf, xf - l, l * yf - xf * yi);
          }
          mini = min(d, xf);
        }
        else {
          double d;
          if(xf < v[i - 1].f)
            d = dist(v[i], v[i - 1]);
          else {
            d = dist(v[i - 1], yi - yf, xf, -1 * xf * yi);
          }

          mini = min(d, l - xf);
        }
      }
      else
        mini = l - xf;
      // cout << " " << mini << "\n";
      ans = min(ans, mini);
    }

    // ans = min(ans, (n & 1) ? xf : l - xf);
    cout << fixed << ans << "\n";
  }
  return 0;
}
