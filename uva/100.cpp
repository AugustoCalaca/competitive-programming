#include <iostream>
#include <algorithm>

using namespace std;

// ac
int lenCycle(int i) {
  int l = 1;
  for(; i != 1; l++)
    i = (i & 1) ? (3 * i + 1) : (i >> 1);

  return l;
}

int main() {
  int a, a0, b, b0, m;

  while(cin >> a >> b) {
    a0 = a; b0 = b;
    if(a > b) {
      a ^= b;
      b ^= a;
      a ^= b;
    }

    m = 0;
    for(int i = a; i <= b; i++) {
      int l = lenCycle(i);
      if(l > m) m = l;
    }

    cout << a0 << " " << b0 << " " << m << endl;
  }

  return 0;
}
