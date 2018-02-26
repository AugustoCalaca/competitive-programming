#include <iostream>

using namespace std;
typedef unsigned long long int ull;

// accepted
ull table[10010];

ull perfectN(int k) {
  ull sum, ans = 19;
  table[1] = ans;

  for(int i = 2; i <= k; ) {
    ans += 9;
    ull aux = ans;
    sum = 0;
    while(aux > 0) {
      sum += aux % 10;
      aux /= 10;
    }

    if(sum == 10) table[i++] = ans;
  }

  return table[k];
}


int main() {
  int k;

  cin >> k;
  cout << perfectN(k) << "\n";

  return 0;
}
