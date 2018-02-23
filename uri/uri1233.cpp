#include <iostream>
#include <cmath>

using namespace std;

// accpeted
typedef long long int li;

li totiente(li n) {
  li ans = n;

  if(n == 1) return 0;
  for(li p = 2; p*p <= n; p++) {
    if(n % p == 0) {
      for(; n % p == 0; n /= p) {}
      ans -= (ans / p);
    }
  }

  if(n > 1)
    ans -= (ans / n);

  return ans;
}

int main() {
  li n;

  while(cin >> n)
    cout << (totiente(n) >> 1) << "\n";

  return 0;
}
