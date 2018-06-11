#include <iostream>

using namespace std;

int main() {
  int n, v, a, b;
  cin >> n;
  a = b = 0;
  while(n--) {
    cin >> v;
    if(v == 100) a++;
    else b++;
  }

  if(((a & 1 || a == 0) && b & 1) || (a & 1 && (!(b & 1) || b == 0))) cout << "NO\n";
  else cout << "YES\n";

  return 0;
}