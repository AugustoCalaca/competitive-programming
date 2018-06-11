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

  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  ull d = b * (n % m);
  ull c = a * (m - (n % m));
  if(d < c) cout << d << "\n";
  else cout << c << "\n";

  return 0;
}
