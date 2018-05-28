#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fast() {
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

map<ll, ll> mp;

int main() {
  fast();

  int n, m;
  ll a, b, sum = 0, sum2 = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    mp.insert({ a, b });
    sum += b;
  }

  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    auto it = mp.find(a);
    if(it != mp.end()) {
      if(it->s <= b) sum -= it->s;
      else sum2 -= b;
    }
    sum2 += b;
  }

  cout << sum + sum2 << "\n";
  return 0;
}
