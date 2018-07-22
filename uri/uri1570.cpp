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
  return 2 * sq(x) * sq(x) + sq(q) == sq(x) * b1;
}

bool checky(ll y) {
  return 2 * sq(y) * sq(y) + sq(p) == sq(y) * b2;
}

bool recheck() {
  return (ans1 + ans2) * ans2 == p && (ans1 - ans2) * ans1 == q && (sq(ans1) + sq(ans2) == p + q);
}

bool solvex() {
  b1 = 3 * q + p;
  long double delta = sq(b1) - 8 * sq(q);
  if(delta < 0) return false;
  delta = sqrt(delta);
  // cout << "deltax: " << delta << "\n";

  double z1 = (b1 - delta) / 4;
  double z2 = (b1 + delta) / 4;
  if(z1 < 0 || z1 < 0) return false;

  z1 = floor(sqrt(z1));
  z2 = floor(sqrt(z2));
  // cout << "z1: " << z1 << "\n";
  // cout << "z2: " << z2 << "\n";

  if(checkx(z1)) {
    ans1 = (ll)z1;
    return true;
  }
  else if(checkx(z1 + 1)) {
    ans1 = (ll)z1 + 1;
    return true;
  }
  if(checkx(z2)) {
    ans1 = (ll)z2;
    return true;
  }
  else if(checkx(z2 + 1)) {
    ans1 = (ll)z2 + 1;
    return true;
  }
  else return false;
}

bool solvey() {
  b2 = 3 * p + q;
  long double delta = sq(b2) - 8 * sq(p);
  if(delta < 0) return false;

  delta = sqrt(delta);

  double z1 = (b2 - delta) / 4;
  double z2 = (b2 + delta) / 4;
  // cout << "z1: " << z2 << "\n";
  if(z1 < 0 || z2 < 0) return false;

  z1 = floor(sqrt(z1));
  z2 = floor(sqrt(z2));

  if(checky(z1)) {
    ans2 = (ll)z1;
    return true;
  }
  else if(checky(z1 + 1)) {
    ans2 = (ll)z1 + 1;
    return true;
  }
  else if(checky(z2)) {
    ans2 = (ll)z2;
    return true;
  }
  else if(checky(z2 + 1)) {
    ans2 = (ll)z2 + 1;
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
      if(p * q < 0) {
        if(-ans1 >= -ans2) ans1 = -ans1, ans2 = -ans2;
        else ans2 = -ans2;
      }
      if(recheck())
        cout << ans1 << " " << ans2 << "\n";
      else
        cout << "Impossible.\n";
    }
    else
      cout << "Impossible.\n";
  }

  return 0;
}
