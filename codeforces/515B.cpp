#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>

#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int gcd(int a, int b) {
  while(b) {
    a %= b;
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return a;
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int main() {
  fast();

  int n, m, b, g, v;
  bool c[110] = { false }, d[110] = { false };

  cin >> n >> m;
  cin >> b;
  for(int i = 0; i < b; i++) {
    cin >> v;
    c[v] = true;
  }
  cin >> g;
  for(int i = 0; i < g; i++) {
    cin >> v;
    d[v] = true;
  }

  int l = lcm(n, m);
  for(int i = 0; i < 2 * l; i++)
    c[i % n] = d[i % m] = c[i % n] || d[i % m];

  for(int i = 0; i < n; i++)
    if(!c[i]) { cout << "NO\n"; return 0; }
  for(int i = 0; i < m; i++)
    if(!d[i]) { cout << "NO\n"; return 0; }

  cout << "YES\n";
  return 0;
}
