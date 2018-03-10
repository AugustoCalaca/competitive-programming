#include <iostream>

#define endl "\n"
using namespace std;
typedef unsigned long long ull;

// ac
int main() {
  ull a, b;

  cin >> a >> b;
  while(true) {
    if((a == 0 || b == 0) || a == b) break;
    else if(a >= 2 * b) a = a % (2 * b);
    else if(b >= 2 * a) b = b % (2 * a);
    else break;
  }

  cout << a << " " << b << endl;

  return 0;
}
