#include <iostream>
#include <cmath>

using namespace std;

// accepted
bool sides(int a, int b, int c) {
  return (abs(b - c) < a && b + c > a) &&
         (abs(a - b) < c && a + b > c) &&
         (abs(a - c) < b && a + c > b);
}

bool isTrian(int a, int b, int c, int d) {
  if(sides(a, b, c)) return true;
  if(sides(a, b, d)) return true;
  if(sides(a, c, d)) return true;
  if(sides(b, c, d)) return true;

  return false;
}

int main() {
  int a, b , c , d;

  cin >> a >> b >> c >> d;

  if(isTrian(a, b, c, d)) cout << "S\n";
  else cout << "N\n";

  return 0;
}
