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

  int k, b, n, t;
  cin >> k >> b >> n >> t;
  ll act = k + b;
  while(act <= t) {
    act = act * k + b;
    n--;
    if(n < 0) {
      cout << "0\n";
      return 0;
    }
  }

  cout << n << "\n";
  return 0;
}
