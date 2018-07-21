#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

#define eps -(1e6)
#define sq(v) (v) * (v)
#define LIM (ll)floor(sqrt((1LL << 32) - 1))
#define f first
#define s second
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll ans1, ans2, p, q, b1, b2;

bool checkx(ll x) {
  return 2 * sq(x) * sq(x) + sq(q) - sq(x) * b1 == 0;
}

bool checky(ll y) {
  return 2 * sq(y) * sq(y) + sq(p) - sq(y) * b2 == 0;
}

bool solvex() {
  b1 = 3 * q + p;
  double delta = sq(b1) - 8 * sq(q);
  if(delta < 0.0) return false;

  delta = sqrt(delta);

  double z1 = (b1 - delta) / 4;
  double z2 = (b1 + delta) / 4;

  z1 = floor(sqrt(z1));
  z2 = floor(sqrt(z2));

  if(checkx(z1)) {
    ans1 = z1;
    return true;
  }
  else if(checkx(z1 + 1)) {
    ans1 = z1 + 1;
    return true;
  }
  else if(checkx(z2)) {
    ans1 = z2;
    return true;
  }
  else if(checkx(z2 + 1)) {
    ans1 = z2 + 1;
    return true;
  }
  else return false;
}

bool solvey() {
  b2 = 3 * p + q;
  double delta = sq(b2) - 8 * sq(p);
  if(delta < 0.0) return false;

  delta = sqrt(delta);

  double z1 = (b2 - delta) / 4;
  double z2 = (b2 + delta) / 4;

  z1 = floor(sqrt(z1));
  z2 = floor(sqrt(z2));

  if(checky(z1)) {
    ans2 = z1;
    return true;
  }
  else if(checky(z1 + 1)) {
    ans2 = z1 + 1;
    return true;
  }
  else if(checky(z2)) {
    ans2 = z2;
    return true;
  }
  else if(checky(z2 + 1)) {
    ans2 = z2 + 1;
    return true;
  }
  else return false;
}

int main() {
  FAST;

  ll n, k = 1;

  cin >> n;
  while(n--) {
    cin >> p >> q;
    cout << "Case " << k++ << ":\n";
    if(solvex() && solvey()) {
      if(p * q < 0) ans1 = -ans1, ans2 = -ans2;
      cout << ans1 << " " << ans2 << "\n";
    }
    else
      cout << "Impossible.\n";
  }

  return 0;
}
