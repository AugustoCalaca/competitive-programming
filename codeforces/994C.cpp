#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define f first
#define s second
#define pb push_back
#define EPSILON 1.0e-8
#define pii pair<int, int>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

vector<pii> m;
vector<pii> m2;

bool overlap(const pii pr) {
  if((m[0].f <= pr.f && m[1].f >= pr.f) && (m[0].s <= pr.s && m[2].s >= pr.s))
    return true;
  else
    return false;
}

int orientation(const pii p, const pii q, const pii r) {
  int o = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
  return o > 0 ? 1 : 2;
}

bool intercept(const pii p, const pii q, const pii r, const pii s) {
  int o1 = orientation(p, q, r);
  int o2 = orientation(p, q, s);
  int o3 = orientation(r, s, p);
  int o4 = orientation(r, s, q);

  if(o1 != o2 && o3 != o4) return true;
  else return false;
}

double distance(pii p, pii q) {
  return sqrt((q.f - p.f) * (q.f - p.f) + (q.s - p.s) * (q.s - p.s));
}

int main() {
  fast();

  int a, b;
  for(int i = 0; i < 4; i++) {
    cin >> a >> b;
    m.pb({ a, b });
  }

  sort(m.begin(), m.end());
  swap(m[1], m[2]);
  swap(m[2], m[3]);

  pii pr;
  // lozenge inside of square
  for(int i = 0; i < 4; i++) {
    cin >> a >> b;
    pr = {a, b};
    if(overlap(pr)) {
      cout << "YES\n";
      return 0;
    }
    m2.pb(pr);
  }

  sort(m2.begin(), m2.end());
  swap(m2[2], m2[3]);

  // intercept
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(intercept(m[i], m[(i + 1) % 4], m2[j], m2[(j + 1) % 4])) {
        cout << "YES\n";
        return 0;
      }
    }
  }

  // square inside of lozenge
  double sidelz = distance(m2[0], m2[1]);
  double arealz = sidelz * sidelz;
  for(int i = 0; i < 4; i++) {
    double sum = 0.0, sg, sh, p;
    for(int j = 0; j < 4; j++) {
      sg = distance(m2[j], m[i]);
      sh = distance(m2[(j + 1) % 4], m[i]);
      p = (sidelz + sg + sh) / 2;
      sum += sqrt(p * (p - sidelz) * (p - sg) * (p - sh));
    }

    if(fabs(arealz - sum) < EPSILON) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";
  return 0;
}
