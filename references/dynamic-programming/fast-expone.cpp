#include <iostream>

int fexp(int b, int e, int m) {
  int ans = 1;

  for(; e > 0; e >>= 1) {
    if(e & 1) ans = (ans * b) % m;
    b = (b * b) % m;
  }

  return ans;
}
