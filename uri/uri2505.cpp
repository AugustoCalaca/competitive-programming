#include <iostream>

#define MOD 1000000
#define TEN 10
using namespace std;
typedef unsigned long long int ull;


// accepted
ull fastExp(ull k) {
  ull base = k;
  ull ans = 1;

  for(; k > 0; k >>= 1) {
    if(k & 1) ans = (ans * base) % MOD;
    base = (base * base) % MOD;
  }

  return ans;
}

bool isAutopot(ull n, ull modn) {
  ull vn[8];
  ull vmodn[8];
  ull i;

  for(i = 0; n; i++, n /= TEN)
    vn[i] = n % TEN;

  for(ull j = 0; j < i; j++, modn /= TEN)
    vmodn[j] = modn % TEN;

  for(ull j = 0; j < i; j++)
    if(vn[j] != vmodn[j]) return false;

  return true;
}

int main() {
  ull n;
  ull modn;

  for(; cin >> n;) {
    modn = fastExp(n);
    if(isAutopot(n, modn))
      cout << "SIM\n";
    else
      cout << "NAO\n";
  }

  return 0;
}
