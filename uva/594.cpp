#include <iostream>
#include <algorithm>

// #define swap(a, b) a ^= b; b ^= a; a ^= b;
using namespace std;

// ac
int main() {
  int n;

  while(cin >> n) {
    int r = n;
    char * endian = (char *) &r;

    swap(endian[0], endian[3]);
    swap(endian[1], endian[2]);

    cout << n << " converts to " << r << endl;
  }

  return 0;
}
